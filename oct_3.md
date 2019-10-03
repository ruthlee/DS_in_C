# Oct 3: Heap Allocation, Pointer to Pointer, Struct

### Review
- Everything we create occupies some amount of memory
- Array is a block of chars/ints/basic types
    - exposed as pointer to first element
```C
int A[10]; // initializes block of 10 integers and points to the first one
sizeof(A); // evaluates to 40
int *q = A; // pointer to first element of a
q++; // now q points to the second element of A 
*q; // = A[1]
a[b]; // = *(a + b), address and offset 
char c[] = "abc"; // is a char array which lets us imbed the size of the array because null character is implied- STRING equivalent to char c[] = {'a', 'b', 'c', '\0'};
```
- don't normally modify string arrays; stored in different part of memory (static memory). If you were going to modify, you'd use regular char array. 

### Heap Allocation Motivation
- Want functions to return arrays
```C
void foo() {
    int x = 5; 
    blah blah
    // x gets deleted after function end
    return A;
    // does not return the whole array, only value of the first element
}
```
- When we leave the scope, we return a pointer to the first element of an array which is now gone, so it's useless
    - seg fault
- We want to write a function to create a bunch of things, they stick around, and later you can deallocate memory
- We want dynamic allocations of memory that can live between scopes

### Solution
- ```malloc(n)``` assigns memory on heap, not stack. It allocates n bytes of memory on the heap and points to the first one. 
    - stack stores automatic variables, heap doesn't.
```C
int *p = (int *) malloc(100 * sizeof(int)); \\ returns void * (generic pointer) to n bytes of memory on the heap
\\ we say sizeof(int) to make it more readable; this allocates 100 integers on the heap, even if the machine assigns a different number of bytes per int.
```
- Question: how can you tell whether a language is big endian or little endian (reads left to right or right to left binary) 
- if malloc gives back a NULL value then it means memory can't be allocated
    - edge case we don't have to handle; print that malloc failed and exit program
    - code to exit in L04 notes
- ```memset``` can also initialize elements of a malloc-assigned chunk of memory.
- ```free(p);``` deallocates memory block previously returned by ```malloc```. 
- allocate persistant variables with ```malloc```. 
    - before I use p for something else need to make sure to free up p so it doesn't cause memory leak.
- For every program we write, need to check that memory can be allocated, (no memory errors allowed) AND everything that we allocate we need to free- no memory leaks allowed. 
- **Upshot: can return a pointer to an array allocated on the heap because it doesn't go away**

### How Tim will check our programs for memory leaks
- valgrind is the program we'll use
- if in use at exit we have 0 bytes in 0 blocks; n allocs, n frees; and 0 errors in 0 contexts, then you're good
    - ```valgrind ./a.out```
- invalid writes or reads are not good
    - we're trying to write memory that we're not using or read memory we didn't use 
- if you try to double free, you'll also get errors. 

**UPSHOT: most data structures are going to need to have dynamic allocations**

### Pointer to Pointer
- ```char **p = a;``` is a pointer pointing to a pointer to a. 
- Common case where we see double pointers is string literal array
- ```printf("%c %c\n", p[0], p[1]);``` in notes would just print "H" and "w"
- Command line arguments
    - argv[0] is a char* pointing to echo, argv[1] points to hello, argv[2] points to world
- ** is a pointer which takes us to address of a pointer, which if we follow to the address will get us to the first element of array or whatever

### Struct
- A struct is a bundling of basic types
```C
struct point {
pt.x = 2;
pt.y = 3;
} // like a header

struct point pt; // actual declaration
pt.x = 2;
pt.y = 3; 
```
- Under the hood, in memory it aliases a big block of memory that stores two ints. pt.x is an alias for first four bytes, pt.y the second four bytes.
- array of structs can bundle data 
- can typedef struct into another variable
- we can allocate an array of ints and an array of chars at once, for example.
- structs are pass by value like everything else. 
```C
struct point *pPt = &pt; 
(*pPt).x = 2; // means deallocate the pointer and get the x thing (need parenthesis) 
pPt->y = 3; // means deallocate the pointer and get the y thing
```
