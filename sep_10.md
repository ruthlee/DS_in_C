## 9/10/2019 Class

LAST CLASS- We compile to get the .o file, and link to get the executable (a.out)
- Everything is statically typed - must specify type of every variable (e.g., ```int```)
- We call other functions from ```main()```
- C is NOT pass by reference, C is pass by value i
- ```vsplit FILE``` and ```split FILE``` in vim seems useful

Style Notes
- Four spaces, NOT tab
- not next line curly praces
- curly braces on single line statements 

### Today: Makefile with add program
- we can define functions above main before using them i
- BUT we can also split up functions into programs 
- need a way of telling ```main()``` about the ```add()``` function 
- ```#include "myadd.h"``` means pre-processer copies all the contents of myadd.h into the file before compiling (like importing a library)
- ```#include <folder/file>```
- in C, every function is global and can't have duplicates. 
- header file tells us of existance of function without duplicating into .o files. When we go to link .o files together, one of those has to have implementation for the make to work. 

COMPILING AND HEADERS
- ```gcc -c main.c```
- ```gcc -c myadd.c```
- ```gcc myadd.o main.o``` order here for linkage doesn't matter
- if you don't link and compile like this (for example, directly trying to compile main.o, then it won't compile because it doesn't have the add file)
- if you make changes to main, don't need to re-compile all of the functions from the header. 
- just need to recompile things with errors, then re-link (not recompile everything)
- write functions in ```myadd.c```, put them in ```myadd.h``` to use in ```main()```
- GUARDS on .h file: ex, ```#infndef __MYADD_H__``` means "if this special variable, "myadd.h" is not defined, then define it using ```#define __MYADD_H__``` with these specific functions. ```#endif```. Guards prevent us from having more than one declaration. In future language, this is replaced by ```pragma_one``` 
    - ```__NAME_H__```
    - Should be the same header format for everything. 
    - ```#define PI 3.14``` is a preprocessor variable. Goes through code and does a find a replace at the beginning. So for example if we write a variable called ```aPIb``` then we'll replace it with ```a3.14b``` which would be a syntax error. It's all string based, so "3.14" is a string.

Structure of Code
- We want a ```main.c``` file, and a bunch of other files (in lab1, ```calculator.c``` will contain main, tokenize might have input) 

MAKEFILE
- We want to be able to type one thing and have our entire program built.
- We want it to know the dependencies/order of our compilation files 
- We have targets on left, dependecies on right. ex. ```main.o: main.c myadd.h``` main is the target, dependencies are main and myadd
- ```-Wall``` means we see all warnings (required tag)
- make sure to ```clean: blah blah``` to delete the .o intermediary files
- ```touch FILE``` will simulate editing file so you can see what rebuilds when you call ```make``` 
- ```CFLAGS=-g -WALL``` means that if you put ```$(CFLAGS)``` then it'll automatically put in those two flags. 
- ```$(CC)``` replaces the compiling command, which should be ```gcc```
- ```TARGET``` is main, just in case we want to change the main program name. i
- MAKE SURE dependencies are correct. If ```myadd.c``` changes, don't have to necessarily change ```main.c```. Dependencies are the file itself plus any header files. Every target will have one ```.c``` dependency and all the headers within it.
- Will probably have to write a makefile from scratch for exams.

GETTING STARTED ON LAB1
- can clone ```sample-code``` for class sample code
- when submitting lab, try to build and run the code and see if it works within the timestamp folder. 
    - git status should be clean when you submit. 
