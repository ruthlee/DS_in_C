# Oct 29 Notes - C++ Intro Part 2

## Review
### Why C?
- We need string objects
- User defined-types, classes, polymorphisms

### Declaration vs Definition
- Delcare stuff before defining
- Definition actually allocates memory

## C++ 
- instead of malloc and free, we have new and delete in C++ 

###Object Oriented Language
- A constructor goes from the blueprint of the class (house) to the actual instance of the class (house). 
    - classes have attributes (number of rooms, colors, etc.) 
    - instance of class has values which are bound to it
    - has methods which are bound to it (we may want to "paint the house") - we can call paint method, and modify that house's color without modifying the color of any other house instance.
- A vector in C++ is an array which expands for us so we don't have to do memory management
    - each instantiation of a vector has its own methods which modify that vector as we want it (ex. append) and leaves the other vectors alone. 
- overloading means redefining operators like + for two instances of a class
- inheritance: classes can inherit methods from superclasses and have new methods which are defined on it. Can also overload methods from superclass. 
- polymorphism: we can use different classes (scalene/isoceles triangles) can use methods written for a more generic class (triangle)- generic reuse 

### C++ Constructor/ Destructor
- Two special methods for a class 
- Constructor is a special function which lets us build a class into an object
- When the object goes out of scope, we destroy it. 
- If we allocate memory for object on the heap, then with the "delete" method we deallocate with the destructor
    - methods are functions which are defined on classes which you call on objects
- in Python its ```__init__``` and something else
    - in C++ we have something else
- How can we assign instance into another instance?
- if class is allocated on heap, must use new and delete. 

### Allocation of objects in C++
- Can stack allocate objects or heap allocate objects
- reference operator ```String& r3 = s3``` means that ```r3=s3```. 
    - easy way for two variables to refer to the same data
    - before we needed to allocate two separate buckets of memory with same variable in C. 
    - DIFFERENT from unary de-reference operator ```String *p3 = &s3;```. Unary de-reference is applied to one variable. Reference is in the type name. Same as difference between unary * and *. 
- delete array of objects write like this: ```delete[] a1;```

### C++ Basic 4
- Constructor: special method which tells you how to go from class to instance of class
    - default constructor = constructor with no arguments; what happens when you declare a new object
    - properly allocate all memory needed and base classes
- Destructor: deallocates all buffers/memory (delete if on heap)
- Copy constructor: copy an existing instance of class
- Copy assignment: instance of class = another instance of class
- Auto-generated stuff exists, but won't do what you want. 
    - memory leak if you don't implement your own constructor/destructor

### MyString Class
- headers, cpp files
    - class definitions are in header files
    - certain methods in header, others in cpp file. 
- compiler: ```g++``` not ```gcc``` 
- from cout, stream cs, then stream comma, then stream ... ```cout << s1 << ", " << s2``` 
    - this will output s1, s2
- ```using namespace std;``` using standard namespace
    - so we can write functions which aren't in global scope (functions defined in namespace) e.x., math.sqrt and numpy.sqrt is okay.
- public means anyone instantiating class can call
    - private means only maker can control (e.g., attributes can be internal) 
        - methods only accessible from body of class
    - getters = all attributes are private, can get them with a getter (copies out value) 
    - setter = function which lets you set an attribute but you can't set it to things which are bad. 
- Compiler is smart enough to know that constructor doesn't need to be prefaced by type
- ```const``` keyword means method is constant; method doesn't modify object  
    - constant reference to character means you can't modify the character. 
- ```operator=``` or ```operator+``` means overloading operator (can't make new syntactic constructs, but can overload existing things in C syntax)
- must define basic four methods, then can implement other methods (small ones can be implemented in header)
- two different operators for []
