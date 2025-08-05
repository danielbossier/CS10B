



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

A programmer can also overload relational operators like the less than operator (<). The < operator should return true if the object on the left side of the < operator is less than the object on the right side of the operator. In the Review class below, the operator< function returns true if the left Review operand has a lower rating than the right Review operand.


The sort() function, defined in the C++ Standard Template Library's (STL) algorithms library, can sort vectors containing objects of programmer-defined classes. To use sort(), a programmer must:

1. Add #include <algorithm> to enable the use of sort().
2. Overload the < operator for the programmer-defined class.
3. Call the sort() function as sort(myVector.begin(), myVector.end())



A name conflict occurs when two or more items like variables, classes, or functions, have the same name. Ex: One programmer creates a Seat class for auditoriums, and a second programmer creates a Seat class for airplanes. A third programmer creating a reservation system for airline and concert tickets wants to use both Seat classes, but a compiler error occurs due to the name conflict.

A namespace defines a region (or scope) used to prevent name conflicts. Above, the auditorium seat class code can be put in an auditorium namespace, and airplane seat class code in an airplane namespace. The scope resolution operator :: allows specifying in which namespace to find a name, as in: auditorium::Seat concertSeat; and airplane::Seat flightSeat;.


std namespace
All items in the C++ standard library are part of the std namespace (short for standard). To use classes like string or predefined objects like cout, a programmer can use one of two approaches:

Scope resolution operator (::): A programmer can use the scope resolution operator to specify the std namespace before C++ standard library items. Ex: std::cout << "Hello"; or std::string userName;
Namespace directive: A programmer can add the statement using namespace std; to direct the compiler to check the std namespace for any names later in the file that aren't otherwise declared. Ex: For string userName;, the compiler will check namespace std for string.
For code clarity, most programming guidelines discourage using namespace directives except perhaps for std.



The keyword static indicates a variable is allocated in memory only once during a program's execution. Static variables are allocated memory once and reside in the program's static memory region for the entire program. Thus, a static variable retains a value throughout the program.

In a class, a static data member is a data member of the class instead of a data member of each class object. Thus, static data members are independent of any class object, and can be accessed without creating a class object.

A static data member is declared inside the class definition, but must also be defined outside the class declaration. Within a class function, a static data member can be accessed just by variable name. A public static data member can be accessed outside the class using the scope resolution operator: ClassName::variableName.


A static member function is a class function that is independent of class objects. Static member functions are typically used to access and mutate private static data members from outside the class. Since static methods are independent of class objects, the this parameter is not passed to a static member function. So, a static member function can only access a class' static data members.



1. friend functions
These are non-member functions, but they have access to the class's private members because they're declared as friend.

They are used when:

The left-hand operand is not necessarily a Fraction object.

You need symmetry — for example, to support both fraction + int and int + fraction.

You’re comparing or combining two objects.

Examples:

cpp
Copy
Edit
friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
friend bool operator==(const Fraction& lhs, const Fraction& rhs);
friend ostream& operator<<(ostream& out, const Fraction& frac);
Why?

These need access to num and denom from both operands.

They also allow expressions like 3 + Fraction(1, 2) by enabling overloads outside the class.

🔹 2. Member functions returning Fraction or Fraction&
These are member functions — they operate on the object itself (this), and are used when:

The left-hand operand must be a Fraction.

You’re changing the internal state (like with +=).

You’re implementing prefix/postfix increment/decrement.

Examples:

cpp
Copy
Edit
Fraction& operator+=(const Fraction& rhs);     // modifies this object
Fraction& operator++();                        // prefix ++
Fraction operator++(int);                      // postfix ++
Why?

These modify the current object (this) or return a result based on it.

Only member functions can modify the current object directly.

You don’t want to allow int += Fraction(...), but you do want Fraction += int or Fraction += Fraction.



A class containing a dynamically allocated array that may increase in size frequently can be efficiently implemented using an array with extra capacity. Three class members are needed to implement an array with extra capacity:

