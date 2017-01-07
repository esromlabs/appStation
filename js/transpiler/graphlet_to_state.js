// graphlet to state machine
(function($, gq) {
  var given_graph;
  var make_transitions = function(edges) {
    var trans = {};
    $.each(edges, function(i, o) {
      var guard = true;
      if (!trans[o[3]]) {
        trans[o[3]] = {};
      }
      if (o[4]) { guard = "function () { return (" + o[4] + ");}"; }
      trans[o[3]][get_to_node_name(o)] = guard; //get_to_node(o));
    });
    return trans;
  };
  var get_from_node_name = function(edge) {
    return gq.using(given_graph).find({"element":"node", "id":edge[0]}).nodes()[0].name;
  };
  var get_to_node_name = function(edge) {
    return gq.using(given_graph).find({"element":"node", "id":edge[1]}).nodes()[0].name;
  };
  var isaState = function(name) {
    var a = (gq.using(given_graph).find({"element":"node", "name":name}).nodes()[0]);
    var b = (gq.using(given_graph).find({"element":"node", "id":name}).nodes()[0]);
    return a || b;
  };
  graphlet2statemachine = {
    "process": function (g) {
      var states ={};
      var trans = {};
      var views = [];
      var current_state_name;
      given_graph = g;
      $.each(g.nodes, function(i, o) {
        states[o.name] = o.properties || {};
        if (o.onEnterState) {
           states[o.name].onEnterState = "function () {" + o.onEnterState + "}";
        }
        if (o.start || o.start_state || o.name === "Start" || o.name === "start" ) {
          current_state_name = o.name;
        }
      });
      $.each(g.nodes, function(i, o) {
        var transition_edges = gq.using(g).find({"element":"edge", "from":o.id}).edges();
        trans[o.name] = make_transitions(transition_edges);
      });
      $.each(g.views, function(i, o) {
        var this_view = {name: o.name, nodes:{}};
        $.each(o.nodes, function(node_id, v) {
          var node = isaState(node_id);
          if (node) {
            this_view.nodes[node.name] = v;
          }
        });
        views.push(this_view);
      });
      // todo: update views so that we use state names and not Ids
      return {"states":states, "trans":trans, "current_state_name":current_state_name,
        "views": views, "fsm":{"version":"0.3.0"}};
    },
    "reverse": function (sm) {
      var out_graph = {nodes:[], edges:[]};
      $.each(sm, function(name, state) {
        out_graph.nodes.push({"name":name});
        $.each(state.trans, function(key, transition) {
          out_graph.edges.push({"from":name, "to":transition, "name":key });
        });
      });
      return out_graph;
    }
  };
  graphlet2c_code = {
    "process": function (g) {
      // string processing starting points... (could be made into templates)
      var preamble = "// state machine vars and methods\n"
      var states_enum   = "typedef enum { ";
      var states_enum2  = " } State;\n";
      var signal_enum   = "typedef enum { ";
      var signal_enum2  = " } Signal;\n";
      var declare_state = "State state;\n";
      var preinit_state = "// setup pre-init state\n";
      preinit_state += 'void setup_pre_init_state() { state = (State)-1; }\n';
      var onTick_func_1 = "// onTick processor function\n";
      onTick_func_1 += 'void onTick_processor() {\n';
      onTick_func_1 += '  switch (state) {\n';
      var onTick_func_2 = "  }\n}\n\n";
      var onEnterState_func_1 = "  // onEnterState processor function\n";
      onEnterState_func_1 += 'void onEnterState_processor() {\n';
      onEnterState_func_1 += '  switch (state) {\n';
      var onEnterState_func_2 = "  }\n}\n\n";
      var state_trans_1 = "  // process the state transition\n";
      state_trans_1 += 'int state_trans_processor(int state, int sig, int sig_data) {\n';
      state_trans_1 += '  switch (state) {\n';
      var state_trans_2 = "  }\n}\n\n";

      var trans_names = [];
      var state_names = [];
      $.each(g.edges, function(i, e) {
        var edge_name = e[3];
        if (trans_names.indexOf(edge_name) === -1) {
          trans_names.push(edge_name);
        }
      });
      signal_enum += trans_names.join(', ') + signal_enum2;
      $.each(g.nodes, function(i, o) {
        state_names.push(o.name);
        var prop = o.properties || {};
        if (prop.onTick) {
           onTick_func_1 += "    case " + o.name + " :\n      " +
              prop.onTick + "\n    break;\n";
        }
        if (prop.onEnterState) {
           onEnterState_func_1 += "    case " + o.name + " :\n      " +
              prop.onEnterState + "\n    break;\n";
        }
      });
      states_enum += state_names.join(', ') + states_enum2;
      onTick_func_1 += onTick_func_2;
      onEnterState_func_1 += onEnterState_func_2;

      $.each(g.nodes, function(ni, o) {
        var unique_out_signal_names = [];
        var consolidated_signals = [];
        var trans = gq.using(g).find({"element":"edge", "from":o.id}).edges();
        state_trans_1 += "      case " + o.name + " :\n";
        state_trans_1 += "        switch (sig) {\n";

        $.each(trans, function(ti, t) {
          var trans_sig = t[3];
          if (unique_out_signal_names.indexOf(trans_sig) === -1) {
            unique_out_signal_names.push(trans_sig);
          }
        });

        $.each(trans, function(ti, t) {
          var trans_sig = t[3];
          var consol_index = unique_out_signal_names.indexOf(trans_sig);
          var to_state = get_to_node_name(t);
          if (!consolidated_signals[consol_index]) {
            consolidated_signals[consol_index] = {"sig": trans_sig,"out_edges": []};
          }
          consolidated_signals[consol_index].out_edges.push({"guard":t[4], "to_state":to_state});
        });
        $.each(consolidated_signals, function(ti, t) {
          var trans_signal = t.sig;
          var default_trans;
          var elsetro = '';
          state_trans_1 += "          case " + trans_signal + " :\n";
          $.each(t.out_edges, function(ei, e) {
            if (!e.guard) {
              default_trans = e;
            }
            else {
              state_trans_1 += "                  // evaluate guard expression\n";
              state_trans_1 += elsetro + '            if(' + e.guard + ') {\n';
              state_trans_1 += "                state = " + e.to_state + ";\n";
              state_trans_1 += "              }\n";
              elsetro =        '              else ';
            }

          });
          if (default_trans) {
            if (elsetro) {
              state_trans_1 += elsetro + '{\n';
              state_trans_1 += "                state = " + default_trans.to_state + ";\n";
              state_trans_1 += '            }\n';
            }
            else {
              state_trans_1 += "            state = " + default_trans.to_state + ";\n";

            }
          }
          state_trans_1 += "          break;\n";
        });
        state_trans_1 += "        }\n";
        state_trans_1 += "      break;\n";

      });
      state_trans_1 += state_trans_2;
      // todo: update views so that we use state names and not Ids
      return preamble + states_enum + signal_enum + declare_state +
        preinit_state + onTick_func_1 + onEnterState_func_1 + state_trans_1;
    },
    "reverse": function (sm) {
      var out_graph = {nodes:[], edges:[]};
      $.each(sm, function(name, state) {
        out_graph.nodes.push({"name":name});
        $.each(state.trans, function(key, transition) {
          out_graph.edges.push({"from":name, "to":transition, "name":key });
        });
      });
      return out_graph;
    }
  };

})($, gq);


/* example output for use in:
 *    https://github.com/CloudEngineWorks/angular-simple-statemachine

{
 "states": {
     "start": {},
     "clearing_mind": { "clearing_mind_icon": true },
     "blank_slate": {},
     "thinking": { "thinking": true, "thinking_icon": true },
     "thinking_error": { "bad_idea": true, "need_a_new_idea":true },
     "clearing_mind_error": { "clearing_mind": true, "display_error": true, "enterState": "function () { $timeout(function () { get_clear_mind(); }, 1000); return true; }" }
 },
 "trans": {
     "start": { "init": "clearing_mind" },
     "clearing_mind": { "success": "blank_slate", "fail": "clearing_mind_error" },
     "blank_slate": { "idea": "thinking" },
     "thinking": { "success": "blank_slate", "fail": "thinking_error" },
     "thinking_error": { "idea": "thinking" },
     "clearing_mind_error": { "init": "clearing_mind" }
 },
 "current_state_name": "start",
 "current_state": {}
}
*/
