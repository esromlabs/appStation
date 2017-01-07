var ex = {
  "test10":{
    "graph":{"name":"test10","template":""},
    "nodes":[
      {"name":"final_loading","id":"n4", "properties":{"stateEntered":"function () { getDocuments(); }","loading_gear_icon":true}},
      {"name":"submitted","id":"n3", "properties":{"submit_disabled":true}},
      {"name":"confirm_submit","id":"n1","properties":{"submit_disabled":true,"WebMsg":"please confirm submit"}},
      {"properties":{"initializing":true},"name":"start","id":"nstart"},
      {"properties":{"stateEntered":"function () { getDocuments(); }","loading_gear_icon":true},"name":"loading","id":"nloading"},
      {"properties":{},"name":"adding","id":"nadding"},
      {"properties":{"uploading_gear_icon":true},"name":"uploading","id":"nuploading"},
      {"properties":{"display_error":true},"name":"upload_error","id":"nupload_error"},
      {"properties":{"display_error":true,"availability_error":true},"name":"loading_error","id":"nloading_error"},
      {"properties":{"stateEntered":"function () { checkCaseId(); }","loading_gear_icon":true,"initializing":true},"name":"check_caseId","id":"ncheck_caseId"},
      {"properties":{"display_error":true,"availability_error":true},"name":"caseId_error","id":"ncaseId_error"},
      {"properties":{"display_error":true},"name":"submit_error","id":"nsubmit_error"},
      {"properties":{"submit_disabled":true},"name":"submitting","id":"nsubmitting"},
      {"properties":{},"name":"removing","id":"nremoving"},
      {"properties":{"display_error":true},"name":"remove_error","id":"nremove_error"},
      {"id":"n0","name":"lock_out"},
      {"properties":{"stateEntered":"function () { getDocuments(); }","loading_gear_icon":true,"initializing":true},"name":"initial_loading","id":"n2"}
    ],
    "edges":[
      ["nremoving","nloading","flo","success",null,0],
      ["nremoving","nremove_error","set","fail","",1],
      ["nsubmitting","nsubmit_error","set","fail","",2],
      ["ncaseId_error","ncheck_caseId","get","retry","",3],
      ["ncheck_caseId","ncaseId_error","set","fail","",4],
      ["nloading_error","nloading","get","retry","",5],
      ["nuploading","nupload_error","set","fail","",6],
      ["nuploading","nloading","flo","success",null,7],
      ["nadding","nuploading","get","upload","",8],
      ["nloading","nloading_error","set","fail","",9],
      ["nloading","n0","flo","lock","",10],
      ["nloading","nadding","flo","success","",11],
      ["nadding","nremoving","get","remove","",12],
      ["nadding","n1","get","submitDocs","",13],
      ["n1","nsubmitting","get","confirm","",14],
      ["n1","nadding","get","cancel","",15],
      ["n2","nloading_error","set","fail","",16],
      ["ncheck_caseId","n2","flo","success","",17],
      ["n2","nadding","flo","success","",18],
      ["n2","n0","flo","lock","",19],
      ["nstart","ncheck_caseId","flo","init","",20],
      ["nsubmit_error","n1","get","retry","",21],
      ["nsubmitting","n4","flo","success","",22],
      ["n4","n3","flo","lock","",23],
      ["n4","nloading","set","fail","",24],
      ["n4","nsubmit_error","flo","success","",25],
      ["nupload_error","nuploading","get","upload","",26],
      ["nupload_error","nadding","get","retry","",27],
      ["nremove_error","nadding","get","retry","",28]
    ],
    "views":[
      {"name":"pincushion","nodes":{"n4":{"position":{"x":445,"y":161}},"n3":{"position":{"x":509,"y":225}},"n1":{"position":{"x":335,"y":378}},"nstart":{"position":{"x":-111,"y":2}},"nloading":{"position":{"x":546,"y":-16},"width":60},"nadding":{"position":{"x":184,"y":333}},"nuploading":{"position":{"x":199,"y":36},"width":100},"nupload_error":{"position":{"x":125,"y":141},"width":100},"nloading_error":{"position":{"x":60,"y":-16},"width":100},"ncheck_caseId":{"position":{"x":-111,"y":370}},"ncaseId_error":{"position":{"x":7,"y":311}},"nsubmit_error":{"position":{"x":444,"y":329}},"nsubmitting":{"position":{"x":372,"y":265}},"nremoving":{"position":{"x":348,"y":81}},"nremove_error":{"position":{"x":244,"y":132},"width":100},"n0":{"position":{"x":546,"y":414}},"n2":{"position":{"x":60,"y":414},"width":100}},"edges":{}},
      {"name":"zig_zag","nodes":{"n4":{"position":{"x":521,"y":516}},"n3":{"position":{"x":595,"y":426}},"n1":{"position":{"x":406,"y":301},"width":100},"nstart":{"position":{"x":-56,"y":206}},"nloading":{"position":{"x":227,"y":510},"width":60},"nadding":{"position":{"x":199,"y":298}},"nuploading":{"position":{"x":348,"y":456}},"nupload_error":{"position":{"x":349,"y":368}},"nloading_error":{"position":{"x":177,"y":580}},"ncheck_caseId":{"position":{"x":-58,"y":478}},"ncaseId_error":{"position":{"x":70,"y":406}},"nsubmit_error":{"position":{"x":530,"y":217}},"nsubmitting":{"position":{"x":590,"y":299}},"nremoving":{"position":{"x":428,"y":485}},"nremove_error":{"position":{"x":431,"y":408}},"n0":{"position":{"x":170,"y":454}},"n2":{"position":{"x":119,"y":509}}},"edges":{}}
    ]
  };