#######################################
File to explain SPLAY assignment
#######################################
To compile, type 'make'
to run, type ./SPLAY

TASK 5:
The splaying in splay trees affect the balance mostly minimally in the long 
term, while at times during rotations it can become unbalanced, it usually
ends up gradually rebalancing itself. The amortized running time is not 
hugely impacted, as it stays fairly efficient regardless. The running time
per operation should remain O(log n) when considering a span of operations.
Comments:
Not too difficult, once I understood the operations and order of things,
hopefull exception handeling was done correctly, and outputs are correct. 