1.1 Programming (General)

1.2 Programming Basics

The following statement gets an input value and puts that value into variable x: cin >> x; cin is short for characters in.

cin = "characters in"
cout = "characters out"
endl = "end line"
\n = newline character

On 1.3 Console Input


Good practice for fixing errors reported by the compiler.
1. Focus on FIRST error message, ignoring the rest.
2. Look at reported line of first error message. If error found, fix. Else, look at previous few lines.
3. Compile, repeat.


Floating-point division by zero
Dividing a nonzero floating-point number by zero is undefined in regular arithmetic. Many programming languages produce an error when performing floating-point division by 0, but C++ does not. C++ handles this operation by producing infinity or -infinity, depending on the signs of the operands. Printing a floating-point variable that holds infinity or -infinity outputs inf or -inf.