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

