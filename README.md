appStation
==========
appStation, aims to make state machines easier to use in your applications.

Demo env http://esromlabs.github.io/appstation/editor.html?example=Turnstyle

A Visual Graph Based Editor
--------------------
 * a visual editor lets you see the states and transitions in any layout (with multiple views)
 * you can create and edit properies of the states in your machine
 * allows hierarchical state (states can have a parent that provides a base set of properties)
 * import and export your FSM for use in a state machine interpreter
 
What is a state machine and what is it good for?
--------------------
>A state machine is made of states and transition. States represent a resting state where properties are static and only a transition can change them. Transitions move the current state of the state machine interpretor to a new state.
State Machines are 

>You will not find an "IF" or "WHILE" control structure in an FSM. The traversal from state to state is determined by the topology of the graph. Conditionals and loops are easy to make by branching or cyclical transitions 

FSA Visualization
------------------
Central to the appStation project is the ability to easily visualize, edit, share and debug FSMs (rendered as a graphs).
A survey of available graph editor applications revealed a lack of web based tools that could be integrated into this pattern of programming. Several rendering libraries have been explored, and currently effort is being invested into integrating
Cytoscape.js into the appStation environment. Modularity is also a focus of the design, so that alternate graph rendering options could be supported
in the future.

Cytoscape.js is used to facilitate graph visualization, by providing a view into FSMs. The goal is to present them in a high cognitive-bandwidth format.

