# 11/7 Class: C++ (Part 3)

### Basic 4
- default construction, destruction, copy construction, copy assignment(?) 
- Pass by reference
- Constructor = allocate value of pointer, destructor = deallocate
    - automatic memory management 
- Can write stuff to automatically deallocate functions that are not in use

### MyString 
- const means that we don't expose stuff to outside programmers
- friend: you want function to be able to touch the private aspects of a class
    - we can write the operator as a global function, available everywhere, that says how we can add two MyStrings. 
- If we write ```x+y``` operator is looking for ```x.operator+(y)``` or ```operator+(x,y)```
    - ```MyString MyString::operator+(const MyString& rhs);```
    - ```MyString operator+(const MyString&, const MyString&);```
- If something has to be const, can't modify it. 
    - const is infectious. If something is looking for const argument, it has to be const. 
- Inside header function, if you write a function within a class structure, it is a method
    - if you overload a binary operator with one argument, it'll be a method. 
    - if you have two arguments, operator will be global function (not a method) - exception for operators. 
    -  KNOW DIFFERENCE BETWEEN single arg and double arg operators. 
        - we want it to be a method or a friend to access private stuff sometimes
- Must return a reference to this - ```*this```
- Stream operators are bitshift operators
    - utilities for taking an object from user input/terminal and turning it into a string 
- operator[]: example of casting away const-ness ```((MyString&)*this)[i]``` dereference to const MyString and then recast. 
    - non-const version is for assignment.```x[4] = 'a';``` 
    - Reading the value is for const version. ```char z = x[4];```

### HW4
- Changing arguments to references saves on calls (part 2 of part 1)
- elide flag tells compiler we can be less safe 
    - optimization flags

### Nonlinear data structures
- Binary tree: every node has 0, 1, or 2 children 
    - expression trees
- Tree representation of doing a binary search. 
