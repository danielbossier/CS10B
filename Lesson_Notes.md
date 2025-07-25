



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


Some variables only need to store a small set of named values. For example, a variable representing a traffic light need only store values named GREEN, YELLOW, or RED. An enumeration type (enum) declares a name for a new type and possible values for that type.


enum identifier {enumerator1, enumerator2,  ...};

The items within the braces ("enumerators") are integer constants automatically assigned an integer value, with the first item being 0, the second 1, and so on. An enumeration declares a new data type that can be used like the built-in types int, char, etc.



Basics of functions
A function is a named list of statements.

A function definition consists of the new function's name and a block of statements. Ex: double CalcPizzaArea() { /* block of statements */ }
A function call is an invocation of a function's name, causing the function's statements to execute.

A function can only return one item, not two or more.

Parameters
A programmer can influence a function's behavior via an input.

A parameter is a function input specified in a function definition. Ex: A pizza area function might have diameter as an input.
An argument is a value provided to a function's parameter during a function call. Ex: A pizza area function might be called as CalcPizzaArea(12.0) or as CalcPizzaArea(16.0).
A parameter is like a variable declaration. Upon a call, the parameter's memory location is allocated, and the parameter is assigned with the argument's value. Upon returning to the original call location, the parameter is deleted from memory.

An argument may be an expression, like 12.0, x, or x * 1.5.


C++ supports another kind of parameter that enables updating of an argument variable. A pass-by-reference parameter does not create a local copy of the argument, but rather the parameter refers directly to the argument variable's memory location. Appending & to a parameter's data type makes the parameter pass-by-reference type.


Manually examining a program's printed output is cumbersome and error prone. A better test harness would only print a message for incorrect output. The language provides a compact way to print an error message when an expression evaluates to false. assert() is a macro (similar to a function) that prints an error message and exits the program if assert()'s input expression is false. The error message includes the current line number and the expression (a nifty trick enabled by using a macro rather than an actual function; details are beyond our scope). Using assert requires first including the cassert library, part of the standard library, as shown below.

assert() enables compact readable test harnesses, and also eases the task of examining the program's output for correctness; a program without detected errors would simply output "Testing started" followed by "Testing completed".



Each function call creates a new set of local variables, forming part of what is known as a stack frame. A return causes those local variables to be discarded.


Define a function's output or input/output parameters as pass by reference.
- But create output parameters sparingly, striving to use return values instead.
Define input parameters as pass by value.
- Except for large items (perhaps 10 or more elements); use constant pass by reference for those.



C++ supports two kinds of ordered list types.

Arrays: declared as int myList[10], accessed as myList[i].
Vectors: declared as vector<int> myList(10), accessed as myList.at(i).
Arrays have a simpler syntax than vectors, but vectors are safer to use. Thus, using vectors rather than arrays is good practice.

Vectors are safer because the access v.at(i) is checked during execution to ensure the index is within the vector's valid range. An array access a[i] involves no such check. Such checking is important; trying to access an array with an out-of-range index is a very common error, and one of the hardest errors to debug.



The struct construct defines a new type, which can be used to declare a variable with subitems.

struct TimeHrMin {
   int hourValue;
   int minuteValue;
};

...

   TimeHrMin runTime1;
   TimeHrMin runTime2;
   TimeHrMin runTime3;

   runTime1.hourValue = 5;
   runTime1.minuteValue = 46;
   runTime3.hourValue = runTime1.hourValue;


Abstraction means to have a user interact with an item at a high-level, with lower-level internal details hidden from the user (aka information hiding or encapsulation). Ex: An oven supports an abstraction of a food compartment and a knob to control heat. An oven's user need not interact with internal parts of an oven.

Objects strongly support abstraction, hiding entire groups of functions and variables, exposing only certain functions to a user.

An abstract data type (ADT) is a data type whose creation and update are constrained to specific well-defined operations. A class can be used to implement an ADT.



The class construct defines a new type that can group data and functions to form an object. A class' public member functions indicate all operations a class user can perform on the object. The power of classes is that a class user need not know how the class' data and functions are implemented, but need only understand how each public member function behaves. The animation below shows a class' public member function declarations only; the remainder of the class definition is discussed later.

In addition to public member functions, a class definition has private data members: variables that member functions can access but class users cannot. Private data members appear after the word "private:" in a class definition.

