# 10/3/19: Graphs and Lab 6

### Logistics
- Recitation this Friday and next Friday. 
- Lab 5 grades will be out before exams. 

### Graphs
- DFS and BFS can be implemented iteratively
    - stacks and queques 
- Lab 6: not root, but rows and columns. 
    - int row and int column. 
- Changing the pop fronts and push backs turns DFS <=> BFS 
- Reference vectors mean that space complexity for these are constant (no need to copy memory) 
    - recursive versions become a lot better. 
- DFS/BFS is brute force algorithm: must look at every node. 
- Time complexity: O(V+E) for both 
    - must do it in terms of V and E. 

### Lab 6
- MAZE_SPACE is visit log- we check if the key is pressed and we can move, then do something. 
- When maze vector is initialized, the entire thing is pound signs, and the maze is "dug" out. 

```C++
// after arrow key if statements
if (key == 'a'){
    // solve_maze(m, row, col); // ref for m is really important so you actually modify the maze object.
    while((key=getch()) != 'q') {}
    break;
}

if (key == 'f'){
    // flood_maze(m, row, col);
    while((key=getch()) != 'q') {}
    break;

}
```
- flood_maze is implement BFS (iteratively if you want)
    - solve_maze is implement dfs (recursively if you want)

```C++
void flood_maze(vector< vector<char> >& maze, int row, int col) {
    deque<pair<int, int> >d;
    d.push_back(pair<int, int>(row, col));
}

int solve_maze(vector< vector<char> >& maze, int row, int col) {
    \\ implement dfs

    \\ try north
    if(solve_maze(north...){
        return 1;
    }
    else if(solve_maze(south...){
        return 1;
    }
    ... 
    ...
    return 0;
    \\ after we recurse all the way down, we don't have to go all the way up. 
}
```

- How do you get dude to walk back? 
    - if you do DFS recursively, if it's print-recurse-print, it prints as you walk down call state
    - if it's recurse-print, go all the way down and print going back up. 
    - print-recurse(DFS)-print means we see the dude move down. As you walk back up if you print again then you'll see dude move back up. 
    - for solve maze will print dude twice, once before and once after to print
- start with flood maze (it's easier)
- every time you print to screen, do ```mvaddch(row, col, MAZE_DUDE);``` to just PRINT something to the screen (not to actually modify maze)
    - need to pause 100 ms after each move with usleep(DELAY) - put these into DFS/BFS algos with a header that i can google 
- Modifiers + bitwise or
    - mvaddch takes row, col, and a character with modifiers 
    - the other attributes are binary "flags" which modify the chars
        - examples: highlight, blink, etc. 
        - These are options 
    - so instead of thinking of it as 8-bit integer and a bunch of flags, we can treat integer as boolean and just have 32 booleans
    - so if we have 8 possible options, we have an 8x8 diagonal matrix where each row is one-hot encoding an option
    - If we want to turn on options 1, 3, and 8, we use bitwise OR: option 1 | option 3 | option 5
    - if(options & option 1 == 1) is true if option 1 is turned on. If not, option 1 is off. 
    - turn them on by | (OR), turn them off by & (AND) 
```mvaddch(row, col, MAZE_TRACE | A_BOLD | A_BLINK);```
- Will have to modify one of the characters with bitwise OR 
