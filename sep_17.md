# 9/17/19 

### Data Types (cont)
- Mapping between what value is stored in memory and what value is actually shown is different
```Python
ord(x) 
97

ord('0')
48

ord('0')
0

print('\0')

```
- No classes

```C

int x;
int y;
x = (y = 4);
```
- Whatever value of expression y=4 is is what x will take
```C
x = i++;
x = ++i;
```
- indents/whitespace don't mean anything in C
    - make sure to use curly braces for if-else statements! 
- no global variable/ static variable stuff. Don't use it! 
- Scoping will be tested and it will cause bugs


