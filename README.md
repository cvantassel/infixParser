# infixParser


This parses infix expressions.

Project 1A
• Using stacks, write an infix expression parser. Here are a few
examples of expressions your program should parse and evaluate:

Expression     Result
1+2*3              7
2+2^2*3            14
1==2               0
//or false if the type is bool
1+3 > 2            1
// or true if the type is bool
(4>=4) && 0        0
//or false if the type is bool
(1+2)*3            9
++++2-5*(3^2)      -41
Technical Requirements
•
(Weight: 20%)
Your parser should parse an infix expression that s
upports the following
arithmetic and logical operators with the specified
 precedencies:
Operator
Precedence
Example
!
//
logical
not
8              ! 1
// = 0 (false)
++
//
prefix
increment
8              ++2
//3
--
//
prefix decrement
8              --2
//1
-
//
negative
8              -1
//-1
^
//
power
7              2^3
// 8
*, /, %
//arithmetic
6              6 * 2
// 12
+, -
//arithmetic
5              6 – 2
//4
>, >=, <, <=
//comparison
4              6 > 5
// 1(true)
==, !=
//equality comparison
3              6!=5
// 1(true)
&&
//logical
and
2              6>5 && 4>5
//0(false)
||
//logical OR
1 1 || 0//1 (true)

• (Weight: 30%) Parse an expression given in a string format. Your
program should be flexible with
the given expressions. For instance, 1+2 is the sam
e as 1 + 2. The user should not worry about
writing the spaces between operands and operators.

• (Weight: 20%) Your program should check for invalid expressions,
and produce meaningful error messages when necessary. Further, the error message should indicate whether the error
happened (Only report the first error the program encounters and exits the program).

Here are a few examples:
What the user enters
Error message
)3+2
Expression can’t start with a closing parenthesis @
 char: 0
<3+2
Expression can’t start with a
binary operator @ char: 0
3&&&& 5
Two binary operators in a row @ char 3
15+3 2
Two operands in a row @ char 5
10+ ++<3
A unary operand can’t be followed by a binary opera
tor @ char 6
1/0
Division by zero @ char 2
• (Weight: 30%) Evaluate the given expressions efficiently.


Facts and Assumptions

• You may assume that all operands are integers. The
result of a comparison is a boolean (e.g.
6==6 is true). However, C++ compiler allows a boole
an can be converted to an integer according
to this logic: true =1 and false = 0. An integer ca
n be converted to a boolean according to this
logic: a number that is equal to 0 is false. Otherw
ise, it is true.
• You can be inspired by the postfix evaluator as wel
l as the infix to postfix convertor that we have
studied in class (the source code is on Blackboard)
. However, make sure you come up with an
efficient algorithm.
• You may just call the evaluate function in the main
 function. There is no need for getting input
from the user or a menu-based system. For instance,
 this is an example of how the evaluator is
used in the main fun