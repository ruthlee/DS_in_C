# Oct 17: I/O

- 2017 (10=31) Q2 something like it will prob be on the midterm

### Midterm
- Definitely a recursion question
- Write code: logic more important, almost def about linked lists
- identify value or type of the thing he gives
    - pointers vs arrays, addressing, dereferences
    - strlen() vs sizeof()
- time/space complexity
- valgrind
    - memory errors/leaks
- makefile
- linked lists where you have to do loops on linked lists
- 2017-2019 are his exams 

### Standard I/O
- C standard library automatically provides every running programs with 3 I/O channels
    - stdin (incoming character stream from keyboard)
    - stdout (outgoing character stream to terminal, buffered)
        - buffered means that program can crash before the thing is actually printed out. 
    - sterr (outgoing char stream, unbuffered)

### Redirection
- ``` > ``` means stdin comes from file instead of terminal
- ``` <``` means stdout goes to file 
- double >> means append to file
- ```2>&1``` has stderr go to same place as stdout 
    - valgrind goes to stderr, output of program is stdout. 
- A shell is the way to access operating system. 
- Bash shells are user interfaces for accessing operating system. 
    - "born again shell"
- programs are run in the shell. 
- ``` cat test1.txt | grep -n "HEAP"```
- ```|``` is a pipe which connects two commands; puts stdout of the previous command into stdin of next one. 
- ``` find -name "list1.h" | vim``` call vim on all of the outputs of the find command. 
- ```wc -l``` is word count

### Formatted I/O
- Buffer overflow means you write too much memory and override things in memory
    - ```scanf("%s", a);``` is dangerous. if you've only allocated $a[100]$ for instance
    - dangerous for security reasons
- It's possible to write functions in C which take variable number of arguments.

### Buffering
- flush capability means that we make the program write to the disk, regardless of whether it's unbuffered, line buffered, or block buffered. 