A programmer defining a class first declares member functions after the word "public:" in the class definition. A function declaration provides the function's name, return type, and parameter types, but not the function's statements.

The programmer must also define each member function. A function definition provides a class name, return type, parameter names and types, and the function's statements. A member function definition has the class name and two colons (::), known as the scope resolution operator, preceding the function's name. A member function definition can access private data members.



Mutators and accessors
A class' public functions are commonly classified as either mutators or accessors.

A mutator function may modify ("mutate") a class' data members.
An accessor function accesses data members but does not modify a class' data members.
Commonly, a data member has two associated functions: a mutator for setting the value, and an accessor for getting the value, known as a setter and getter function, respectively, and typically with names starting with set or get. Other mutators and accessors may exist that aren't associated with just one data member, such as the Print() function below.

Accessor functions usually are defined as const to make clear that data members won't be changed. The keyword const after a member function's name and parameters causes a compiler error if the function modifies a data member. If a const member function calls another member function, that function must also be const.


C++ has a special class member function, a constructor, called automatically when a variable of that class type is declared, and which can initialize data members. A constructor callable without arguments is a default constructor, like the Restaurant constructor below.

A constructor has the same name as the class. A constructor function has no return type, not even void. Ex: Restaurant::Restaurant() {...} defines a constructor for the Restaurant class.

If a class has no programmer-defined constructor, then the compiler implicitly defines a default constructor having no statements.



The standard template library (STL) defines classes for common Abstract Data Types (ADTs). A vector is an ADT of an ordered, indexable list of items. The vector ADT is implemented as a class (actually a class template that supports different types such as vector<int> or vector<string>, although templates are discussed elsewhere).

For the commonly-used vector member functions below, assume a vector is declared as:

vector<T> vectorName();
where T represents the vector's element type, such as:

vector<int> teamNums(5);



Pointers
A pointer is a variable that contains a memory address. This section describes a few situations where pointers are useful.

Handling different amounts of data
A program often needs to support data of varying sizes. Using a predefined fixed-size array may either waste memory or limit the program's usefulness.


A program can use a dynamically allocated array to efficiently handle different amounts of data. A dynamically allocated array is an array whose size and memory location are determined during runtime. If a program needs to store more elements than the array's initial capacity, the program can create a new array with an increased capacity and copy the array elements to the new larger array.

A pointer variable is used to store the array's memory location, since the array's location in memory will change each time the array is dynamically allocated.


An array (or vector) stores elements in contiguous memory locations, which enables fast access to any element using the element's index. However, inserting an item requires making room by shifting higher-indexed items. For an array with thousands of elements, a single insert can require thousands of operations and cause the program to run very slowly.

A programmer can use a linked list to make inserts faster. A linked list consists of items that contain both data and a pointer (or link) to the next list item. Inserting a new item between two existing items just requires a few operations to update each item's pointer.



A dynamically allocated array is an array whose size and memory location are determined during runtime. A programmer can use the new operator to allocate an array and use a pointer to hold the array's memory location:

- A pointer is a variable that holds a memory address, rather than holding data like most variables. A pointer is declared by including * before the pointer's name. Ex: double* recordedTimes declares a double pointer named recordedTimes. When a pointer is initialized with the address of a dynamically allocated array, the pointer "points to" the array.

- The new operator allocates memory for the given type and returns a pointer to the allocated memory. Ex: new double[3] dynamically allocates a double array with three elements.

Dynamically allocated memory must be explicitly deallocated once the program no longer needs the memory. The deallocated memory is then available for allocation to other calls of new. The delete[] operator is used to deallocate an array allocated with the new operator. Ex: delete[] recordedTimes; deallocates the array pointed to by recordedTimes. If recordedTimes does not point to any arrays, then an error occurs.

After the delete, a program should not attempt to access the array pointed to by the pointer variable. Accessing memory that has been deallocated, such as a deleted dynamically allocated array, is a common error and may cause strange program behavior.


When a pointer is declared, the pointer variable holds an unknown address until the pointer is initialized. A programmer may wish to indicate that a pointer points to "nothing" by initializing a pointer to null. Null means "nothing". A pointer that is assigned with the keyword nullptr is said to be null.

For functions with pointer parameters, a good practice is to check that a pointer is not null before accessing the memory pointed to by the pointer. In the following example, the PrintArray() function ensures that arrayPtr is not null before accessing elements in the array.