A pointer to hold the dynamically allocated array's address.
A capacity to hold the total number of elements that the array can hold.
A size to hold the number of elements currently held in the array.


When a class has a dynamically allocated array that grows, the class' constructor usually initializes the array with a positive capacity and allocates the array. The array's initial size is 0. Ex: The ActivityTracker class' constructor initializes an ActivityTracker object with an Activity array of capacity 2. Allocating memory in powers of 2 is a popular practice because memory management is sometimes faster.


Each time an array is expanded, a new array is allocated and existing elements are copied over to the new array. Copying elements is time consuming, especially for large size arrays. To reduce the frequency of array expansion, the new array's capacity is usually doubled at each expansion. Ex: ActivityTracker's member function IncreaseCapacity() doubles the activities array's capacity.


Adding elements to a dynamically allocated array with extra capacity
When an element is added to a dynamically allocated array:

- If the array's capacity is greater than the size, the array has unused space to add the new element. So, the first unused object in the array is assigned with the new element.
- If the array's capacity is equal to the size, the array does not have unused space. So, the array is first expanded, and then the new element is added.



A destructor is a special class member function that is called automatically when a variable of that class type is destroyed. When a C++ class object uses dynamically allocated data, such data is commonly deallocated in the class' destructor.

The syntax for a class' destructor function is similar to a class' constructor function, but with a "~" (called a "tilde" character) prepended to the function name. A destructor has no parameters and no return value. Ex: The ActivityTracker class destructor is declared as ~ActivityTracker();.


When an array of objects is deallocated using delete[], the destructor is called on each object in the array. Ex: The Activity destructor is not required, but is implemented below to illustrate when the Activity destructor is called.

If an object is dynamically allocated using the new operator, using delete on the object calls the object's destructor. If an object is not dynamically allocated, the object's destructor is called automatically when the object goes out of scope.



A memory leak occurs when a program that allocates memory loses the ability to access the allocated memory, typically due to failure to properly destroy/free dynamically allocated memory. A program's leaking memory becomes unusable, much like a water pipe might have water leaking out and becoming unusable. A memory leak may cause a program to occupy more and more memory as the program runs, which slows program runtime. Even worse, a memory leak can cause the program to fail if memory becomes completely full and the program is unable to allocate additional memory.

A common error is failing to free allocated memory that is no longer used, resulting in a memory leak. Many programs that are commonly left running for long periods, like web browsers, suffer from known memory leaks — a web search for "<your-favorite-browser> memory leak" will likely result in numerous hits.


Garbage collection
Some programming languages, such as Java, use a mechanism called garbage collection wherein a program's executable includes automatic behavior that at various intervals finds all unreachable allocated memory locations (e.g., by comparing all reachable memory with all previously-allocated memory), and automatically frees such unreachable memory. Some non-standard C++ implementations also include garbage collection. Garbage collection can reduce the impact of memory leaks at the expense of runtime overhead. Computer scientists debate whether new programmers should learn to explicitly free memory versus letting garbage collection do the work.


Memory not freed in a destructor
Destructors are needed when destroying an object involves more work than simply freeing the object's memory. Such a need commonly arises when an object's data member, referred to as a sub-object, has allocated additional memory. Freeing the object's memory without also freeing the sub-object's memory results in a problem where the sub-object's memory is still allocated, but inaccessible, and thus can't be used again by the program.

The program in the animation below is very simple to focus on how memory leaks occur with sub-objects. The class's sub-object is just an integer pointer but typically would be a pointer to a more complex type. Likewise, the object is created and then immediately destroyed, but typically something would have been done with the object.


Copy constructor
The solution is to create a copy constructor, a constructor that is automatically called when an object of the class type is passed by value to a function and when an object is initialized by copying another object during declaration. Ex: MyClass classObj2 = classObj1; or obj2Ptr = new MyClass(classObj1);. The copy constructor makes a new copy of all data members (including pointers), known as a deep copy.

