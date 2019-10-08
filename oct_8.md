# Oct 8: Linked Lists Intro

### Logistics
- ```/home/w3136/submit/check-late-days``` will check late days that you have.

### Pointers: review
- malloc can handle dynamically sized arrays
    - malloc can allocate generic blocks of memory. 
- Anything we allocate we need to free
- Double de-referencing argv gives us first letter of first argument 
- structs are not classes but let us bundle variables. 
    - a struct with 2 integers is 8 bytes
    - can call attributes of a struct 
- can use pointers to structs
- ```(*pPt).x; ``` means dereference pPt and get x attribute
- ```char c[] = "abc";``` can't be incremented, can't reassign the array.  
    - ```char *p = "abc";``` can reassign p but can't modify array. 

### Function pointers motivation
- We want to repeatedly add to an array quickly (perhaps at the cost of less speedy accessing of elements)
    - we want appending to be O(1). (accessing = O(n))
- C doesn't have strings. We only have ```char* a;```
- string library has useful functionality to manipulate strings (cppreference.com)
- ```const``` is a modifier for a type; is a signifier for the thing that can't be changed. 
    - modifying a const variable will lead to a compilation error
    - better alternative to #DEFINE because it's not just text relacement 
    - can pass a non-const variable but we'll get a note
    - in the hw we'll have to deal with this; we will make a non-const arg const at some point?? 
- we want generic type of data structure that can hold any underlying type
    - i.e., a list can hold integers or floats
    - we want a data structure that can work with ints, chars, structs, etc.

### Function Pointers - complicated declarations
- Allows us to write generic algorithms for any data type
- We can write custom functions and pass them into our general algorithm function
-```int (*f1)(const void *v1, const void *v2);``` declares a pointer to a function which takes a const void*, const void*, and returns an int.  
    - lets us point to a function- we can make a placeholder to a function which we've written. 
    - Ex., ```f1 = &factorial_function;```
-```int *f2 (const void *v1, const void *v2);``` declares a function which takes a const void*, const void*, and returns an int pointer.  
-```int (*f3[5])(const void *v1, const void *v2);``` is a declaration of an array of five function pointers which takes in a two constant void pionters and returns and int. 
    - declares a variable which will later on hold five functions. 
- **TRICK FOR COMPLICATED FUNCTION DECLARATIONS: clockwise rule**

### Linked Lists
- Array has great inexing time (O(1))
    - insert/delete/append is O(n)
- Linked lists have bad indexing time (O(n))
    - one of insert, double, append is O(1)
- To append, we allocate memory on the heap and a pointer to the next element of the struct
- A singly linked list with head pointer means we have arrow to front of list and single pointers linking the list
    - singly linked list with head and tail pointers is same but we know where the end is
    - doubly linked list means we have arrows connecting both directions
- for this class we want to make **singly linked list with head pointer** 
- Time complexity
    - insert: we have to walk to nth spot, put item in, and change up pointers: O(n)
    - delete: same, O(n)
    - append: same, O(n) - we have to walk all the way to the end of the list
        - with tail pointer would be O(1)
    - for repeated insertions, deletions, appends it's efficient

### What do we need for linked list? 
- We need data and a pointer.
- We have a struct called "Node" which is self-referential (like recursive) 
    - we have data and a pointer which points to another struct which itself has data
- If you want to initialize an empty linked list you just make initialize with null pointer. 
