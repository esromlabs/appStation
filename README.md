appStation
==========
Demo env http://esromlabs.github.io/appstation/editor.html?example=Turnstyle

appStation, aims to make the use of Finite State Machines (FSMs) easier to use for several programming tasks.
 * a visual graph based editor lets you see the states and transitions in any 2D layout (multiple views on the same graph)
 * you can create and edit any properies of a state
 * allows hierarchical state (states can have a parent that provides a base set of properties)
 * import and export your FSM for use in your FSM interpreter
 
A Visual Graph Based Editor
--------------------
>The syntax for an FSM is made of states and transition. States represent a resting state where properties are static and only a transition can change them. Transitions move the current state of the FSM interpretor to a new state.

>You will not find an "IF" or "WHILE" control structure in an FSM. The traversal from state to state is determined by the topology of the graph. Conditionals and loops are easy to make by branching or cyclical transitions 

FSA Visualization
------------------
Central to the appStation project is the ability to easily visualize, edit, share and debug FSMs (rendered as a graphs).
A survey of available graph editor applications revealed a lack of web based tools that could be integrated into this pattern of programming. Several rendering libraries have been explored, and currently effort is being invested into integrating
Cytoscape.js into the appStation environment. Modularity is also a focus of the design, so that alternate graph rendering options could be supported
in the future.

Cytoscape.js is used to facilitate graph visualization, by providing a view into FSMs. The goal is to present them in a high cognitive-bandwidth format.

A Portable Approach
-------------------
When the Graphlet environment loads a flow-control-graph, it registers "pubsub" style subscriptions for all edges in
the graph. Nodes marked for data "i/o" are registered with the local server, DOM environment, or data services across Internet.

Diverse environments such as embedded systems, servers and clients, that have pubsub patterned utilities may run a Graphlet flow-control-graph.
Code portability will be supported by a process of code generation, where the graph source is transposed into pubsub calls for the local environment.

Event Oriented
--------------
Message passing is represented in the graph by certain edge types {color:blue}. These message bearing edges
can be styled to clearly show the source and target of message. The affected on connected nodes of the graph can be traced and
understood visually.
The Graphlet interpreter also sends events out to any external subscribers, these events
allow developer tools to display an indication of how your graph is progressing. External development tools
could be as simple as progress bar, or as complex as a full IDE (eg. TBD the HoneyBee project).

Visualizing Data Structures and Transformations
-----------------------------------------------
Stacks, Queues, Lists (my favorite is a 'Skip List'), State Machines, and Heaps are all usefull Data Objects. Each one could really benefit the programmer by having a visual representation. The goal is to provide a visual environment that is helpful in alining a programmers intent with the selected data structures and associated transformations.


The Way Graphlet Works
======================
So far, Graphlet has been developed with an alternating focus on coding (a) ideals and (b) practicalities.
Hopefully a balance will result in an semi-ideal yet practical programming system.

This is what I know about the "way" it works (to date). Questions
"Why is it done this way?" and
"How did this come about?" are difficult to answer, other than "It has emerged in this way
from a few _highfalutin_ ideals and a great number of pesky practicalities."


Node abilities (types)
----------
 * Process (executes some operation)
 * Data (stores data in the node)
 * IO  (represents some external input/output data)

Nodes in Graphlet may hold a "process" to be executed and/or "data" either stored internally
or externally via input or output.

Nodes can have any combination of these abilities.
For example, a node could store "data" (perhaps a 'counter') and "process" data
(perhaps 'increment' that counter).
A node takes on a type of role in the graph network by:
 * defining a "process" operation to be executed
 * Storing "data"
 * Referencing some external input/output "IO" element.

Edge types
----------
 * Get gets data from targeted nodes
 * Set sets data on targeted nodes
 * Pub publishes a message to the target (IO) node
 * Sub subscribes to messages from the source (IO) node
 * Flo flow or transition (guarded) between nodes

Edges define how data moves and how the flow-of-control moves from node to node
while the Graphlet is running.
> Note that Graphlet does *not* have any flow-of-control structures
 such as `for/while-loops` or `if-then-else blocks`. Instead all flow of execution is
 controlled by edges that pass the control from node to node until no edge is suitable for
 transition and therefore no node is given the control to execute.


Starting a Graphlet Program Running
===================================
calling `graphlet_init(graph)` with a Graphlet (source graph) will prepare the program to
be run and then a `graph_init` message is emitted.
If a graph has a subscribe edge (of type 'sub') listening for this event, then the edge's target
node is given control to execute. A Graphlet may also lay dormant, waiting for an input message
from an element (IO node) with a subscribe edge, such as a 'click' event on a button element in a web browser.



Execution Steps for a Node
------------------------
When a node is given control by a message or transition, these 4 processing steps are executed in this order.
 * Get data (via all immediate "get" edges)
 * Process the internal function or operation of the node
 * Set data or publish events (via all immediate "set" or "msg" edges)
 * Transition to the next node (via one selected "Guard protected" transitions edges)

