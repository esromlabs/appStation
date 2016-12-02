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
    return (gq.using(given_graph).find({"element":"node", "name":name}).nodes()[0]);
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
        $.each(o.nodes, function(node_name, v) {
          if (isaState(node_name)) {
            this_view.nodes[node_name] = v;
          }
        });
        views.push(this_view);
      });
      // todo: update views so that we use state names and not Ids
      return {"states":states, "trans":trans, "current_state_name":current_state_name,
        "views": views};
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
