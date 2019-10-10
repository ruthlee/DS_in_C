# Oct 10: Linked Lists (continued)

### Going over Linked List Sample Code
- prepend: allocate memory, fix arrows
- ```while(node)``` means while this pointer actually points to data and is not null
- only seg fault when you dereference a null pointer, if you ```node = node->next``` inside the while loop, it shouldn't seg fault
- Memory allocated within a function or with function arguments go away after the braces go away. 
- lldb can set breakpoints
    - ```p [variable name]``` prints a variable (can be a pointer). 
    - ```n``` is next
- prepending on linked lists is O(1). Prepending on an array is O(n). 
    - if we had a tail pointer, appending would be O(1). 
- In general, data structures are about figuring out how to optimize for the access patterns we want
    - linked lists are good for things which are expanding/contracting
    - arrays are good for changing stuff.
    - figure out use cases
- Can iterate through a linked list by using ```while(node)``` or ```if(list) thnen recursively apply something```
- no need to put an ampersand in front of function because address of function and function themselves are the same thing
    - function itself is an address
- Deallocating: stash the node in a temporary variable, then free the node. When empty you should just have a null pointer.

```C
if (list) {
    do something
    call function on list->next
    }
// recursive iteration

while(list) {
do something
list->next
}

while(list && list->next) //will stop us one node before the end
```

- calling ```return;``` on a void function kicks you out of the function. 

### Linked list 2 program
- ```assert()``` means assume it's true and if what we want doesn't happen crash the program. 
    - assert is a sanity check
- Remove node is p complicated, check it out over the weekend
    - need to actually modify list in order to remove nodes bc it returns a 0 or 1, not the list itself. We can't return both the list and the 0 and 1. 
    - If we give the function the address of the variable, then we can actually modify the list and still return the 0 or 1. 