If the programmer doesn't define a copy constructor, then the compiler implicitly defines a constructor with statements that perform a memberwise copy, which simply copies each member using assignment: newObj.member1 = origObj.member1, newObj.member2 = origObj.member2, etc. Creating a copy of an object by copying only the data members' values creates a shallow copy of the object. A shallow copy is fine for many classes, but typically a deep copy is desired for objects that have data members pointing to dynamically allocated memory.

The copy constructor can be called with a single pass-by-reference argument of the class type, representing an original object to be copied to the newly-created object. A programmer may define a copy constructor, typically having the form: MyClass(const MyClass& origObject);


The program below adds a copy constructor to the earlier example, which makes a deep copy of the data member dataObject within the MyClass object. The copy constructor is automatically called during the call to SomeFunction(). Destruction of the local object upon return from SomeFunction() frees the newly created dataObject for the local object, leaving the original tempClassObject's dataObject untouched. Printing after the function call correctly prints 9, and destruction of tempClassObject during the return from main() produces no error.


Copy constructors in more complicated situations
The above examples use a trivially-simple class having a dataObject whose type is a pointer to an integer, to focus attention on the key issue. Real situations typically involve classes with multiple data members and with data objects whose types are pointers to class-type objects.


Default assignment operator behavior
Given two MyClass objects, classObj1 and classObj2, a programmer might write classObj2 = classObj1; to copy classObj1 to classObj2. The default behavior of the assignment operator (=) for classes or structs is to perform memberwise assignment. Ex:

classObj2.memberVal1 = classObj1.memberVal1;
classObj2.memberVal2 = classObj1.memberVal2; 
...

Such behavior may work fine for members with basic types like int or char, but typically is not the desired behavior for a pointer member. Memberwise assignment of pointers may lead to program crashes or memory leaks.


Default assignment operator behavior
Given two MyClass objects, classObj1 and classObj2, a programmer might write classObj2 = classObj1; to copy classObj1 to classObj2. The default behavior of the assignment operator (=) for classes or structs is to perform memberwise assignment. Ex:

classObj2.memberVal1 = classObj1.memberVal1;
classObj2.memberVal2 = classObj1.memberVal2; 
...

Such behavior may work fine for members with basic types like int or char, but typically is not the desired behavior for a pointer member. Memberwise assignment of pointers may lead to program crashes or memory leaks.


Overloading the assignment operator
The assignment operator (=) can be overloaded to eliminate problems caused by a memberwise assignment during an object copy. The implementation of the assignment operator iterates through each member of the source object. Each non-pointer member is copied directly from source member to destination member. For each pointer member, new memory is allocated, the source's referenced data is copied to the new memory, and a pointer to the new member is assigned as the destination member. Allocating and copying data for pointer members is known as a deep copy.

The following program solves the default assignment operator behavior problem by introducing an assignment operator that performs a deep copy.


Rule of three
The rule of three describes a practice that if a programmer explicitly defines any one of three special member functions (namely, a destructor, copy constructor, or copy assignment operator), then the programmer should explicitly define all three. Those three special member functions are sometimes called the big three. A good practice is to always follow the rule of three and define the big three if any one of these functions is defined.


Default destructor, copy constructor, and copy assignment operator
If a programmer does not define a special member function, then the compiler implicitly defines a default implementation:

A default destructor does nothing.
A default copy constructor initializes an object's data members with a copy, by value, of another object's corresponding members. Such a copy is called a shallow copy.
A default copy assignment operator assigns an object's data members with a copy, by value, of another object's corresponding members.


Rule of Five
If a function returns a static object, a temporary copy of the static object is created and passed back from the function. Since the static object will be destroyed soon, a more efficient approach is to define move operations to transfer the data from the static object to the temporary copy. Thus, a modern practice since C++11 recommends the rule of five. The five member functions to be defined together are: destructor, copy constructor, copy assignment operator, move constructor, and move assignment operator. While the rule of three is a rule to ensure that classes with dynamically allocated data are handled correctly, the rule of five is primarily a rule for handling such data efficiently.


