# Last Class 12/5/19

### Exam prep 
- Deque keeps track of start and end - we can push and pop from both ends efficiently but is slightly less space efficient
- vector is the way to go if you only need to pop from the back
- popping from both ends = deque
- inserting is less efficient for both (O(1) -> O(n))
- Linked lists 
- push back on a linked list with only a head pointer is O(n)
- with a head and tail pointer is O(1)
- need info about linked list to answer complexity questions
- What is the time complexity of a lookup on a hash map? 
- O(1) lookup without notion of ordering
- Order-free implementation of a vector
- set = list with no duplicates 
- implement a set with a vector: modify insert to check if it's in the vector - if it is, then don't add (O(n)) 
- implement intersection 
- implement union in a set. 
- Lookup in a map, index into a list, push back, push front, insert on deques and vectors 
- all of access patterns of generic linked lists, trees, graphs
- binary vs binary search trees
    - binary search tree has ordering: lookup on BST = O(log n) 
    - lookup on binary tree = O(n) because unordered 
- Ex. implement find min on binary tree. 
    - traverse the tree and find min

### Review
- Template: we can replace data type with placeholder 
    - different versions of classes will automatically be created for different data types 
    - data types must be consistent. 
- We talked about data structures and access patterns for those data structures. 

