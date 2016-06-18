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