unique_ptr for single objects
A smart pointer is a class that wraps around a pointer to an object to simplify the memory management of the object. To distinguish a smart pointer from a pointer, the latter is referred to as a raw pointer in this section. unique_ptr is a smart pointer that permits only one owner over an object. When a unique_ptr goes out of scope, the object owned by the unique_ptr is automatically deleted. To use the unique_ptr class, the programmer must include the statement #include <memory> for C++17 and later versions.


Types of smart pointers
C++ supports smart pointers with various ownership relationships between the smart pointer and the dynamically allocated object being pointed to. The following summarizes three common smart pointer types.


Type	                 Features	                
unique_ptr	            A unique_ptr only allows an exclusive ownership of the object. The object's ownership can be transferred to a different unique_ptr, but not shared. When a unique_ptr goes out of scope, the object owned by the unique_ptr is deleted.
- As an efficient replacement of raw pointer

shared_ptr	            A shared_ptr permits shared ownership of an object. When the last owner of the object goes out of scope, the object is deleted. Internally, a counter, called the reference count, keeps track of the number of owners sharing an object.
- When a dynamically allocated object is shared by multiple pointers

weak_ptr	            A weak_ptr allows access to, but not ownership of, an object that is owned by a shared_ptr.
- To interact with a dynamically allocated object whose memory is managed elsewhere



Lesson 17 Notes:

Each inventory item represents an individual item in an inventory.

Just going to store a description (c-string) and quantity (int).


Commonly, one class is similar to another class but with some additions or variations. Ex: A store inventory system might use a class called GenericItem that has itemName and itemQuantity data members. But for produce (fruits and vegetables), a ProduceItem class with data members itemName, itemQuantity, and expirationDate may be desired.


Inheritance
A derived class (or subclass) is a class that is derived from another class, called a base class (or superclass). Any class may serve as a base class. The derived class is said to inherit the properties of the base class, a concept called inheritance. An object declared of a derived class type has access to all the members of the derived class as well as the public and protected members of the base class.

A derived class is declared by placing a colon ":" after the derived class name, followed by a member access specifier like public and a base class name. Ex: class DerivedClass: public BaseClass { ... };. The figure below defines the base class GenericItem and derived class ProduceItem that inherits from GenericItem.


Inheritance scenarios
Various inheritance variations are possible:

A derived class can serve as a base class for another class. Ex: class FruitItem: public ProduceItem {...} creates a derived class FruitItem from ProduceItem, which was derived from GenericItem.
A class can serve as a base class for multiple derived classes. Ex: class FrozenFoodItem: public GenericItem {...} creates a derived class FrozenFoodItem that inherits from GenericItem, just as ProduceItem inherits from GenericItem.
A class may be derived from multiple classes. Ex: class House: public Dwelling, public Property {...} creates a derived class House that inherits from base classes Dwelling and Property.


Member access
The members of a derived class have access to the public members of the base class, but not to the private members of the base class. This is logical—allowing access to all private members of a class merely by creating a derived class would circumvent the idea of private members. Thus, adding the following member function to the Restaurant class yields a compiler error.


Protected member access
Recall that members of a class may have their access specified as public or private. A third access specifier is protected, which provides access to derived classes but not by anyone else. The following illustrates the implications of the protected access specifier.

In the following example, the member called name is specified as protected and is accessible anywhere in the derived class. Note however that the name member is not accessible in main() -- the protected specifier only applies to derived classes; protected members are private to everyone else.


SPECIFIER	DESCRIPTION
private	    Accessible by self.
protected	Accessible by self and derived classes.
public	    Accessible by self, derived classes, and everyone else.


Protected access modifier and encapsulation
Encapsulation is a goal of object-oriented programming. Encapsulation is restricting access to data from outside a class. The protected access modifier loosens encapsulation since since data may be directly accessed by the base class and any derived classes.


Class definitions
Separately, the keyword "public" in a class definition like class DerivedClass: public BaseClass {...} has a different purpose, relating to the kind of inheritance being carried out:

