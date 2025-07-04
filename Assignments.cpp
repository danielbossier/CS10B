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




#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {

	int total;
	int card1;
	int card2;
	int card3;
	char userResponse;

	/* for (int i = 0; i < 1; i++) {
		cout << "First cards: " << rand() % 10 + 1 << ", " << rand() % 10 + 1 << endl;
	}
	*/
	card1 = rand() % 10 + 1;
	card2 = rand() % 10 + 1;

	cout << "First cards: " << card1 << ", " << card2 << endl;
	total = (card1 + card2);
	cout << "Total: " << total << endl;

	cout << "Do you want another card (y/n)?" << endl;
	cin >> userResponse;
	cout << "Total: " << total << endl;
	cout << "You entered: " << userResponse << endl;
		
	while (userResponse == 'y') {
		cout << "Do you want another card (y/n)?" << endl;
		cin >> userResponse;
		cout << "You entered: " << userResponse << endl;
		cout << "Total: " << total << endl;
	}

	
	/*if (response2 == 'y') {
		cout << "Do you want another card (y/n)?" << endl;
		cin >> response3;
	}
	*/


	return 0;
}



#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {

	int card1;
	int card2;
	int total;
	int hitCard;
	char userResponse;
	char playAgain;

	playAgain = 'y';   //setting loop trigger (y = initiate loop)

	while (playAgain == 'y') {     //create first two cards and set total
		card1 = rand() % 10 + 1;
		card2 = rand() % 10 + 1;
		total = (card1 + card2);

		cout << "First cards: " << card1 << ", " << card2 << endl;
		cout << "Total: " << total << endl;

		if (total == 21) {                       //checking for blackjack
			cout << "Congratulations!" << endl;
		}
		else {
			cout << "Do you want another card (y/n)? ";  //offer user chance to hit
			cin >> userResponse;

			while (userResponse == 'y') {              //user "hits", new card is generated and total updated
				hitCard = rand() % 10 + 1;
				cout << "Card: " << hitCard << endl;
				total = total + hitCard;
				cout << "Total: " << total << endl;

				if (total >= 21) {                    //after new total, check if blackjack or bust
					break;
				}

				cout << "Do you want another card (y/n)? "; //offer another chance to hit
				cin >> userResponse;
			}
			
			if (total == 21) {                        //blackjack and bust logic
				cout << "Congratulations!" << endl;
			}
			else if (total > 21) {
				cout << "Bust." << endl;
			
			}
		}

		cout << "Would you like to play again (y/n)? "; //chance to play again and reset loop
		cin >> playAgain;
	}

	return 0;
}



#include <iostream>
#include <string>
using namespace std;

int main() {
   string userText;
   int usaIndex;

   cout << "Enter text: ";
   getline(cin, userText);

   // At least one occurrence exists
   while (userText.find("U.S.A.") != string::npos) {
      // Get index of first instance
      usaIndex = userText.find("U.S.A.");

      // U.S.A. is 6 long
      userText.replace(usaIndex, 6, "USA");
   }

   cout << "New text: " << userText<< endl;

   return 0;
}


int main() {
   string secretStr;
   unsigned int i;
   
   getline(cin, secretStr);

   for (i = 0; i < secretStr.length(); ++i) {
      
      if (isspace(secretStr.at(i))) {
         secretStr.at(i) = '/';
      }
      }

   cout << "Updated password: " << secretStr << endl;
   
   return 0;
}
int main() {
   string password;
   int i;
   int count;
   
   getline(cin, password);
   count = 0;
   
   for (i = 0; i < password.length(); ++i) {
      if (isdigit(password.at(i))) {
         count += 1;
      }
   }
   if ((count > 2) && (password.length() <= 10)) {
     cout << "Valid" << endl; 
   }  else {
      cout << "Invalid" << endl;
   }
   
   return 0;
}

int main() {
   string passPhrase;
   int index;
   
   cin >> passPhrase;

   index = 0;

   while (passPhrase.find("qwerty") != string::npos) {
      
      index = passPhrase.find("qwerty");
      
      passPhrase.replace(index, 6, "gljmpk");
   }

   cout << "Updated password: " << passPhrase << endl;
   
   return 0;
}


int main() {
   int firstInput;
   int secondInput;
   int count;
   int i;
   int j;

   cin >> firstInput;
   cin >> secondInput;

   count = 0;
   for (i = 0; i < firstInput; ++i) {
		for (j = 0; j < secondInput; ++j) {
         ++count;
      }
   }

   cout << "Inner loop ran " << count << " times" << endl;



   int main() {
   int initialValue;
	int finalValue;
   int i;
   int j;

   cin >> initialValue;
	cin >> finalValue;
   
   for (i = initialValue; i <= finalValue; ++i) {
      for (j = 0; j < i; ++j) {
         cout << '#';
      }
      cout << endl;
   }

   return 0;
}


char letter1;
char letter2;

letter1 = 'a';
while (letter1 <= 'f') {
   letter2 = 'c';
   while (letter2 <= 'f') {
      // Inner loop body
      ++letter2;
   }
   ++letter1;
}

#include <iostream>
#include <iomanip>
using namespace std;

double ComputeAverage(int numCount) {
   double valuesSum = 0;
   int currValue = 0;

   for (int i = 0; i < numCount; ++i) {
      cout << "Enter number: ";
      cin >> currValue;
      valuesSum += currValue;
   }
   return valuesSum / numCount;
}

int main() {
   int numValues;
   double averageVal;

   cout << "Enter number of values: ";
   cin >> numValues;
   averageVal = ComputeAverage(numValues);

   cout << "Average: ";
   cout << fixed << setprecision(3) << averageVal << endl;
   return 0;
}




#include <iostream>
#include <vector>
using namespace std;

int main() {
   int dataSize;
   unsigned int i;
   int intVal;
   string stringVal;

   cin >> dataSize;

   vector<int> quantityList;
   vector<string> groceryList;
   
   for (i = 0; i < dataSize; ++i) {
      cin >> intVal;
      quantityList.push_back(intVal);
   }
   
   for (i = 0; i < dataSize; ++i) {
      cin >> stringVal;
      groceryList.push_back(stringVal);
   }

   for (i = 0; i < quantityList.size(); ++i) {
      cout << "Quantity: " << quantityList.at(i) << ", ";
      cout << "Grocery: " << groceryList.at(i) << endl;
   }

   return 0;
}


#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> ageList;
   vector<string> userList;
   int numElements;
   int ageAsked;
   unsigned int i;
   int intVal;
   string stringVal;

   cin >> numElements;

   for (i = 0; i < numElements; ++i) {
      cin >> intVal;
      cin >> stringVal;

      ageList.push_back(intVal);
      userList.push_back(stringVal);
   }

   cin >> ageAsked;

   for (i = 0; i < numElements; ++i) {
   if (ageList[i] == ageAsked) {
      cout << "Index " << i << ": age " << ageList[i] << " is matched with user " << userList[i] << endl;
   }
   }

   return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> dataVect;
   int value;
   int i;
   int n;

   cin >> value;
   while (value != -1) {
      dataVect.push_back(value);
      cin >> value;
   }
   
   n = dataVect.back();
   for (i = 0; i < n; ++i) {
      cout << dataVect[i] << endl;
   }

   return 0;
}