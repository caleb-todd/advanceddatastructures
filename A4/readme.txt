#######################################
File to explain HASH assignment
#######################################
To compile, type 'make'
to run, type ./HASH


TASK 6:
For No collisions, it seems that chaining list did better than vector, the same was true for low collision, and high collisions,
Insertion time for chaining BST was longer than chaining list and vector, but search time was quicker for the three data sets.
For linear probing, it had a low insertion time and a long search time, but quadratic probing was the opposite. for high collision data. For low or no collision data, they both had similar results, with insertion taking longer than searching.
Double hashing had consistent results for all data sets, with not much change in time between the three.

Comments:
Simple to implement, just repeating steps and proper implementation, added function in main for easier to understand printing