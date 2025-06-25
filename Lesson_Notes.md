



Section 2

Let's take a closer look at assignment statements. The general form of an assignment statement is

    <variable> = <expression>;


    
operation	    C++ operator	algebraic example	C++ example
addition	           +	          x + 7	           x + 7
subtraction	           —	          x — 7	           x — 7
multiplication	       *	            4x	           4 * x
division	           /	            x÷2	           x / 2
modulus	               %	           none	           x % 2


In C++ when you divide two integers, the answer is an integer. You simply chop off (truncate is the technical term) any fraction or decimal part of the number. So 23 / 4 is 5.




Section 2.4: Double Variables and Literals



In computer programming, a "literal" is an actual value that appears in the code. For example, the 83 and the 25 in the above example are literals.

A double literal is defined as a number that has a decimal point in it.

In C++ 5 is an integer literal, but 5.0 is a double literal because it includes a decimal point. In algebra 5.0 would be considered an integer.

The declaration statement used to define a double variable looks like this:

    double salary;
After using this declaration statement, we could then say something like

    salary = 1213.81;
Here's another example:

    double gallons;
    double quarts = 7;

    gallons = quarts / 4;
If we had declared gallons and quarts to be integers, gallons would have been assigned the value 1. However, since we have declared gallons and quarts to be doubles, this statement assigns to gallons the value 1.75.

Here are some important observations about type double:

Because of the way that computers store doubles, you can never assume that a double value is being stored with exact precision. For this reason, you should never attempt to compare doubles.

You should use type int whenever possible. Use double only when the situation requires the use of non-integer values.

At times you will need to convert an int into a double. For example, in order to do some sort of calculation that requires decimal points in the answer.

If the int that needs to be converted is a literal, this is easy: you can just add a ".0" to the literal. For example, if the int is 47, to force C++ to treat it as a double instead of as an int you can just use 47.0.

