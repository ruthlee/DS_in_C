# 9/24 Notes
#### Merge Sort, Lab 2 Walk Through

### Logistics
- Midterm questions will often be pulled from optional extra homeworks

### Review
- Recursive functions
    - Every time you call a function, you enter a new scope and you create new variables for that local scope
    - call stack implements things recursively 
- Recursive vs iterative complexity
    - same time complexity
    - recursive for factorial had worse space complexity (O(1) for iterative, O(n) for recursive) 
        - O(n) for factorial because a variable is called every time the function is called
- Recursive selection sort
    - Find smallest thing remaining, swap, repeat

```
for ith position and n elements;

    base case: i is the last element

    if there's more than 1 thing left in the list
        initialize smallest index = i
        for everything in the list
            if there's an element smaller than my small position
                assign small to that new index
            swap

        recursive call: move to the next position and repeat 
```
- complexity: 
    - Time: we're doing n iterations in inner loop, n in outer loop, so this is O(n^2)
    - Space: we have two variables per recursive call, and we're using same list for everything, so it's O(n) 

### Scope/ Space Problem
- C is a **pass-by value** language
- if swap is a function to swap a and b, and main defines x and y, prints them, calls swap(x, y), then prints again, then x and y will be the same x and y as before 
    - everything is an immutable type I guess
    - in this case x and y get copied into swap, not actually changed
    - same thing happens in recursive selection sort; every time we call the function, the previous values get copied into the new variable
    - No **pass by reference** means that something that happens within an inner scope will stay within that inner scope. 
- In iterative selsort, we defined a global variable of an array (NOT OKAY) to bypass space cocomplexity issue
- But is there a better way? 
- We want to modify variables outside of their scope
- In addition, we want functions to allocate memory so that we can return local variables out of the function 

### Pointers and Arrays
- Memory is big block of buckets, byte occupies one bucket, ints occupy 4 buckets, etc.
- If we create a variable, we are putting its value in a bucket
    - if it gets modified, the modified value is in the bucket.
    - Every bucket has an ID or an address
- A **pointer variable** allows us to modify stuff outside of a function

```C
int *p; \\ defines a pointer variable
```
- p is some alias to a bucket in memory, but the value is not an integer, it's an ID of another bucket. 

```C
p = &x \\ the address of the variable x
int *p = &x; \\ take the address of x and assign that address to p (* is part of a type)
char *p = &c; \\ taking the address of a char and assigning it to c
y = *p; \\ means follow the pointer to its underlying bucket and grab value (* is operator which will get the thing at address p)
*p = 0; \\ means we go to the address and put in 0 (setting the bucket)  
(*p)++; \\ need parenthesis; order of operations is right to left
```
- Pointers are typed
    - if I have address of char, I can only put chars in it; same for other types
    - this is so that the number of buckets we need to assign stays consistent.
    - type safety on pointer

```C
void *pv; \\ a generic pointer; can turn it into the type you need have to cast it before dereferencing
```
- Segmentation fault = you accessed memory that you weren't using and didn't plan to use
    - You never tried to allocated memory, program will die
    - You accessed a piece of memory and didn't reference it or tried to reference to a piece of memory that doesn't exist
- **NULL pointer**: we want to know whether something is a valid pointer or not
    - Means don't dereference this or you'll get a seg fault
    - Can init pointers as null and check if you can dereference it 
    - Ensure we don't have a seg fault if we dereference pointer by first making it a NULL pointer and getting a runtime error if we dereference

```C
char *q = 0;
if (*q) \\ crash! can't dereference null
```
- Can assign variables to address (pointer to an address) 
- Can get two levels away from an int by pointing to a pointer. 
```C
int *p = &x
int **q = &p
```
- Simulate pass by reference by returning addresses, not variables. 
    - if we return pointers, things will actually change 
    - if we pass in a pointer, we can actually change something in an outer scope 
    - Still call by value; addresses are the things which are passed by value

### Arrays
```C
int a[10]; // 10 integers are declared in contiguous memory, from 0th to 9th
a[0] = 100;
a[10] = 300; // will compile but will get some kind of error

// initialization:
int a[] = {100, 200, 300}
int b[10] = { 1 } // any skipped values initialize to 0. 
char c[] = "abc" // short-hand for char c[] = {'a', 'b', 'c', '\0'}; i.e., strings are arrays of characters
```
