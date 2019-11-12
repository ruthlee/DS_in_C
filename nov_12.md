# Nov 12 

### Labs
- Labs 5 and 6 have been pushed back a week. 

### Lecture 10: C-style Binary Search Tree
- Up until this point, we have linear data structures (list) 
- Now we have nonlinear
- Each node has 0, 1, or 2 children. 
- Everything on the left subtree contain values less than x, right subtree has values greater than x.
- BST = type 
- looking at very C-style code here, to bridge gap between C and C++ 
- In C and C++ **class and struct are the same thing**
    - classes are private by default, structs are public by default. 
    - can still define private and public things within a struct, but that would be the same thing as calling it a class. 
- insertion: look at root node, if it's null allocate return the tree. If not, perform comparison and put it on the right or left RECURSIVELY. Else (if x is already in the tree) just return the same tree. 
- We also remove all nodes recursively 
- Trees are basically linked lists that can split
- Traverse in order: go left as far as you can before going right. 
    - one of the arguments is a function pointer to a function which would presumably print the contents of the node. 

### Complexity
- Binary search algorithm on a list is made very easy with tree data structure. 
    - time complexity of lookup is O(log(n)). 
- Inserting is O(log(n))
- If I have an array, inserting is O(n)
- if our use case is to store data, search, insert data, then tree is more efficient for storing than list.
- BST we have both insertion and search relatively cheap
- time complexity of remove all nodes: O(n)
- draw: O(n) (have to look at every node)
- traverse all noes: O(n)
- height: O(n) 
- find min, find max: O(log(n))
- We could have **BALANCED BINARY SEARCH TREE** 
    - which would rebalance the three
- If we insert things in order then we end up with a linked list, and all of our O(log(n)) turn to O(n) 
    - we won't be exactly O(log(n)) - we'll end up doing worse and worse the closer in order we insert our data. 

### Proper C++ Style BST (Lecture 11)
- we're using methods on classes, not random global functions 
- can also implement removing nodes.
- BSTNodes are private, but we make the BSTNode class a friend so that we can alter nodes. 
    - making a class a friend means that from within the BST class, we can access private attributes of BST class 
- Note: API means how people interact with code
    - Classes have certain APIs - how user interacts with class. 
    - Set of public methods exposed to end user. 
- Make all C-style methods/functions and make it private
    - take nodes and make them private
    - the only API we expose is clean BST class one. 
- Namespaces: can either declare/define a function within a namespace with the double colon operator (cpp file) or with namespace and brackets (header) or with using namespace keywords 
    - classes define namespaces which are basically scoping levels.
    - like importing packages in python
- If you want to refer to outer namespace, can use ::max operator to define outside namespace.
- in insert function in BST2 we have :: to indicate what namespace each of the things lives in. 
- only friends can touch a class's private stuff
