# 9/12/2019 Lecture 2 

### Lab1 Overview
- Part 1: write function that calculates prime, write function which calculates gcd 
    - main asks user for input, calls prime and calls gcd
- tokenizer takes string of tokens and splits them up by tokens 

### Data Types in C
- ``` char <= short <= int <= long <= long long```
    - char = 1 byte
    - short = 2 bytes (we won't use them at all- useful if you're in a constrained number space- we have less space than integers)
    - int = traditional integer, 4 bytes long
    - long vs long long, C doesn't specify byte sizes
- to specify byte sizes, use ```int<N>_t``` types
    - e.g., ```int8_t``` or ```int16_t```
    - ```include <stdint.h>```
- everything is two's complement underneath
- variable declaration examples
    - ```int x = 4, y = 4;```
    - ```char c = 'x';``` must use single quotes
    - ```char c = '\n';```
    - ASCII table would show how things are actually stored
    - THIS IS IMPORTANT: ```char c = 0``` is the character zero (null character in ASCII), ```char c = '\0'``` the digit zero same as ```char c = 0;``` (this is character 0 vs value 0). 
    - ```long x = 0L;``` the L at the end means it's a long literal of 0 (not an integer) 
- conversion bw signed and unsigned preserves bit patterns 
    - potentially dangerous if you're comparing signed/unsigned numbers
    - putting integer in a long is okay. If I put a long into an integer, it won't be the same number at the end (won't fit)
- A float is four bytes, a double is 8 bytes 
- NO STRINGS in C. It only has chars and arrays of chars. 

### Expressions
- literals vs variables
    - literals is anywhere you see a value actually written
    - variables are placeholders/ aliases for data underneath 
- ```x = i++;``` vs ```x = ++i``` first one takes the value of i and increments it. Second case means i's value is incremented AND x's value is incremented 
- logical operators are doubled ```&&``` is AND and ```||``` is OR
- bitwise operators: ``` x = x * 2``` is the same as ```x *= 2``` or ```x = x << 1``` (bitshift)
    - example: 
```C
x = 10100
y = 01101

x ^ y

11001
```
Statements
```C
if(A) {
} else if (B) {
} else {
}

if (A)
    // statement
    x = 4; // only the x is in the if statement 
    y = 5;

if (A)
    x = 4;
    if (B)
        y = 5;
else
    x = 3; // WRONG: else binds to closes if in the absence of braces
```
- always use curly braces to avoid that last thing
- switches cascade, so always use breaks 

```C
while(expression {

}

do {

} while (expression) // difference: second does something before iteration; useful if you have to do something before evaluating all the other cases

for(initializer; expression; recursion){

}

for(int i = 0; i < list_length; ++i){
    continue; // whatever is left in the body of the loop ignore, jump to the next iteration of the loop and evaluate again
    break; // jump out of loop
}

# tag
LABEL:

# jump to a line number
goto LABEL;

AFTER_LOOP:
```
