# Oct 1 Class: Pointers and Arrays

### Lab 2
- Part 2: figure out where to put print statements given recursion
    - always asked about on tests
- Part 4: have to use ```/usr/bin/time```
    - memory usage: measures max usage of memory at any point in time (so approximation) 
    - Theoretical vs practical has to do with why the complexity isn't going to match what I'd expect. 
    - Mergesort has O(n) complexity but gets worse as array size increases because space constraints physically raise time it takes to run
    - depends on how many people are using how much memory on the machine
- ```git diff origin/master``` will tell me if I've changed files that I wasn't supposed to change.

### Pointers and Arrays 
- Double quotes cause there to be an extra null pointer (HW 3) 
```C
char c[] = "abc"; // sizeof(c) = 4
```
- **Arrays are just syntactic sugar for pointers** 
    - ```int a[10];``` means initialize ten integers in contiguous memory and point to the first one
    - ```x = *p; // same as a[0]```
    - ```x = *(p+1); // same as [1]```
- You can initalize a pointer ```int *p = a;``` which points to the same thing as the first element of a. 
- Anywhere you use array notation, you can use pointer notation and vice versa
- Pointers are typed, so ```p+1``` moves me the number of bytes away to match with the type of p. So if a is array of integers, then ```p+1``` will move pointer forward by 4 bytes. 
- ```sizeof``` is one difference; if you call it on a pointer you'll get 8; at an array you'll get the size of the array (sizeof(a)/sizeof(a[0]))
- compiler automatically converts ```a[b]``` to ```*(a+b)```
- CAN change pointer, but CANNOT change array 
- Indexing a list is O(n) because it only takes one addition operation to get to any index position (```a[5] = *(a+5)```)
- ```int x = q - p;``` where q and p are both pointers subtracts positions of the positions 
```C
*(0+a) = // a is an address, 0 + a is the address, then we dereference it
0[a] = a[0] // a[b] is address a offset by b. This means offset 0 by a and dereference.
```
- In homework we exploit the fact that ASCII character mappings match the order of integer numbers so we can store numbers as characters. 
- Pointers are addressing a block
    - can interchange pointer and array notation. 

### Data Structures Questions
- How much does appending to an array cost in C?
    - Create a list of 10 things that is empty, how much does it cost to put something in the lsit? Should just be O(1); calculate offset, get bucket, put that thing in
    - if you want to create a new space (10 elements -> 11) is O(n) -- have to create a new array and copy everything into it
    - adding an element into array, have to shift everything else down, worst case scenario O(n)
    - deleting an element is also O(n)
- numpy arrays take up continguous memory, that's why it's hard to append to them
    - so it's best to append to your Python list then convert to numpy array

### Memory management
- Ask someone for 10 integers means someone gives you ```int *p```. We'll have blocks of memory and pointers pointing to the beginning of it. 

### Char array = String
- ```char *p = "abc";``` is a string literal
    - most likely will only use double quotes 
- double quotes are not modifiable UNLESS
    - ``` char c[] = "abc";``` can be modified because expressly cast as char array (size 4 including null char)
- A string is done when we read a null character (because it doesn't print anything); so don't need to keep track of how many chars in the string 

### Heap Memory Allocation
- Dynamic memory: I'm writing a program, everything is pass by value, single return also by value. 
    - I want to write a function which takes in an integer and returns an array
    - Anything I declare in the function will go away when function ends. 
    - If I return something, that value is copied out 
    - If I try to return the array, the value of the pointer is returned, the array goes away, seg fault.
- We want function to produce something that doesn't go away when function ends. 
    - Want to create some variable and take responsibility for when to delete it. 
- Most languages have automatic memory management
    - Java periodically goes through and cleans up pointers which don't point to anything
- C does not have memory management, so we have to do it ourselves.
- We want inner scope to feed to outer scope WITHOUT global variable
- SOLUTION: next time. 
- What happens if you mismanage memory? 
    - if you forget to clean up, OS allocates memory and deleted pointer to first element but not the stuff itself; memory from program grows and grows and grows and can't stop (memory leakage) 
    - Ex. chrome :) 

### Debugging Tips
- GDB and LDB are two "debugging facilitators" 
- Look for cheat sheets 

```C
lldb [EXECUTABLE] 
breakpoint set -f gcd.c -l 4 \\ on gcd file on line four whenever you get there, stop. 
p x \\ print value of x
bt \\ can see everything that happened
n \\ next line
s \\ step in 
q \\ quit
```

- lldb wraps executable and lets you poke around
