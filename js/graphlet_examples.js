var graph_examples = {
  "changedit 1":{"graph":{"name":"changedit 1","template":""},"nodes":[{"id":"n0","name":"Start"},{"id":"n1","name":"clean"},{"name":"editing","id":"n2"},{"name":"changed","id":"n3"}],"edges":[["n0","n1","","init","",0],["n1","n2","","edit","",1],["n2","n1","","revert","",2],["n2","n3","","accept","",3],["n2","n1","","accept","this.original_item == this.new_item",4]],"views":[{"name":"primary","nodes":{"n3":{"position":{"x":328,"y":163},"width":80},"n2":{"position":{"x":229,"y":71},"width":60},"n1":{"position":{"x":116,"y":163},"width":60},"n0":{"position":{"x":-13,"y":163},"width":60}},"edges":{}},{"name":"kitty corner","nodes":{"n0":{"position":{"x":9,"y":59}},"n1":{"position":{"x":103,"y":60}},"n2":{"position":{"x":207,"y":-34}},"n3":{"position":{"x":295,"y":57}}},"edges":{}}]},
  "changedit 2":{"graph":{"name":"changedit 2","template":""},"nodes":[{"name":"to be removed","id":"n4"},{"name":"changed","id":"n3"},{"name":"editing","id":"n2"},{"id":"n1","name":"clean"},{"id":"n0","name":"Start"}],"edges":[["n0","n1","","init","",0],["n1","n2","","edit","",1],["n2","n1","","revert","",2],["n2","n3","","accept","",3],["n2","n1","","accept","this.original_item == this.new_item",4],["n1","n4","","remove","",5],["n4","n1","","restore","",6]],"views":[{"name":"primary","nodes":{"n4":{"position":{"x":250,"y":241},"width":130},"n3":{"position":{"x":328,"y":163},"width":80},"n2":{"position":{"x":212,"y":90},"width":60},"n1":{"position":{"x":116,"y":163},"width":60},"n0":{"position":{"x":-13,"y":162},"width":60}},"edges":{}},{"name":"kitty corner","nodes":{"P1 leads":{"position":{"x":112,"y":105},"width":90},"All":{"position":{"x":300,"y":150}},"P2 leads":{"position":{"x":502,"y":106},"width":90},"Start":{"position":{"x":300,"y":70},"width":60},"Advantage P1":{"position":{"x":154,"y":250},"width":110},"Advantage P2":{"position":{"x":450,"y":250},"width":110},"Deuce":{"position":{"x":300,"y":250},"width":60},"Game P2":{"position":{"x":550,"y":300},"width":90},"Game P1":{"position":{"x":50,"y":300},"width":90}},"edges":{}}]},
  "changedit 3":{"graph":{"name":"changedit 3","template":""},"nodes":[{"id":"n0","name":"Start"},{"id":"n1","name":"clean"},{"name":"editing","id":"n2"},{"name":"changed","id":"n3"},{"name":"to-be-removed","id":"n4"}],"edges":[["n0","n1","","init","",0],["n1","n2","","edit","",1],["n2","n1","","revert","",2],["n2","n3","","accept","",3],["n2","n1","","accept","this.original_item == this.new_item",4],["n1","n4","","remove","",5],["n4","n1","","revert","",6],["n3","n1","","revert","",7]],"views":[{"name":"primary","nodes":{"n0":{"position":{"x":-13,"y":163},"width":60},"n1":{"position":{"x":116,"y":163},"width":60},"n2":{"position":{"x":238,"y":71},"width":60},"n3":{"position":{"x":335,"y":163},"width":80},"n4":{"position":{"x":256,"y":249},"width":130}},"edges":{}},{"name":"kitty corner","nodes":{"P1 leads":{"position":{"x":112,"y":105},"width":90},"All":{"position":{"x":300,"y":150}},"P2 leads":{"position":{"x":502,"y":106},"width":90},"Start":{"position":{"x":300,"y":70},"width":60},"Advantage P1":{"position":{"x":154,"y":250},"width":110},"Advantage P2":{"position":{"x":450,"y":250},"width":110},"Deuce":{"position":{"x":300,"y":250},"width":60},"Game P2":{"position":{"x":550,"y":300},"width":90},"Game P1":{"position":{"x":50,"y":300},"width":90}},"edges":{}}]},
  "verbose tennis 1":{"graph":{"name":"verbose tennis 1","template":""},"nodes":[{"properties":{},"name":"30 All","id":"n7"},{"properties":{},"name":"30 15","id":"n6"},{"properties":{},"name":"15 30","id":"n5"},{"properties":{},"name":"Love 30","id":"n4"},{"properties":{},"name":"30 Love","id":"n3"},{"properties":{},"name":"15 All","id":"n2"},{"properties":{},"name":"15 Love","id":"n1"},{"properties":{},"name":"Love 15","id":"n0"},{"properties":{},"name":"Start","id":"Start"}],"edges":[["Start","n1","set","1","",0],["Start","n0","get","2","",1],["n1","n2","get","2","",2],["n0","n2","set","1","",3],["n1","n3","set","1","",4],["n0","n4","get","2","",5]],"views":[{"name":"primary","nodes":{"n7":{"position":{"x":326,"y":156},"width":80},"n6":{"position":{"x":239,"y":94},"width":80},"n5":{"position":{"x":236,"y":219},"width":80},"n4":{"position":{"x":170,"y":280},"width":80},"n3":{"position":{"x":168,"y":28},"width":80},"n2":{"position":{"x":151,"y":155},"width":80},"n1":{"position":{"x":76,"y":88},"width":80},"n0":{"position":{"x":76,"y":220},"width":80},"Start":{"position":{"x":10,"y":154},"width":60}},"edges":{}},{"name":"top down","nodes":{"P1 leads":{"position":{"x":112,"y":105},"width":90},"All":{"position":{"x":300,"y":150}},"P2 leads":{"position":{"x":502,"y":106},"width":90},"Start":{"position":{"x":300,"y":70},"width":60},"Advantage P1":{"position":{"x":154,"y":250},"width":110},"Advantage P2":{"position":{"x":450,"y":250},"width":110},"Deuce":{"position":{"x":300,"y":250},"width":60},"Game P2":{"position":{"x":550,"y":300},"width":90},"Game P1":{"position":{"x":50,"y":300},"width":90}},"edges":{}}]},
  "verbose tennis 2":{"graph":{"name":"verbose tennis 2","template":""},"nodes":[{"properties":{},"name":"Start","id":"Start"},{"properties":{},"name":"Love 15","id":"n0"},{"properties":{},"name":"15 Love","id":"n1"},{"properties":{},"name":"15 All","id":"n2"},{"properties":{},"name":"30 Love","id":"n3"},{"properties":{},"name":"Love 30","id":"n4"},{"properties":{},"name":"15 30","id":"n5"},{"properties":{},"name":"30 15","id":"n6"},{"properties":{},"name":"30 All","id":"n7"}],"edges":[["Start","n1","set","1","",0],["Start","n0","get","2","",1],["n1","n2","get","2","",2],["n0","n2","set","1","",3],["n1","n3","set","1","",4],["n0","n4","get","2","",5],["n2","n6","set","1","",6],["n2","n5","get","2","",7],["n3","n6","get","2","",8],["n6","n7","get","2","",9],["n5","n7","set","1","",10],["n4","n5","set","1","",11]],"views":[{"name":"primary","nodes":{"Start":{"position":{"x":10,"y":154},"width":60},"n0":{"position":{"x":79,"y":216},"width":80},"n1":{"position":{"x":86,"y":90},"width":80},"n2":{"position":{"x":162,"y":154},"width":80},"n3":{"position":{"x":163,"y":27},"width":80},"n4":{"position":{"x":162,"y":283},"width":80},"n5":{"position":{"x":241,"y":222},"width":80},"n6":{"position":{"x":239,"y":94},"width":80},"n7":{"position":{"x":326,"y":156},"width":80}},"edges":{}},{"name":"top down","nodes":{"P1 leads":{"position":{"x":112,"y":105},"width":90},"All":{"position":{"x":300,"y":150}},"P2 leads":{"position":{"x":502,"y":106},"width":90},"Start":{"position":{"x":300,"y":70},"width":60},"Advantage P1":{"position":{"x":154,"y":250},"width":110},"Advantage P2":{"position":{"x":450,"y":250},"width":110},"Deuce":{"position":{"x":300,"y":250},"width":60},"Game P2":{"position":{"x":550,"y":300},"width":90},"Game P1":{"position":{"x":50,"y":300},"width":90}},"edges":{}}]},
  "verbose tennis 3":{"graph":{"name":"verbose tennis 3","template":""},"nodes":[{"properties":{},"name":"Love 40","id":"n13"},{"properties":{},"name":"15 40","id":"n12"},{"properties":{},"name":"40 30","id":"n11"},{"properties":{},"name":"30 40","id":"n10"},{"properties":{},"name":"40 Love","id":"n9"},{"properties":{},"name":"40 15","id":"n8"},{"properties":{},"name":"Start","id":"Start"},{"properties":{},"name":"Love 15","id":"n0"},{"properties":{},"name":"15 Love","id":"n1"},{"properties":{},"name":"15 All","id":"n2"},{"properties":{},"name":"30 Love","id":"n3"},{"properties":{},"name":"Love 30","id":"n4"},{"properties":{},"name":"15 30","id":"n5"},{"properties":{},"name":"30 15","id":"n6"},{"properties":{},"name":"30 All","id":"n7"}],"edges":[["Start","n1","set","1","",0],["Start","n0","get","2","",1],["n1","n2","get","2","",2],["n0","n2","set","1","",3],["n1","n3","set","1","",4],["n0","n4","get","2","",5],["n2","n6","set","1","",6],["n2","n5","get","2","",7],["n3","n6","get","2","",8],["n6","n7","get","2","",9],["n5","n7","set","1","",10],["n4","n5","set","1","",11],["n3","n9","set","1","",12],["n6","n8","set","1","",13],["n4","n13","get","2","",14],["n5","n12","get","2","",15],["n7","n10","get","2","",16],["n7","n11","set","1","",17]],"views":[{"name":"primary","nodes":{"n7":{"position":{"x":326,"y":156},"width":80},"n6":{"position":{"x":239,"y":94},"width":80},"n5":{"position":{"x":241,"y":222},"width":80},"n4":{"position":{"x":162,"y":283},"width":80},"n3":{"position":{"x":163,"y":27},"width":80},"n2":{"position":{"x":162,"y":154},"width":80},"n1":{"position":{"x":86,"y":90},"width":80},"n0":{"position":{"x":79,"y":216},"width":80},"Start":{"position":{"x":10,"y":154},"width":60},"n8":{"position":{"x":331,"y":26},"width":80},"n9":{"position":{"x":241,"y":-31},"width":80},"n10":{"position":{"x":405,"y":224},"width":80},"n11":{"position":{"x":410,"y":94},"width":80},"n12":{"position":{"x":324,"y":284},"width":80},"n13":{"position":{"x":243,"y":349},"width":80}},"edges":{}},{"name":"top down","nodes":{"n13":{"position":{"x":74,"y":230}},"n12":{"position":{"x":149,"y":295}},"n11":{"position":{"x":389,"y":358}},"n10":{"position":{"x":225,"y":357}},"n9":{"position":{"x":546,"y":239}},"n8":{"position":{"x":476,"y":295}},"Start":{"position":{"x":304,"y":35},"width":60},"n0":{"position":{"x":217,"y":109}},"n1":{"position":{"x":383,"y":105}},"n2":{"position":{"x":305,"y":164}},"n3":{"position":{"x":462,"y":165}},"n4":{"position":{"x":148,"y":172}},"n5":{"position":{"x":227,"y":234}},"n6":{"position":{"x":386,"y":229}},"n7":{"position":{"x":308,"y":293}}},"edges":{}}]},
  "verbose tennis 4":{"graph":{"name":"verbose tennis 4","template":""},"nodes":[{"properties":{},"name":"Advantage P2","id":"n16"},{"properties":{},"name":"Advantage P1","id":"n15"},{"properties":{},"name":"Deuce","id":"n14"},{"properties":{},"name":"30 All","id":"n7"},{"properties":{},"name":"30 15","id":"n6"},{"properties":{},"name":"15 30","id":"n5"},{"properties":{},"name":"Love 30","id":"n4"},{"properties":{},"name":"30 Love","id":"n3"},{"properties":{},"name":"15 All","id":"n2"},{"properties":{},"name":"15 Love","id":"n1"},{"properties":{},"name":"Love 15","id":"n0"},{"properties":{},"name":"Start","id":"Start"},{"properties":{},"name":"40 15","id":"n8"},{"properties":{},"name":"40 Love","id":"n9"},{"properties":{},"name":"30 40","id":"n10"},{"properties":{},"name":"40 30","id":"n11"},{"properties":{},"name":"15 40","id":"n12"},{"properties":{},"name":"Love 40","id":"n13"},{"properties":{},"name":"Game P1","id":"n17"},{"properties":{},"name":"Game P2","id":"n18"}],"edges":[["Start","n1","set","1","",0],["Start","n0","get","2","",1],["n1","n2","get","2","",2],["n0","n2","set","1","",3],["n1","n3","set","1","",4],["n0","n4","get","2","",5],["n2","n6","set","1","",6],["n2","n5","get","2","",7],["n3","n6","get","2","",8],["n6","n7","get","2","",9],["n5","n7","set","1","",10],["n4","n5","set","1","",11],["n3","n9","set","1","",12],["n6","n8","set","1","",13],["n4","n13","get","2","",14],["n5","n12","get","2","",15],["n7","n10","get","2","",16],["n7","n11","set","1","",17],["n11","n14","get","2","",18],["n10","n14","set","1","",19],["n14","n15","set","1","",20],["n14","n16","get","2","",21],["n15","n14","get","2","",22],["n16","n14","set","1","",23],["n16","n18","get","2","",24],["n15","n17","set","1","",25],["n11","n17","set","1","",26],["n10","n18","get","2","",27]],"views":[{"name":"primary","nodes":{"n16":{"position":{"x":598,"y":235},"width":120},"n15":{"position":{"x":603,"y":98},"width":120},"n14":{"position":{"x":498,"y":160},"width":80},"n7":{"position":{"x":326,"y":156},"width":80},"n6":{"position":{"x":239,"y":94},"width":80},"n5":{"position":{"x":241,"y":222},"width":80},"n4":{"position":{"x":162,"y":283},"width":80},"n3":{"position":{"x":163,"y":27},"width":80},"n2":{"position":{"x":162,"y":154},"width":80},"n1":{"position":{"x":86,"y":90},"width":80},"n0":{"position":{"x":79,"y":216},"width":80},"Start":{"position":{"x":10,"y":154},"width":60},"n8":{"position":{"x":331,"y":26},"width":80},"n9":{"position":{"x":241,"y":-31},"width":80},"n10":{"position":{"x":405,"y":224},"width":80},"n11":{"position":{"x":410,"y":94},"width":80},"n12":{"position":{"x":324,"y":284},"width":80},"n13":{"position":{"x":243,"y":349},"width":80},"n17":{"position":{"x":638,"y":24},"width":90},"n18":{"position":{"x":635,"y":312},"width":90}},"edges":{}},{"name":"top down","nodes":{"P1 leads":{"position":{"x":112,"y":105},"width":90},"All":{"position":{"x":300,"y":150}},"P2 leads":{"position":{"x":502,"y":106},"width":90},"Start":{"position":{"x":300,"y":70},"width":60},"Advantage P1":{"position":{"x":154,"y":250},"width":110},"Advantage P2":{"position":{"x":450,"y":250},"width":110},"Deuce":{"position":{"x":300,"y":250},"width":60},"Game P2":{"position":{"x":550,"y":300},"width":90},"Game P1":{"position":{"x":50,"y":300},"width":90}},"edges":{}}]},
  "verbose tennis 5":{"graph":{"name":"verbose tennis 6","template":""},"nodes":[{"properties":{},"name":"Start","id":"Start"},{"properties":{},"name":"15 All","id":"n2"},{"properties":{},"name":"30 All","id":"n7"},{"properties":{},"name":"Deuce","id":"n14"},{"id":"n19","name":"p2 wins"},{"id":"n20","name":"P1 wins"},{"id":"n21","name":"P2 Ahead"},{"id":"n22","name":"P1 Ahead"},{"properties":{},"name":"Advantage P1","id":"n15","parent":"n22"},{"properties":{},"name":"40 30","id":"n11","parent":"n22"},{"properties":{},"name":"30 15","id":"n6","parent":"n22"},{"properties":{},"name":"30 Love","id":"n3","parent":"n22"},{"properties":{},"name":"Love 30","id":"n4","parent":"n21"},{"properties":{},"name":"Advantage P2","id":"n16","parent":"n21"},{"properties":{},"name":"30 40","id":"n10","parent":"n21"},{"properties":{},"name":"15 30","id":"n5","parent":"n21"},{"properties":{},"name":"Game P1","id":"n17","parent":"n20"},{"properties":{},"name":"40 15","id":"n8","parent":"n20"},{"properties":{},"name":"Love 40","id":"n13","parent":"n19"},{"properties":{},"name":"15 40","id":"n12","parent":"n19"},{"properties":{},"name":"Game P2","id":"n18","parent":"n19"},{"properties":{},"name":"40 Love","id":"n9","parent":"n20"},{"properties":{},"name":"Love 15","id":"n0","parent":"n21"},{"properties":{},"name":"15 Love","id":"n1","parent":"n22"}],"edges":[["Start","n0","get","2","",0],["n0","n2","set","1","",1],["n2","n5","get","2","",2],["n5","n7","set","1","",3],["n5","n12","get","2","",4],["n7","n10","get","2","",5],["n10","n14","set","1","",6],["n14","n16","get","2","",7],["n16","n14","set","1","",8],["n16","n18","get","2","",9],["n4","n13","get","2","",10],["n0","n4","get","2","",11],["n4","n5","set","1","",12],["Start","n1","set","1","",13],["n1","n2","get","2","",14],["n3","n9","set","1","",15],["n1","n3","set","1","",16],["n2","n6","set","1","",17],["n6","n7","get","2","",18],["n6","n8","set","1","",19],["n3","n6","get","2","",20],["n7","n11","set","1","",21],["n11","n14","get","2","",22],["n14","n15","set","1","",23],["n15","n14","get","2","",24],["n15","n17","set","1","",25],["n11","n17","set","1","",26],["n10","n18","get","2","",27]],"views":[{"name":"primary","nodes":{"Start":{"position":{"x":10,"y":154},"width":60},"n2":{"position":{"x":162,"y":154},"width":80},"n7":{"position":{"x":326,"y":156},"width":80},"n14":{"position":{"x":498,"y":160},"width":80},"n19":{"position":{"x":476,"y":361}},"n20":{"position":{"x":495,"y":-55}},"n21":{"position":{"x":349,"y":250}},"n22":{"position":{"x":355,"y":63}},"n15":{"position":{"x":603,"y":98},"width":120},"n11":{"position":{"x":410,"y":94},"width":80},"n6":{"position":{"x":239,"y":94},"width":80},"n3":{"position":{"x":163,"y":27},"width":80},"n4":{"position":{"x":162,"y":283},"width":80},"n16":{"position":{"x":598,"y":235},"width":120},"n10":{"position":{"x":405,"y":224},"width":80},"n5":{"position":{"x":241,"y":222},"width":80},"n17":{"position":{"x":680,"y":-36},"width":90},"n8":{"position":{"x":438,"y":-36},"width":80},"n13":{"position":{"x":290,"y":373},"width":80},"n12":{"position":{"x":392,"y":348},"width":80},"n18":{"position":{"x":656,"y":351},"width":90},"n9":{"position":{"x":305,"y":-74},"width":80},"n0":{"position":{"x":79,"y":216},"width":80},"n1":{"position":{"x":86,"y":90},"width":80}},"edges":{}},{"name":"top down","nodes":{"P1 leads":{"position":{"x":112,"y":105},"width":90},"All":{"position":{"x":300,"y":150}},"P2 leads":{"position":{"x":502,"y":106},"width":90},"Start":{"position":{"x":300,"y":70},"width":60},"Advantage P1":{"position":{"x":154,"y":250},"width":110},"Advantage P2":{"position":{"x":450,"y":250},"width":110},"Deuce":{"position":{"x":300,"y":250},"width":60},"Game P2":{"position":{"x":550,"y":300},"width":90},"Game P1":{"position":{"x":50,"y":300},"width":90}},"edges":{}}]},
  "Tennis Kata 1":{"graph":{"name":"Tennis Kata 1","template":""},"nodes":[{"properties":{},"name":"Start","id":"Start"},{"properties":{},"name":"P2 leads","id":"P2 leads"},{"properties":{},"name":"All","id":"All"},{"properties":{},"name":"P1 leads","id":"P1 leads"}],"edges":[["Start","P1 leads","flo","1","",0],["Start","P2 leads","flo","2","",1],["P2 leads","All","flo","1","",2],["P1 leads","All","flo","2","",3]],"views":[{"name":"primary","nodes":{"Start":{"position":{"x":10,"y":150},"width":60},"P2 leads":{"position":{"x":75,"y":250},"width":90},"All":{"position":{"x":137,"y":150}},"P1 leads":{"position":{"x":75,"y":50},"width":90}},"edges":{}},{"name":"kitty corner","nodes":{"P1 leads":{"position":{"x":112,"y":105},"width":90},"All":{"position":{"x":300,"y":150}},"P2 leads":{"position":{"x":502,"y":106},"width":90},"Start":{"position":{"x":300,"y":70},"width":60},"Advantage P1":{"position":{"x":154,"y":250},"width":110},"Advantage P2":{"position":{"x":450,"y":250},"width":110},"Deuce":{"position":{"x":300,"y":250},"width":60},"Game P2":{"position":{"x":550,"y":300},"width":90},"Game P1":{"position":{"x":50,"y":300},"width":90}},"edges":{}}]},
  "Tennis Kata 2":{"graph":{"name":"Tennis Kata 2","template":""},"nodes":[{"properties":{},"name":"Game P1","id":"Game P1"},{"properties":{},"name":"Game P2","id":"Game P2"},{"properties":{},"name":"Start","id":"Start"},{"properties":{},"name":"P2 leads","id":"P2 leads"},{"properties":{},"name":"All","id":"All"},{"properties":{},"name":"P1 leads","id":"P1 leads"}],"edges":[["Start","P1 leads","flo","1","",0],["Start","P2 leads","flo","2","",1],["P2 leads","All","flo","1","this.tied() && this.score('P1') < this.forty()",2],["P1 leads","All","flo","2","this.tied() && this.score('P2') < this.forty()",3],["P1 leads","P1 leads","flo","1","",4],["P2 leads","P2 leads","flo","2","",5],["All","P1 leads","flo","1","",8],["All","P2 leads","flo","2","",9],["P2 leads","Game P2","flo","2","this.score('P2') >= this.forty()",14],["P1 leads","Game P1","flo","1","this.score('P1') >= this.forty()",17]],"views":[{"name":"primary","nodes":{"Game P1":{"position":{"x":490,"y":50},"width":90},"Game P2":{"position":{"x":490,"y":250},"width":90},"Start":{"position":{"x":10,"y":150},"width":60},"P2 leads":{"position":{"x":75,"y":250},"width":90},"All":{"position":{"x":120,"y":150}},"P1 leads":{"position":{"x":75,"y":50},"width":90}},"edges":{}},{"name":"top down","nodes":{"P1 leads":{"position":{"x":112,"y":105},"width":90},"All":{"position":{"x":300,"y":150}},"P2 leads":{"position":{"x":502,"y":106},"width":90},"Start":{"position":{"x":300,"y":70},"width":60},"Advantage P1":{"position":{"x":154,"y":250},"width":110},"Advantage P2":{"position":{"x":450,"y":250},"width":110},"Deuce":{"position":{"x":300,"y":250},"width":60},"Game P2":{"position":{"x":550,"y":300},"width":90},"Game P1":{"position":{"x":50,"y":300},"width":90}},"edges":{}}]},
  "Tennis Kata 3": {
  "graph": {
    "name": "Tennis Kata",
    "template": ""
  },
  "nodes": [{
    "properties": {},
    "name": "P1 leads",
    "id": "P1 leads"
  }, {
    "properties": {},
    "name": "All",
    "id": "All"
  }, {
    "properties": {},
    "name": "P2 leads",
    "id": "P2 leads"
  }, {
    "properties": {},
    "name": "Start",
    "id": "Start"
  }, {
    "properties": {},
    "name": "Advantage P1",
    "id": "Advantage P1"
  }, {
    "properties": {},
    "name": "Advantage P2",
    "id": "Advantage P2"
  }, {
    "properties": {},
    "name": "Deuce",
    "id": "Deuce"
  }, {
    "properties": {},
    "name": "Game P2",
    "id": "Game P2"
  }, {
    "properties": {},
    "name": "Game P1",
    "id": "Game P1"
  }],
  "edges": [
    ["Start", "P1 leads", "flo", "1", "", 0],
    ["Start", "P2 leads", "flo", "2", "", 1],
    ["P2 leads", "All", "flo", "1", "this.tied() && this.score('P1') < this.forty()", 2],
    ["P1 leads", "All", "flo", "2", "this.tied() && this.score('P2') < this.forty()", 3],
    ["P1 leads", "P1 leads", "flo", "1", "", 4],
    ["P2 leads", "P2 leads", "flo", "2", "", 5],
    ["P1 leads", "Deuce", "flo", "2", "this.tied() && this.score('P2') >= this.forty()", 6],
    ["P2 leads", "Deuce", "flo", "1", "this.tied() && this.score('P1') >= this.forty()", 7],
    ["All", "P1 leads", "flo", "1", "", 8],
    ["All", "P2 leads", "flo", "2", "", 9],
    ["Deuce", "Advantage P1", "flo", "1", "", 10],
    ["Advantage P1", "Deuce", "flo", "2", "", 11],
    ["Deuce", "Advantage P2", "flo", "2", "", 12],
    ["Advantage P2", "Deuce", "flo", "1", "", 13],
    ["P2 leads", "Game P2", "flo", "2", "this.score('P2') >= this.forty()", 14],
    ["Advantage P2", "Game P2", "flo", "2", "", 15],
    ["Advantage P1", "Game P1", "flo", "1", "", 16],
    ["P1 leads", "Game P1", "flo", "1", "this.score('P1') >= this.forty()", 17]
  ],
  "views": [{
    "name": "primary",
    "nodes": {
      "Game P1": {
        "position": {
          "x": 490,
          "y": 50
        },
        "width": 90
      },
      "Game P2": {
        "position": {
          "x": 490,
          "y": 250
        },
        "width": 90
      },
      "Deuce": {
        "position": {
          "x": 210,
          "y": 150
        },
        "width": 60
      },
      "Advantage P2": {
        "position": {
          "x": 350,
          "y": 200
        },
        "width": 110
      },
      "Advantage P1": {
        "position": {
          "x": 350,
          "y": 100
        },
        "width": 110
      },
      "Start": {
        "position": {
          "x": 10,
          "y": 150
        },
        "width": 60
      },
      "P2 leads": {
        "position": {
          "x": 75,
          "y": 250
        },
        "width": 90
      },
      "All": {
        "position": {
          "x": 120,
          "y": 150
        }
      },
      "P1 leads": {
        "position": {
          "x": 75,
          "y": 50
        },
        "width": 90
      }
    },
    "edges": {}
  }, {
    "name": "top down",
    "nodes": {
      "P1 leads": {
        "position": {
          "x": 112,
          "y": 105
        },
        "width": 90
      },
      "All": {
        "position": {
          "x": 300,
          "y": 150
        }
      },
      "P2 leads": {
        "position": {
          "x": 502,
          "y": 106
        },
        "width": 90
      },
      "Start": {
        "position": {
          "x": 300,
          "y": 70
        },
        "width": 60
      },
      "Advantage P1": {
        "position": {
          "x": 154,
          "y": 250
        },
        "width": 110
      },
      "Advantage P2": {
        "position": {
          "x": 450,
          "y": 250
        },
        "width": 110
      },
      "Deuce": {
        "position": {
          "x": 300,
          "y": 250
        },
        "width": 60
      },
      "Game P2": {
        "position": {
          "x": 550,
          "y": 300
        },
        "width": 90
      },
      "Game P1": {
        "position": {
          "x": 50,
          "y": 300
        },
        "width": 90
      }
    },
    "edges": {}
  }]
}
};
