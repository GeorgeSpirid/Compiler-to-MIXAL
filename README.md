# C-like Compiler to MIXAL

## Introduction
This project implemets a compiler for a simple c-like language to the MIX Assembly Language (MIXAL), from D.Knuth's *The Art of Computer Programming*.
The compiler is divided into sixe stages:
1. Lexical Analysis
2. Syntax Analysis
3. Semantic Analysis
4. Error Detection
5. Error Recovery
6. Code Generation
All source, helper, and test files should be in the same directory for the instructions to work.

## Lexical Analysis
- **Identifiers**: variables and methods must start with a letter, followed by letters, digits, or underscores.
- **Tool**: *flex* is used with *lex.l* to generate tokens for syntax analysis.
To generate the lexer, *lex.yy.c*:
```sh flex lex.l```

## Syntax Analysis
The context-free grammar is defined in *syd.y* and uses *bison* to produce an Abstract Syntax Tree (AST), which is the backbone for later stages.
To build the parser, *syd.tab.c* and *syd.tab.h*:
```sh bison -dv syd.y```
**Language Rules**:
- Programs consist of zero or more methods.
- Only type supported is signed *int*.
- All nethods must return *int*.
- Methods can have zero or more parameters.
- Variabled can be initialized at declaration or later.

## Semantic Analysis
Performed in the same file with the syntax analysys, *syd.y*.
**Rules**:
- *break* terminates the innermost loop.
- In conditions, any non-zero expression is *true* and zero expressions are *false*.
- Declarations must appear at the beginning of a method.
- Method overloading isn't supported.
- Every program must have a *main* method.

## Error Handling
**Error Types**:
- Lexical - invalid tokens.
- Syntax - violating the grammar.
- Semantic - invalid program meaning.
- Runtime - only division by zero variable is detected at runtime.
The message printed gives information about the location and type of the error. If there is one or more errors the AST won't be built. The *error* token is used in some rules to handle expected errors.

## Error Recovery
Uses *yyerrok()* to recover and continue parsing. Multiple errors can be detected in a signle run and can sometimes be resolved by handling the first one. This happens because some following errors are side effects or previous ones.

## Goal Language
Implemented in *syd1.c*. If no errors are found then the AST is printed and *output.mixal* contains a MIXAL program equivalent to the *.txt* one.
The MIXAL assembler, **mixasm**, then creates an object file, *.mix*, and the MIX Virtual Machine, **mixvm**, loads it and executes it.

## Building the Compiler
In order to create and test the compiler we do the following:
<pre>gcc syd.tab.c lex.yy.c syd1.c zyywrap.c</pre>
*zyywrap.c* and *syd2.y* contain helper functions that are essential for our compiler to work.
Now we have created the executable *a* which is the compiler.
To test for example with file *test7.txt* we can:
<pre>./a.out < test7.txt</pre>
If there are no errors, the AST of *test7.txt* is displayed and if we check the contents of *output.mixal* we can see an equivelant program but in MIXAL. Now to see the result:
```sh
mixasm output.mixal
mixvm output.mix
MIX> run
MIX> preg
```
And now we see the contents of the rA register of the MIX computer which is meant to have our result.

## Tests
These are some of the test cases and their results.