public : "public-->public, protected-->protected" -- public members of BaseClass are accessible as public members of DerivedClass, and protected members of BaseClass are accessible as protected members of DerivedClass.
protected : "public-->protected, protected-->protected" -- public and protected members of BaseClass are accessible as protected members of DerivedClass.
private : "public-->private, protected-->private" -- public and protected members of BaseClass are accessible as private members of DerivedClass. Incidentally, if the specifier is omitted as in "class DerivedClass: BaseClass {...}", the default is private.
Most derived classes created when learning to program use public inheritance.


Overriding
When a derived class defines a member function that has the same name and parameters as a base class's function, the member function is said to override the base class's function. The example below shows how the Restaurant's GetDescription() function overrides the Business's GetDescription() function.


Overriding vs. overloading
Overriding differs from overloading. In overloading, functions with the same name must have different parameter types or number of parameters. In overriding, a derived class member function must have the same parameter types, number of parameters, and return value as the base class member function with the same name. Overloading is performed if derived and base member functions have different parameter types; the member function of the derived class does not hide the member function of the base class.


Calling a base class function
An overriding function can call the overridden function by prepending the base class name. Ex: Business::GetDescription().


A common error is to leave off the prepended base class name when wanting to call the base class's function. Without the prepended base class name, the call to GetDescription() refers to itself (a recursive call), so GetDescription() would call itself, which would call itself, etc., never actually printing anything.


22.4 Constructor initializer lists
A constructor initializer list is an alternative approach for initializing data members in a constructor, coming after a colon and consisting of a comma-separated list of variableName(initValue) items.


The approach is important when a data member is a class type that must be explicitly constructed. Otherwise, that data member is by default constructed. Ex: If you have studied vectors, consider a data member consisting of a vector of size 2.

On the left, the constructor initially creates a vector of size 0, then resizes to size 2, where each element has the value 0. On the right, itemList(2) is provided in the SampleClass constructor initialization list, causing the vector constructor to be called with size 2 and each vector element to be initialized with the value 0. Using the initialization list avoids the inefficiency of constructing and then modifying an item.

Note: Since C++11, the data member could have been initialized in the class definition: vector<int> itemList(2);. However, initialization lists are still useful for other cases.


Composition should be used when the classes exhibit a "has-a" relationship; inheritance is used when the relationship is an "is-a" relationship

This brings up an important rule of inheritance. C++ takes the "IS-A" relationship very seriously. In fact, any place in a program where a base class object is expected, you are allowed to place an object of a class that is derived from that base class instead. This explains why it is that when we overload the extraction operator, we do not use "ifstream" as the type of the first parameter (see the extraction operator in the invItem class of lesson 16 or in the feetInches class of lesson 13 for examples of this). Instead, we use "istream". But C++ still allows us to use an ifstream object as the argument instead of an istream object. This is because C++ considers an ifstream object to BE an istream object, because the ifstream class is derived from the istream class. Just think, if it weren't for inheritance we would have to write two different extraction operators for each of our classes, one with a first parameter of type istream and one with a first parameter of type ifstream.

Each time a derived class constructor is called, the base class *default* constructor is called before execution of the derived class constructor begins

The derived class shouldn't be messing with the base class data members


Take some time to reflect on the program you just completed from the perspective of the base class, Creature. With respect to inheritance, you'll see 3 categories of member functions illustrated (not counting constructors, since they are not inherited).

The accessors and mutators are typical member functions that are inherited and never redefined. For example, the balrog class's getDamage() function calls getStrength(), which it can do because it has been inherited from the Creature class (via the Demon class).

getSpecies() is a pure virtual function. It is not defined in the Creature class, but it must be defined in every class that is derived from the Creature class, or the Creature class won't work, because the Creature class's getDamage() function depends on the fact that getSpecies() exists in the derived class.

getDamage() is a virtual member function that is inherited and is sometimes redefined.


Polymorphism
Polymorphism refers to determining which program behavior to execute depending on data types. Two main types of polymorphism exist:

Compile-time polymorphism is when the compiler determines which function to call at compile-time.
Runtime polymorphism is when the compiler is unable to determine which function to call at compile-time, so the determination is made while the program is running.
Function overloading is an example of compile-time polymorphism where the compiler determines which of several identically-named functions to call based on the function's arguments.

One scenario requiring runtime polymorphism involves derived classes. Programmers commonly create a collection of objects of both base and derived class types. Ex: The statement vector<Business*> businessList; creates a vector that can contain pointers to objects of type Business or Restaurant, since Restaurant is derived from Business. Similarly, polymorphism is also used for references to objects. Ex: Business& primaryBusiness declares a reference that can refer to Business or Restaurant objects.


Virtual functions
Runtime polymorphism only works when an overridden member function in a base class is virtual. A virtual function is a member function that may be overridden in a derived class and is used for runtime polymorphism. A virtual function is declared by prepending the keyword "virtual". Ex: virtual string GetDescription() const. At runtime, when a virtual function is called using a pointer, the correct function to call is dynamically determined based on the actual object type to which the pointer or reference refers.

The override keyword is an optional keyword used to indicate that a virtual function is overridden in a derived class. Good practice is to use the override keyword when overriding a virtual function to avoid accidentally misspelling the function name or typing the wrong parameters.


Virtual table
To implement virtual functions, the compiler creates a virtual table that allows the computer to quickly lookup which function to call at runtime. The virtual table contains an entry for each virtual function with a function pointer that points to the most-derived function that is accessible to each class. Looking up which function to call makes runtime polymorphism slower than compile-time polymorphism.

The program below illustrates how runtime polymorphism is used with a vector. businessList is a vector of Business pointers but holds Business and Restaurant pointers. A for loop iterates over businessList and calls each Business pointer's GetDescription() function. Restaurant GetDescription() is called when a Restaurant pointer is accessed because GetDescription() overrides the base class's virtual function.


Pure virtual functions
Sometimes a base class should not provide a definition for a member function, but all derived classes must provide a definition. Ex: A Business may require all derived classes to define a GetHours() function, but the Business class does not provide a default GetHours() function.

A pure virtual function is a virtual function that provides no definition in the base class, and all derived classes must override the function. A pure virtual function is declared like a virtual function with the "virtual" keyword but is assigned with 0. Ex: virtual string GetHours() const = 0; declares a pure virtual function GetHours().

A class that has at least one pure virtual function is known as an abstract base class. An abstract base class object cannot be declared. Ex: The variable declaration Business someBusiness; generates a syntax error if Business is an abstract base class.


Abstract classes
Object-oriented programming (OOP) is a powerful programming paradigm, consisting of several features. Three key features include:

Classes: A class encapsulates data and behavior to create objects.
Inheritance: Inheritance allows one class (a subclass) to be based on another class (a base class or superclass). Ex: A Shape class may encapsulate data and behavior for geometric shapes, like setting/getting the Shape's name and color, while a Circle class may be a subclass of a Shape, with additional features like setting/getting the center point and radius.
Abstract classes: An abstract class is a class that guides the design of subclasses but cannot itself be instantiated as an object. Ex: An abstract Shape class might also specify that any subclass must define a ComputeArea() function.


Abstract and concrete classes
A pure virtual function is a virtual function that is not implemented in the base class, thus all derived classes must override the function. A pure virtual function is declared with the "virtual" keyword and is assigned with 0. Ex: virtual double ComputeArea() const = 0; declares a pure virtual function ComputeArea().

An abstract class is a class that cannot be instantiated as an object, but is the superclass for a subclass and specifies how the subclass must be implemented. Any class with one or more pure virtual functions is abstract.

A concrete class is a class that is not abstract, and hence can be instantiated.


The concept of inheritance is commonly confused with the idea of composition. Composition is the idea that one object may be made up of other objects, such as a MotherInfo class being made up of objects like firstName (which may be a string object), childrenData (which may be a vector of ChildInfo objects), etc. Defining that MotherInfo class does not involve inheritance, but rather just composing the sub-objects in the class.


