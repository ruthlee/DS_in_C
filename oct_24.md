# 10/24 Intro to C++ 

### Midterm Solutions
- Q1: 
    - time complexity is something like O(n log n), space is something like O(log n) - because you only have space complexity of inputs. 
- Q2:
    - could have just copied parts of code from hw
- Q3:
    - valgrind heap summary: 16 bytes (8 for double, 8 for pointer) in 1 block, 10 allocs, 9 frees, 160 bytes allocated, 1 error from 1 context (0 in 0 context is fine if you assume leaks aren't counted). 
- Q4: ``` char*, char*, int**, 24, invalid, int**, 8, '\0', 'b', char*, invalid, 'b', invalid (can't increment fixed size array)``` 
    - x is array of 3 pointers, y is a pointer to an array of size 3

### Why C++?
- Textbook: A tour of C++ 
- We want strings and objects. 
- Polymorphism: define a class, then create instances of that class
    - inheritance: class circle inherits features from class shape
- Generic programming (templates) 
- Exceptions
    - catch seg faults without crashing program
- containers: a vector is an enhanced array; queues, stacks, trees, hash maps, etc.
- Algorithms

### Our approach
- What makes C++ different from C
- How do we write correct and safe C++ code
- How does memory work in C++? 
- standard library essentials
- practical example-based approach
- will skip polymorphism (we will construct objects but without parent/child classes)
    - also exceptions
    - a lot of stuff

### Declaration vs Definition
- We can declare a function, we can declare a struct, class, template, etc. without actually saying what it is
    - say it exists without allocating any space for it. 
- We have pass by reference now. 
```C++
void swap(int &x, int &y){
// ampersand means int reference type. It means that we actually just give it the thing from the outside
    int temp = x;
    x = y;
    y = x;
}
```
