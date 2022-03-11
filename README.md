# markov
This is a small implementation of a Markov algorithm language written in C++, Markov algorithms are essentially string manipulation rules which consist of a left hand side (pattern) and a right hand side. When a rule is applied to a string, if the pattern is found one or more times in the string, the _first_ occurence of the pattern is replaced with the right hand side expression.

The rules are scanned from top to bottom, when no applicable rule is found the execution ends and the final string is produced as output.

## Use 

At this stage the language supports 2 types of statements: rules of type
```
lhs := rhs
```
and _one single_ input string (this is simply represented by a string without the := token)
Whitespace at the beginning and end of the rhs and lhs expression is removes, whitespace in the input string is not. For the same reason it's best to have no lines containing only whitespace or they will be consider inputs

## Examples
The algorithm below (contained in bin_test.txt) will transform the binary number passed as input into a string containing a number of '|' chars equal to the decimal representation of the number
```
|0 := 0||
1 := 0|
0 := 

11110
```
This algorithm will add 1 to a binary number passed as input (enclosed in underscores)
```
1_:= 1++
0_ := 1
01++ := 10
11++ := 1++0
_0 := _
_1++ := 10
__ := 1

_1111111111_
```

