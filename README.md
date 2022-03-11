# markov
This is a small implementation of a Markov algorithm language written in C++, Markov algorithms are essentially string manipulation rules which consist of a left hand side (pattern) and a right hand side. When a rule is applied to a string, if the pattern is found one or more times in the string, the _first_ occurence of the pattern is replaced with the right hand side expression.

The rules are scanned from top to bottom, when no applicable rule is found the execution ends and the final string is produced as output.

## Use 

At this stage the language supports 2 types of statements: rules of type
```
lhs := rhs
```
and _one single_ input string (this is simply represented by a string without the := token)
Whitespace at the beginning and end of the rhs and lhs expression is removes, whitespace in the input string is not.

## Examples

```
|0 := 0||
1 := 0|
0 := 

11110
```

