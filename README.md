# Compiler to MIXAL

## Introduction
This is a compiler from a simple c-like language to the symbolic language of the MIX computer from the book "The Art of Computer Programming", written by D.Knuth, called MIXAL. The project is broken down to six main stages, lexical, syntax and semantic analysis, then error finding and recovery and finally production to goal language.
All tools and files, both source and test, must be in the same directory for the following instruction to work.

## Lexical Analysis
In this language variables and methods can be named with a combination of digits, letters and underscores, but they need to start with a letter.
The tool **flex** is used in combination with the lex.l file to generate tokens to pass to the syntax analysis.
In order to do the above and create the *lex.yy.c*, which is our lexer, just type the following:
<pre>```sh flex lex.l```</pre>

## Syntax Analysis
Now that we have converted the *.txt* file to tokens we can continue with integrating the context-free grammar rules. The rules can be seen in the *syd.y* file which also creates the nodes for the Abstract Syntax Tree, also known as AST, that is incredibly important to continue.
In order to create our parser, the *syd.tab.c* file we can use **bison**:
<pre>```sh bison -dv syd.y```</pre>
Every program must have zero or more methods and the only type supported is signed int. All methods must return an **int** and can have zero or more parameters. Variables can me assigned a value when declared or later.

## Semantic Analysis
Semantic analysis takes place in the same file as syntax analysis and adds more rules for the language. A *break* statement stops the innermost loop in which it is in. All statements in conditions that are evaluated to be non-zero are considered **true**, while those that evaluate to zero are considered **false**. Declarations must be in the beginning of a method and method overloading isn't supported. Lastly, every program must have a **main** method.

## Error Finding
If a program doesn't comply to the rules above then an appropriate message should be printed in the terminal and the AST will not be built. For this purpose, the *error* token is used in our grammar and in specific rules. The error types are "Lexical", "Syntax", and "Semantic" and contain a message and a location near which the error is found. There is also a runtime error that is only seen when there is a division with a variable and not a constant that has the value of zero. However, this only outputs division by zero and doesn't show where it was found at.

## Error Recovery
This is used in order to find as many errors as possible in one take. The function used is *yyerrok()* which returns the compiler to its normal state after encountering an error. Sometimes, when an error is found, some of the next errors displayed are fixed with fixing the first one.

## Goal Language
MIX's Assembly Language, called MIXAL, has basic instructions and is easy to understand for someone with assembly expirience. The main file which converts the given *.txt* file to a *.mixal* file is *syd1.c*. This file prints the AST if there are no errors and uses it in order to generate an equivalent program as the one in the beggining but in MIXAL. The mixal assembler **mixasm** then can convert the *output.mixal* file we created to an object file, *output.mix*, which is then loaded and executed on a simulated MIX machine by the mix virtual machine **mixv**.

## Creating the Executable
In order to create and test the compiler we do the following:
<pre>```sh gcc syd.tab.c lex.yy.c syd1.c zyywrap.c```</pre>
*zyywrap.c* and *syd2.y* contain helper functions that are essential for our compiler to work.
Now we have created the executable *a.exe* which is the compiler.
To test for example with file *test7.txt* we can:
<pre>```sh ./a.exe < test7.txt```</pre>
If there are no errors, the AST of *test7.txt* is displayed and if we check the contents of *output.mixal* we can see an equivelant program but in MIXAL. Now to see the result:
<pre>```sh mixasm output.mixal```</pre>
<pre>```sh mixvm output.mix```</pre>
<pre>```sh MIX> run```</pre>
<pre>```sh MIX> preg```</pre>
And now we see the contents of the rA register of the MIX computer which is meant to have our result.

## Tests
<pre>``` text This is text ```</pre>

## Requirements
The versions of the tools used are listed below:
flex 2.6.4
bison++ 1.21.9-1
gcc (Debian 14.2.0-19) 14.2.0
mixasm GNU MDK 1.3.0
mixvm GNU MDK 1.3.0
