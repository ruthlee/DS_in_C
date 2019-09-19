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
- Factorial becomes wrong after about 20! because we only have 64 bits (so we have overflow error) 

### Time Complexity
- Which algorithm is better: recursive factorial or explicit factorial? 
- Time complexity = how fast? Space complexity = how much memory? 
    - Think of a graph where input size (n) is on x- axis and # of steps is on y axis 
    - linear growth, squared growth, log growth, etc. 
- Calculate number of steps and don't take into account coefficients 
- Big-O notation: 3n + 5 calculation = O(n)

### Time complexity of factorial algorithm
- Look for loops and recursions as indicators of complexity
- Time complexity for both algorithms above is O(n)

- * Note: Pythonic behavior means don't return something in an else. Can just return at the end *

- Space complexity: faster algorithm might require more space
    - We count variables, not steps (one variable is one block of memory)
    - recursion: we have n variables. When we call factorial within factorial, we call it again. And again. For n times.  
    - explicit: we have two variables
    - Recursive algorithm is worse in terms of space complexity. (generally true) 
- *Reminder: n = 1, x = (n--); n is equal to the old value of n *
    - *x = (--n); n is equal to the new value of x (0)*
    - *in both cases, x = 0.*
- **Three rules for writing recursive functions:
    1. Well-behaved basis
    2. Induction goes towards the basis
    3. Have faith- believe f(n-1), check the rest. **

- Factorial time complexity is the worst you could possibly have. 
