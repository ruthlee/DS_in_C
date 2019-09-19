# 9/19/20

### Program structure
- Know about heap and stack
- Automatic allocations happen on stack, manual on heap 
    - this will be important when we talk about allocating memory ourselves

### Recursion
- Something which is defined in terms of itself
- If problem can be categorized as recurrence relation + base case 
- Example in Python (factorial):
    - f(n) = n * f(n-1) is recurrence
    - f(n) = 1 is base case
```Python
def fact(n):
    if(n == 1): # base case
        return 1
    return n * fact(n-1)
```
- for python, name of the function is in scope. As soon as I write function, it knows function. Python doesn't need to know the rest of the function to execute it
- for C there is a compilation step and some kind of forward declaration 
- When the function is executed, it's like a loop within a loop within a loop
    - When factorial is called, get a local variable n. When it's called again, you get another local n within a new scope (nested factorial functions) 
    - in a lower level, you jump to new routine, but you're still within the stack so some sense of "order" is preserved
- Need base case to stop an infinite loop from happening 

- In C, don't need to "forward declare" function or variable types. C will read line by line and knows function when you call it within the code