If the int that needs to be converted is a variable, you should use a static-cast. (There are other ways to do this conversion in C++, but the one I'm about to show you is best practice.) If you have an int variable named "numCorrect" and you need to convert it to a double, use this syntax: static_cast <double> (numCorrect). You probably won't need this technique right away, but keep it in mind for future assignments.

All 5 of the arithmetic operators we have discussed require both of their operands to be of the same type. This means, for example, that C++ cannot add an int and a double. However, C++ is able convert back and forth between the two types, so the two types can be mixed in expressions and assignment statements. The assignment statement above, for example, has a double (quarts) and an int (4) in the expression. The results, however, are not always what we would expect. Unlike the situation in algebra, in C++ we cannot perform mathematical operations with operands of two different types. We must have rules for how to convert one type to another so that the types of the operands match.


The rule is that C++ automatically changes the value of the expression on the right side of the assignment operator so that it matches the type of the variable of the left side of the assignment operator.


Example 1:

    int i;
    double x;
    double y;

    x = 11;
    y = 4;
    i = x / y;
x/y is equal to 2.75. When C++ goes to assign this value to i, it realizes that i is an integer variable, and so before doing the assignment, it converts 2.75 to an integer by dropping the decimal. So i gets the value 2.

Example 2:

    int i;
    int j;
    double x;

    i = 11;
    j = 4;
    x = i / j;
Because i and j are both integers, i/j is equal to 2. When C++ goes to assign this value to x, it realizes that x is a double variable, and so before doing the assignment, it converts 2 to a double. So x gets the value 2.0.

Both of these examples illustrate that C++ doesn't always do things the way we expect it to. Unless we are careful, we might not expect i to get the value 2 in example 1, because in math we learn to give an exact answer (2.75) or to round off to the nearest integer (3). In example 2, we might expect x to get the value 2.75. After all, x is a double variable so it could handle the value 2.75. If we are careful, though, we notice that i and j are both integers, so i/j is equal to 2. When mixing doubles and ints in expressions and assignment statements, we must be very careful to follow C++'s rules exactly.


Section 2.5: Char Variables and Literals

Characters are things like letters ('a', 'Z'), digits ('1','9','0'), and other symbols that might appear on a screen ('$','+','^',' '). There are also some characters that are invisible (such as a newline character), but we won't concern ourselves with them just yet.

A declaration statement to declare a character variable looks like this:

    char ch;
Then we could say something like this:

    ch = '?';


Other important points about character literals and variables:

A common mistake made by novice computer programmers is omitting the quotation marks when using a character literal. When this happens, C++ will think that we are trying to use a variable that has not been declared.

The rule about using single quotes for character literals refers to how things appear in our code. When a character value is typed in by the user, the user does not enclose it in quotes.

Character variables store exactly one character. It doesn't make sense to say ch = 'hi';

Computers don't actually store characters, they store numbers. When you store a character value in a character variable, what is actually being stored is an integer code that represents that character value. We use ASCII codes for this purpose. Take a look at this table: http://www.asciitable.com/. You should be able to see from that table that when you store the character 'A' in a char variable, what is actually being stored is the number 65. Understanding this may make it easier to work with char variables in some contexts. For example, to print every uppercase letter of the alphabet I could use this for loop:

for (char ch = 'A'; ch <= 'Z'; ch++) {
    cout << ch;
}



Section 2.6: String Variables and Literals


2.9 Constant variables
Instructor note:
This is an important section, but in my opinion it is better to place the constants before int main() instead of inside int main() (for reasons that we will see in a few weeks). Please review Lesson 2.9 of the lessons (coincidentally the same number as this section).

Figure 2.9.1: Constant variable example: Lightning distance.

int main() {
   const double SPEED_OF_SOUND   = 761.207; // Miles/hour (sea level)
   const double SECONDS_PER_HOUR = 3600.0;  // Secs/hour
   double secondsBetween;
   double timeInHours;
   double distInMiles;
   
   cout << "Enter seconds between lightning and thunder: ";
   cin  >> secondsBetween;
   
   timeInHours = secondsBetween / SECONDS_PER_HOUR;
   distInMiles = SPEED_OF_SOUND * timeInHours;
   
   cout << "Lightning strike was approximately" << endl;
   cout << distInMiles << " miles away." << endl;
   
   return 0;
}



2.10 Using math functions
Basics
Some programs require math operations beyond +, -, *, /, like computing a square root. A standard math library has about 20 math operations, known as functions. A programmer can include the library and then use those math functions.

A function is a list of statements executed by invoking the function's name, such invoking is known as a function call. Any function input values, or arguments, appear within ( ), separated by commas if more than one. Below, function sqrt is called with one argument, areaSquare. The function call evaluates to a value, as in sqrt(areaSquare) below evaluating to 7.0, which is assigned to sideSquare.


Table 2.10.1: A few common math functions from the math library.
Function	   Behavior	                    Example
sqrt(x)	    Square root of x	     sqrt(9.0) evaluates to 3.0.
pow(x, y)	Power: x to the Y        pow(6.0, 2.0) evaluates to 36.0.
fabs(x)   	Absolute value of x	     fabs(-99.5) evaluates to 99.5.



2.12 Type conversions
Type conversions
A calculation sometimes must mix integer and floating-point numbers. For example, given that about 50.4% of human births are males, then 0.504 * numBirths calculates the number of expected males in numBirths births. If numBirths is an int variable (int because the number of births is countable), then the expression combines a floating-point and integer.

A type conversion is a conversion of one data type to another, such as an int to a double. The compiler automatically performs several common conversions between int and double types, such automatic conversions are known as implicit conversion.

For an arithmetic operator like + or *, if either operand is a double, the other is automatically converted to double, and then a floating-point operation is performed.
For assignments, the right side type is converted to the left side type.
int-to-double conversion is straightforward: 25 becomes 25.0.

double-to-int conversion just drops the fraction: 4.9 becomes 4.


Table 2.14.2: Common escape sequences.
Escape sequence	   Char
\n	              newline
\t	              tab
\'	              single quote
\"	              double quote
\\	              backslash

