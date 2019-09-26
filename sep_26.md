# Sep 26 Class

### Review
- By passing locations and not values (pass by point) you can simulate pass by reference 

### Pointers
- Memory buckets where data lives
- **Pointer** = address for the bucket
- 64 bit operating system means we can have addresses from 0 to 2^64-1 
    - how big is an ```int *p```? 
    - char is 1 byte
    - int is 4 byte
    - ```int *``` is 8 bytes 
- Every pointer takes up 4 bytes ```char *p``` takes up 8 bytes even if it points to something of 1 byte 
    - Pointers are **8 bytes** because we are on a 64-bit system which means each address is 64 bits, 64/8 = 8 bytes 
    - "64 bit system" means the max address space. 
    - pointer stores address, so it must take up that much space 
- Every pointer takes up 8 bytes, but depending on how it's cast it will return a certain number of bytes 
    - even pointer to pointer is 8 bytes 
- ```int *p``` grabs four buckets, ```char *p``` grabs one bucket, etc. How you cast the pointer determines how much you grab. 
    - ```void *p``` means you don't know how many buckets you're going to need to grab. 
- Memory management in C means that you have to keep track of types 
    - no type safety 
    - manual memory management
    - no classes to keep track of how many bytes things are 
- NULL pointer means you can't use pointer
    - ``` int *pi = 0; 
    double *pd = NULL; ```
    - If it's a null pointer you can't dereference
    - Every time you allocate a pointer without immediately giving it a value, make it a null pointer so nobody dereferences it (to avoid seg faults)
    ```int *f = 0``` 
    - Trying to dereference a null pointer will result in seg fault
    - **If you deallocate memory and the pointer still points to the same address, then it'll seg fault but look like a valid pointer. So by convention, we reset all deallocated/unallocated pointers to point to 0 so that we don't accidentally try to use that memory.**

### Arrays
- statically sized - cannot append to these 
- don't know how big they are. 
    - No function we can call to tell us how many positions in array are filled (no "len(list)")
    - sizeof will give you total number of bytes but not total occupied spots. 
- Every time we make a list, we have to keep track of how big it is and how many things it contains. 
```C 
sizeof(a) // an array of 10 integers will print sizeof(a[0]) * 4 = 40
```
### Lab 2
- Three buckets: 
    1. Recursion
    1. Arrays
    1. Introducing another sort (merge sort) + time complexity
- Part 1: implement selection sort
    - get rid of global variables! 
- Part 2: How to implement merge sort with recursion trace 
- Part 3: Performance check of part 2 (will go over next week) 
- Part 4: Complexity analysis

### Merge Sort Overview
- Time complexity: O(nlog_2(n)) 
    - each "step" is each comparison we do 
    - Each "level" costs us n
    - Given an array of n elements, we split it in half until we have only one element on either side
    - each computation takes log(n) so total time complexity is O(nlogn)
- How many times can you split an array of size n into k equal pieces means k^x = n, solve for x.  
