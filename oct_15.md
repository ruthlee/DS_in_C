# Oct 15: Linked Lists 2

### Linked List 2
- Instead of prepend we have insert 
- Sample exam question: write an append function 
- For:
    - Algorithms:
        - Complexity, strategy
    - Data structures:
        - How do we access them? (prepend, append, delete, insert)
        - How are they indexed? How fast? 
        - Usage (what are they good for?)
- Arrays:
    - indexing is O(1) 
    - Inserting, appending, prepending, deleting is O(n)
    - Arrays are good for sort and search
- Doubly Linked lists: willing to let index get slower (O(n)) for appending to get faster 
    - insert, append, delete is still O(n)
    - prepend is O(1) 
- Doubly linked list makes prepend and append become O(1)
    - if we did double direction arrows and skip lists things are better
- Other linear data structures: array, linked lists, stack, queque 
    - graphs, binary trees, etc. are nonlinear data structures
- Find algorithm is O(n) 
    - remove nodes is O(n) 
- ```remove_node``` function: might remove front of list
    - analogue to swap problem 
    - give the function the address of the list, which means that we can modify the list itself instead of returning the list
    - So we use a pointer to a pointer to modify list
    - First if statements ensure that we won't get seg faults from Null pointers
    - Understanding this function is key to first half of course

### Lab 3 Overview
- Must run valgrind on executables
- my test1.c will be replaced with theirs- make sure nothing critical to implementation is there
- Reading an unitialized value or read errors mean you're allocating something in an array form and putting the null character in the wrong spot. 
- NEED TO REDO REVERSE FUNCTION
    - keep original list in place
- Don't have to handle invalid recipes, assume it's max 100 integers 
- Permutation function will be okay, can copy into new list BUT NOT REVERSE
- Part 4: sort the nodes based on the length that you store (first two numbers) and NOTHING ELSE!! so it's easier than I thought.
    - stable sort: if two things have the same value but different attribute in some way, then their order is maintained in the final list
