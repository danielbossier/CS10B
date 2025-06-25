#include <iostream>
using namespace std;

int main() {
   int currValue;
   int maxValue;

   cin >> currValue;

   maxValue = currValue;

   while (currValue > 0) {
      if (currValue > maxValue) {
         maxValue = currValue;
      }
      cin >> currValue;
   }

   cout << "Max value: " << maxValue;

   return 0;
}

Write a for loop that iterates seven times to find the minimum value in a list of seven floating-point values. Within the loop:

Read a floating-point value from input into variable inVal.
The first value assigned to inVal is the smallest floating-point value read by default, since no other values have been read yet. Thus, if the current iteration is the first iteration, assign minVal with inVal.
Otherwise, if inVal is less than minVal, assign minVal with the value of inVal.

Ex: If the input is:
7.7 6.8 13.2 14.2 16.2 7.7 15.4
then the output is:

6.8
Note: All floating-point values are of type double.


#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   double inVal;
   double minVal;
   int i;

   for (i = 0; i < 7; ++i) {
      cin >> inVal;
      if (i == 0) {
         minVal = inVal;
      } else if (inVal < minVal) {
         minVal = inVal;
      }
   }
   cout << minVal << endl;

   return 0;
}


Integer inputCount is read from input representing the number of integer values to be read next. Use a for loop to read the remaining integer values from input. Within the loop:

For each integer value read, output "Value read: " followed by the value and a newline.
Assign smallestVal with the smallest integer value read.


#include <iostream>
using namespace std;

int main() {
   int inputCount;
   int inputVal;
   int smallestVal;
   int i;

   cin >> inputCount;

   for (i = 0; i < inputCount; ++i) {
      cin >> inputVal;
      cout << "Value read: " << inputVal << endl;
      if (i == 0) {
      smallestVal = inputVal;
      } else if (inputVal < smallestVal) {
         smallestVal = inputVal;
      }
   }

   cout << "Smallest: " << smallestVal << endl;

   return 0;
}



Integer numInts is read from input representing the number of integers to be read next. Use a for loop to read in the remaining integers from input into val. If none of the integers read from input are 10, assign missingValue with true. Otherwise, assign missingValue with false.

Code at the end of main() outputs "Missing 10" if missingValue is true, or "Has one or more copies of 10" if missingValue is false.

Ex: If the input is:

3
14 9 6
then the output is:

Missing 10


#include <iostream>
using namespace std;

int main() {
   int numInts;
   bool missingValue;
   int i;
   int val;
   
   missingValue = true;
   cin >> numInts;

   for (i = 0; i < numInts; ++i) {
     cin >> val;
     if (val == 10) {
        missingValue = false;
     }
   }   

   if (missingValue) {
      cout << "Missing 10" << endl;
   }
   else {
      cout << "Has one or more copies of 10" << endl;
   }

   return 0;
}