**test2.txt**
```c
int method1(int a)
{
int b;
b = ((a+10)-10)*5)/5;
return b;
}
int main()
{
int a=5;
return method1(a);
}

Result: 
|Syntax Error| in line 4 col 19: parse error
There were 1 errors. No code generated.

```
**test3.txt**
```c
int method1(int a)
{
int b;
b=0;
while( a>0)
{
b = (a+10);
a = (a-1);
break;
}
return b;
}
int main()
{
return method1(5);
}

Result:
rA: + 00 00 00 00 15 (0000000015)
```
**test5.txt**
```c
int method1(int a)
{
int b;
b = a+10;
return b;
}
int method2(int c, int d)
{
int e;
e = method1(c);
e = e + d;
return e;
}
int main()
{
return method2(5,6);
}

Result:
rA: + 00 00 00 00 21 (0000000021)
```
**test6.txt**
```c
iint method1(int a)
{
int d=1;
int e=0;
int h=d/e;
int b;
int b;
b=0;
c=1;
while( a>0)
{
b = (a+10);
a = (a-1);
break;
}
break;
return b;
}
int method2(int c, int d)
{
int e;
e = method1(c);
e = e + d;
}
int a=1;
int main()
{
int a=01;
&
// comment
method3();
return method1(5,1);
int d=1;
}

Result:
|Semantic Error| in line 7 col 7: redeclaring variable (near b)
|Semantic Error| in line 9 col 2: variable not found in method (near c)
|Semantic Error| in line 16 col 7: break outside of loop
|Semantic Error| in line 24 col 2: method doesn't have return value (near method2)
|Semantic Error| in line 25 col 9: declaring variable outside of a method (near a)
|Semantic Error| in line 25 col 9: looking for a variable outside a method (near a)
|Syntax Error| in line 26 col 4: parse error
|Lexical Error| in line 28 col 9: number cannot start with zero (near 01)
|Lexical Error| in line 29 col 2: illegal character (near &)
|Syntax Error| in line 31 col 8: only methods allowed at the top level
|Syntax Error| in line 31 col 9: parse error
|Syntax Error| in line 31 col 9: program must have only methods
|Syntax Error| in line 31 col 10: parse error
|Syntax Error| in line 31 col 10: program must have only methods
|Syntax Error| in line 31 col 11: parse error
|Syntax Error| in line 32 col 7: only methods allowed at the top level
|Syntax Error| in line 32 col 15: parse error
|Syntax Error| in line 32 col 15: program must have only methods
|Syntax Error| in line 32 col 16: parse error
|Syntax Error| in line 32 col 16: program must have only methods
|Syntax Error| in line 32 col 17: parse error
|Syntax Error| in line 32 col 17: program must have only methods
|Syntax Error| in line 32 col 18: parse error
|Syntax Error| in line 32 col 18: program must have only methods
|Syntax Error| in line 32 col 19: parse error
|Syntax Error| in line 32 col 19: program must have only methods
|Syntax Error| in line 32 col 20: parse error
|Syntax Error| in line 32 col 20: program must have only methods
|Syntax Error| in line 32 col 21: parse error
|Syntax Error| in line 33 col 4: only methods allowed at the top level
|Syntax Error| in line 33 col 6: parse error
|Syntax Error| in line 33 col 6: program must have only methods
|Syntax Error| in line 33 col 7: parse error
|Syntax Error| in line 33 col 7: program must have only methods
|Syntax Error| in line 33 col 8: parse error
|Syntax Error| in line 33 col 8: program must have only methods
|Syntax Error| in line 33 col 9: parse error
|Syntax Error| in line 34 col 2: only methods allowed at the top level
|Syntax Error| in line 36 col 1: need to have main method
There were 39 errors. No code generated.
```
**test7.txt**
```c
int method1(int a,int b){
    return a+b;
}
int method2(int a,int b,int c){
    int d=method1(1,2);
    int e=0;
    return d/e+b+c;
}
int main() {
    int c=5;
    int a=method2(c,2,3);
    return a+method1(1,2);
} 

Result:
RUNTIME ERROR: DIVISION BY ZERO 
```

## Final Notes
The name of a variable plus the name of the method it is in cannot be more than 10 characters combined, e.x.
variable called "name" in method called "findName" is too big and therefor invalid.
The project was mostly developed in Notepad with some use of Visual Studio Code.

## Requirements
The versions of the tools used are listed below:
- flex 2.6.4
- bison++ 1.21.9-1
- gcc (Debian 14.2.0-19) 14.2.0
- mixasm GNU MDK 1.3.0
- mixvm GNU MDK 1.3.0