Dynamically allocate an integer array with numBarrels elements and assign applesEaten with the array's address.:
 - applesEaten = new int[numBarrels];



 A program's memory usage typically includes four different regions:

Code — The region where the program instructions are stored.

Static memory — The region where global variables (variables declared outside any function) as well as static local variables (variables declared inside functions starting with the keyword "static") are allocated. Static variables are allocated once and stay in the same memory location for the duration of a program's execution.

The stack — The region where a function's local variables are allocated during a function call. A function call adds local variables to the stack, and a return removes them, like adding and removing dishes from a pile; hence the term "stack." Because this memory is automatically allocated and deallocated, it is also called automatic memory.

The heap — The region where the "new" operator allocates memory, and where the "delete" operator deallocates memory. The region is also called free store.



An object's member function is called using the syntax object.Function(). The object variable before the function name is known as an implicit parameter of the member function because the compiler converts the call syntax object.Function(...) into a function call with a pointer to the object implicitly passed as a parameter. Ex: Function(object, ...).

Within a member function, the implicitly-passed object pointer is accessible via the name this. In particular, a member can be accessed as this->member. The -> is the member access operator for a pointer, similar to the "." operator for non-pointers.

Using this-> makes clear that a class member is being accessed and is essential if a data member and parameter have the same identifier. In the example below, this-> is necessary to differentiate between the data member sideLength and the parameter sideLength.

C++ allows a programmer to redefine the functionality of built-in operators like +, -, and *, to operate on programmer-defined objects, a process known as operator overloading. Suppose a class TimeHrMn has data members hours and minutes. Overloading + would allow two TimeHrMn objects to be added with the + operator.


Without Operator Overloading:
TimeHrMn time1(3, 22);
TimeHrMn time2(2, 50);
TimeHrMn timeTot;
timeTot.hours = time1.hours + time2.hours;
timeTot.minutes = time1.minutes + time2.minutes;

timeTot.Print();


With Operator Overloading:
TimeHrMn time1(3, 22);
TimeHrMn time2(2, 50);
TimeHrMn timeTot;
timeTot = time1 + time2;

timeTot.Print();


To overload +, the programmer creates a member function named operator+. Although + requires left and right operands as in time1 + time2, the member function only requires the right operand (rhs: right-hand-side) as the parameter, because the left operand is the calling object. In other words, time1 + time2 is equivalent to the function call time1.operator+(time2), which is valid syntax but almost never used.


When an operator like + has been overloaded, the compiler determines which + operation to invoke based on the operand types. In 4 + 9, the compiler sees two integer operands and thus applies the built-in + operation. In time1 + time2, where time1 and time2 are TimeHrMn objects, the compiler sees two TimeHrMn operands and thus invokes the programmer-defined function.

A programmer can define several functions that overload the same operator, as long as each involves different types so that the compiler can determine which to invoke. The code below overloads the + operator twice in the TimeHrMn class.

main() uses the + operator in 4 statements. The first + involves two TimeHrMn operands, so the compiler invokes the first operator+ function ("A"). The second + involves TimeHrMn and int operands, so the compiler invokes the second operator+ function ("B"). The third + involves two int operands, so the compiler invokes the built-in + operation. The fourth +, commented out, involves an int and TimeHrMn operands. Because no function has those operands ("B" has TimeHrMn and int, not int and TimeHrMn; order matters), that statement would generate a compiler error.




Overloading the equality (==) operator
A programmer can overload the equality operator (==) to allow comparing objects of a programmer-defined class for equality. To overload ==, the programmer creates a function named operator== that returns bool and takes two const reference arguments of the class type for the left-hand-side and right-hand-side operands. Ex: To overload the == operator for a Review class, the programmer defines a function bool operator==(const Review& lhs, const Review& rhs).

The programmer must also determine when two objects are considered equal. In the Review class below, two Review objects are equal if the objects have the same rating and comment.



For the assignment:
TimeHrMn TimeHrMn::operator+(TimeHrMn rhs) {
TimeHrMn TimeHrMn::operator-(TimeHrMn rhs) {
TimeHrMn TimeHrMn::operator*(TimeHrMn rhs) {
TimeHrMn TimeHrMn::operator/(TimeHrMn rhs) {

