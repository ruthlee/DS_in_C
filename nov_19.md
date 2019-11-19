# 11/19: BST and Templates

### BST (cont)
- helper class (BSTNode) is a friend which helps BST class be more user friendly

### Templates
- A way to generalize functions across types. 
- Can template-ize classes
- Not type-less programming, but generic programming. 
- Template specialization: implement version of template for a class which doesn't necessarily fit with the generic template 

## Examples of template classes in std: 

### Vector class in standard library
- Appending to vector is O(1) 
- support index operator ```v[1]```
- can have vector of vectors
- Additions and removals are O(n). 

### String class
- Is a template too! 

### Deque = double-ended queue
- similar to vector but have efficient inserting and removal
- Circular array

### Lists 
- Doubly linked list 
- no random access with bracket operators

### Upshot
- If I have a generic template data structure, then I can write generic algorithms that will work with all data types given the template classes. 

### Iterators
- Custom classes defined within templatized classes 
- you can get references with const iterator (if you're just reading)
    - if you're writing you can't use const
- They are pointers under the hood
```v.begin()```
```v.end()```
- Both of these are examples of iterators
    - v can be a vector, tree, list, whatever
- ```auto``` type means that it takes the type of the return value of the thing (ok bc statically typed) 
- You can also use ```:``` which means the same thing as "in" in Python
- Can use ```++``` operator on iterators naturally no matter what the data type (so it'll automatically do ```node->next``` or ```v[i+1]``` as needed