UML class diagrams
The Unified Modeling Language (UML) is a language for software design that uses different types of diagrams to visualize the structure and behavior of programs. A structural diagram visualizes static elements of software, such as the attributes (variables) and operations (functions) used in the program. A behavioral diagram visualizes dynamic behavior of software, such as the flow of an algorithm.

A UML class diagram is a structural diagram that can be used to visually model the classes of a computer program, including member variables and functions.


UML for inheritance
UML uses an arrow with a solid line and an unfilled arrow head to indicate that one class inherits from another. The arrow points toward the parent class.

UML uses italics to denote abstract classes. In particular, UML uses italics for the abstract class' name, and for each pure virtual function in the class. As a reminder, a parent class does not have to be abstract. Also, any class with one or more pure virtual functions is abstract.


Unhandled exceptions
An exception is an unexpected incident that stops the normal program execution. Ex: Accessing an out of range element in vector results in an exception. A program that does not handle an exception ends execution.


Catching exceptions
To avoid having a program end when an exception occurs, a program can use try and catch blocks to handle the exception during program execution.

A try block surrounds normal code, which is exited immediately if a statement within the try block throws an exception.
A catch block catches an exception thrown in a preceding try block. If the thrown exception's type matches the catch block's parameter type, the code within the catch block executes. A catch block is called an exception handler.


Handling exceptions
A program may be able to resolve some exceptions. The previous example only printed an error message and an invalid shipping cost. Instead, the program can handle the exception and then get user input again until a valid input is provided, , as shown in the below example.


Type	            Cause of exception
runtime_error	    Errors that occur and are detected at runtime. runtime_error is a base class for other exceptions.
system_error	    Errors originating from the underlying operating system or other low-level system components. system_error's typically have an associated error code.
invalid_argument	Errors due to invalid user inputs or invalid inputs to program components (e.g., function arguments).
out_of_range	    Errors due to accessing elements outside of a supported range (e.g., vector indices).
ios_base::failure	Errors due to failures in reading or writing input/output streams.


Handling exceptions from opening invalid files
A program may try to open a file that does not exist. Ex: The file may have been deleted, renamed, or moved. In the below program, the statement inputFile.exceptions(ifstream::failbit); configures the inputFile stream to throw an exception if an error occurs when attempting to open or read from the specified file.

Closing files
The previous program did not close the opened file before exiting. A good practice is to close all files to allow the operating system to cleanup any resources used while reading from or writing to a file. The following example reads numbers from an input file, calculates the sum and prints the average, then closes the file before exiting.


Handling exceptions when writing to files
A program may fail to write to a file. Ex: The file may have been renamed or moved, or is a read-only file. In the program below, the statement outputFile.exceptions(ofstream::failbit); configures the outputFile stream to throw an exception if an error occurs when attempting to open or write to the specified file.


Writing to files after handling exceptions
A programmer can use a catch block to do additional processing, even if an exception is thrown in the try statement. Ex: If an exception is thrown after a program has opened and partially read a file, code within the catch block can preserve calculations the program has made up to when the exception was thrown. In the program below, the first catch block contains code to write partial results to the output file, even if an exception occurs while reading the input file.


24.6 Function templates
Multiple functions may be nearly identical, differing only in their data types.
Writing and maintaining redundant functions that only differ by data type can be time-consuming and error-prone. The language supports a better approach.

A function template is a function definition having a special type parameter that may be used in place of types in the function.


The function return type is preceded by template<typename TheType>, where TheType can be any identifier. That type is known as a type parameter and can be used throughout the function for any parameter types, return types, or local variable types. The identifier is known as a template parameter, and may be various reference types or even another template parameter.

The compiler automatically generates a unique function definition for each type appearing in function calls to the function template. Thus, the above example's calls would create three TripleMin() function definitions using int, char, and string as in this section's introductory example. The programmer never sees those function definitions.