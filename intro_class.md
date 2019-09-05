## Class 1: 9/3/2019 and Class 2: 9/5/2019

Note for vim: to start code use the block code syntax. Three backwards quotes with the language indicated. Example: 

```C
int main()
{
    printf("hello world");
}
```

### History/Basic Info
- Language specifications of C = C[year] (i.e., C99, C89)
- Python runs on C
- gcc = C compiler, one of the most popular/original C compilers 
- Macs also have LVM compiler called Clang
- UNIX is a specification for OS 
- LINUX emulates UNIX system (LINUX = set of tools which emulate UNIX environments) 

### Useful Info
- In CLOC, home directory is \students 
- ```man [bash command]``` gives manual for command
- ```ls -l``` folder info
- alias in the /.bash_profile to shortcut commands ```alias cloc = sshblahblah```
- will set up alias in mutt
- ```rm -r [dir]``` will remove a directory
- ```clear``` or ctl-l will control history
- ```exit``` or ```logout``` will log out of cloc
- if stuck in infinite loop, break with CTL-C. 

### Hello, World!
- Executable needs ```.\a.out``` in order to locate the file. 
- ```%s``` for string, ```%d``` for integer(?)
- ``` printf("%s %d\n", "String", 4)```
- only one main function in program (entry program into executable)
- return 0 to let operating system know that "everything is cool" (if program worked, can run ```echo $?``` to see if it returned correctly)
- ```man printf``` works
- ```# one line comment```
- ```/* multi line comment */```

### Compiling
- compiling turns my code into a binary asset (```a.out```) which is an executable 
- basic idea is that if we compile things seperately for different tasks we can string them together into one big executable for big projects
- gcc command reads syntax, turns it into commands for computer, turns into ```hello.o```
- After compiling, we link by doing ```gcc hello.o``` which makes ```a.out```. Compile and link separately so you can compile one thing among many files instead of all of them every time.
- ```gcc -c -g -Wall hello.c``` not sure what this does but looked interesting
- ```gcc -o hello hello.o``` changes name of executable
- ```gcc -c hello.c``` will just compile and make the ```hello.o```, compile with ```gcc hello.o```

