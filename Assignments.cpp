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


The program first reads integer licenseCount from input, representing the number of pairs of inputs to be read. Each pair has a string and an integer, representing the license's state and fee, respectively. One License object is created for each pair and added to vector licenseList. Output "Average license fee: ", followed by the average fee of all the License objects as an integer. End with a newline.

Ex: If the input is:

3
MO 178 GA 100 IN 295

then the output is:

Average license fee: 191

Note: The ArrayList has at least one element.

#include <iostream>
#include <vector>
using namespace std;

class License {
   public:
      void SetStateAndFee(string newState, int newFee);
		int GetFee() const;
   private:
      string state;
      int fee;
};

void License::SetStateAndFee(string newState, int newFee) {
   state = newState;
   fee = newFee;
}

int License::GetFee() const {
	return fee;
}

int main() {
   vector<License> licenseList;
   License currLicense;
   string currState;
   int currFee;
	int sumFee;
   int licenseCount;
   unsigned int i;

   cin >> licenseCount;
   for (i = 0; i < licenseCount; ++i) {
      cin >> currState;
      cin >> currFee;
      
      currLicense.SetStateAndFee(currState, currFee);
      licenseList.push_back(currLicense);
   }
	
	sumFee = 0;
   
   for (i = 0; i < licenseList.size(); ++i) {
      sumFee += licenseList[i].GetFee();
   }
   
   cout << "Average license fee: " << sumFee / licenseCount << endl;

   return 0;
}




#include <iostream>
using namespace std;

class Distance {
   public:
      Distance(int km = 0, int m = 0);
      void Print() const;
      Distance operator-(Distance rhs);
   private:
      int kilometers;
      int meters;
};

Distance::Distance(int km, int m) {
   kilometers = km;
   meters = m;
}

// No need to accommodate for overflow or negative values
Distance Distance::operator-(Distance rhs) {
   Distance differenceDistance;
   
   differenceDistance.kilometers = this->kilometers - rhs.kilometers;
   differenceDistance.meters = this->meters - rhs.meters;
      
   return differenceDistance;
}

void Distance::Print() const {
   cout << kilometers << " kilometers, " << meters << " meters";
}

int main() {
   int km1;
	int m1;
	int km2;
	int m2;
   
   cin >> km1;
	cin >> m1;
	cin >> km2;
	cin >> m2;
   
   Distance distance1(km1, m1);
	Distance distance2(km2, m2);
   
   Distance difference = distance1 - distance2;
   
   distance1.Print();
	cout << endl;
	distance2.Print();
	cout << endl;
	cout << "Difference: ";
	difference.Print();
	cout << endl;
   
   return 0;
}





#include <iostream>
using namespace std;

class Coordinate2D {
   public:
      Coordinate2D(double xCoord = 0.0, double yCoord = 0.0);
      void Print() const;
      Coordinate2D operator+(Coordinate2D rhs);
   private:
      double xCoordinate;
      double yCoordinate;
};

Coordinate2D::Coordinate2D(double xCoord, double yCoord) {
   xCoordinate = xCoord;
   yCoordinate = yCoord;
}

// No need to accommodate for overflow or negative values

Coordinate2D Coordinate2D::operator+(Coordinate2D rhs) {
   Coordinate2D totalCoordinate;
   
   totalCoordinate.xCoordinate = this->xCoordinate + rhs.xCoordinate;
   totalCoordinate.yCoordinate = this->yCoordinate + rhs.yCoordinate;
      
   return totalCoordinate;
}

void Coordinate2D::Print() const {
   cout << xCoordinate << ", " << yCoordinate;
}

int main() {
   double xCoord1;
	double yCoord1;
	double xCoord2;
	double yCoord2;
   
   cin >> xCoord1;
	cin >> yCoord1;
	cin >> xCoord2;
	cin >> yCoord2;
   
   Coordinate2D point1(xCoord1, yCoord1);
	Coordinate2D point2(xCoord2, yCoord2);
   
   Coordinate2D sum = point1 + point2;
   
   cout << "(";
	point1.Print();
	cout << ") + (";
	point2.Print();
	cout << ") = (";
	sum.Print();
	cout << ")" << endl;
   
   return 0;
}


#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> colorIntensityVector = { 31, 249, 124, 36, 223, 156, 71, 99, 135, 171, 236 };
   int vIndex;
   int colorIntensity;

   try {
      cin >> vIndex;
      colorIntensity = colorIntensityVector.at(vIndex);
      cout << "Color intensity: " << colorIntensity << " at index " << vIndex << endl;
   }

   catch (out_of_range& excpt) {
      cout << "Error: colorIntensityVector index invalid" << endl;
   }

   return 0;
}


#include <iostream>
#include <fstream>
#include <ios>
#include <string>
using namespace std;

int main() {
   string garlicFileName;
   ifstream fileStream;
   int garlicValue;

   cin >> garlicFileName;
   fileStream.exceptions(ifstream::failbit);

   try {
      fileStream.open(garlicFileName);

      fileStream >> garlicValue;
      cout << "Value read from " << garlicFileName << ": " << garlicValue << endl;
   }
	catch (ios_base::failure& excpt) {
		cout << "Failed: " << excpt.what() << endl;
	}

   // Closes the opened file
   if (fileStream.is_open()) {
      fileStream.close();
   }

   return 0;
}


#include <string>
#include <iostream>

using namespace std;

int main() {
   string inputName;
   int age;
   // Set exception mask for cin stream
   cin.exceptions(ios::failbit);

   cin >> inputName;
   while(inputName != "-1") {
      try {
        cin >> age;
        cout << inputName << " " << (age + 1) << endl;
      }

      catch (ios_base::failure& excpt) {
        age = 0;
        cout << inputName << " " << age << endl;
        cin.clear();
        string garbage;
        getline(cin, garbage);
      }

      cin >> inputName;
   }
   
   return 0;
}



#include <iostream>
#include <vector>
#include <stdexcept>      // For std::out_of_range
using namespace std;

int main() {
   vector<string> names = { "Ryley", "Edan", "Reagan", "Henry", "Caius", "Jane", "Guto", "Sonya", "Tyrese", "Johnny" };
   int index;

   
   try {
        cin >> index;
        cout << names.at(index) << endl;
    }
    catch (out_of_range& excpt) {
        if (index < 0) {
            cout << "Exception! " << excpt.what() << endl;
            cout << "The closest name is: " << names[0] << endl;
        }
        else if (index > 9) {
            cout << "Exception! " << excpt.what() << endl;
            cout << "The closest name is: " << names[9] << endl;
        }
    }

   return 0;
}

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
   int userNum;
   int divNum;
   int result;
   cin.exceptions(ios::failbit);       // Allow cin to throw exceptions


    try {
        cin >> userNum;
        cin >> divNum;

        if (divNum == 0) {
            throw runtime_error("Divide by zero!");
        }

        result = userNum / divNum;
        cout << result << endl;
    }
    catch (ios_base::failure& excpt) {
	    cout << "Input Exception: " << excpt.what() << endl;
    }
    catch (runtime_error& excpt) {
        cout << "Runtime Exception: " << excpt.what() << endl;
    }

   return 0;
}


#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

double StepsToMiles(int steps) {
    double milesWalked;

    if (steps < 0) {
        throw runtime_error("Exception: Negative step count entered.");
    }

    milesWalked = steps / 2000.00;
    return milesWalked;
}

int main() {
    double result;
    int userEnteredSteps;

    try {
        cin >> userEnteredSteps;
        result = StepsToMiles(userEnteredSteps);

        cout << fixed << setprecision(2) << result << endl;
    }

    catch (runtime_error& excpt) {
        cout << excpt.what() << endl;
    }

    return 0;
}




#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
using namespace std;

string FindID(string name, ifstream &infoFS) {
    string currentName;
    string currentId;

    infoFS.clear();

    while (infoFS >> currentName >> currentId) {
        if (currentName == name) {
            return currentId;
        }
    }

    throw runtime_error("Student ID not found for " + name);
   
}

string FindName(string ID, ifstream &infoFS) {
    string currentName;
    string currentId;

    while (infoFS >> currentName >> currentId) {
        if (currentId == ID) {
            return currentName;
        }
    }

    throw runtime_error("Student name not found for " + ID);
   
}

int main() {
   int userChoice;
   string studentName;
   string studentID;
   
   string studentInfoFileName;
   ifstream studentInfoFS;
   
   // Read the text file name from user
   cin >> studentInfoFileName;
   
   // Open the text file
   studentInfoFS.open(studentInfoFileName);
   
   // Read search option from user. 0: FindID(), 1: FindName()
   cin >> userChoice;

   // FIXME: FindID() and FindName() may throw an Exception.
   //        Insert a try/catch statement to catch the exception and output the exception message.
   try {
   if (userChoice == 0) {
      cin >> studentName;
      studentID = FindID(studentName, studentInfoFS);
      cout << studentID << endl;
   }
   else {
      cin >> studentID;
      studentName = FindName(studentID, studentInfoFS);
      cout << studentName << endl;
   }
   }
   catch (runtime_error& excpt) {
        cout << excpt.what() << endl;
    }

   studentInfoFS.close();
   return 0;
}



#include <fstream>
#include <ios>
#include <iostream>
#include <string>

using namespace std;

void add_student(const string &roster) {
   try{
      ofstream rosterOutput(roster, ios::app);
      rosterOutput.exceptions(ios::failbit);

      rosterOutput << "Smith,John,24,12345678" << endl;
   }
   catch (ios_base::failure& excpt) {
      cout << "Permission Error: " << excpt.what() << endl;
   }

}

int main() {
   string rosterFileName;
   cin >> rosterFileName;

   add_student(rosterFileName);

   return 0;
}



#include <iostream>
#include <string>
#include <vector>
using namespace std;

void FindMiddle(vector<string> nationItems, string targetNation, int lowIndex, int highIndex) {
   int midIndex;
   int rangeSize;
   string midValue;

   cout << "Searching range from index " << lowIndex << " to " << highIndex << endl;

   rangeSize = (highIndex - lowIndex) + 1;
   midIndex = (lowIndex + highIndex) / 2;
   midValue = nationItems.at(midIndex);

   if (targetNation == midValue) {
      cout << targetNation << " is found at index " << midIndex << endl;
   }
   else if (rangeSize == 1) {
      cout << targetNation << " is not in the list" << endl;
   }
   else {

      if (targetNation < midValue) {

         FindMiddle(nationItems, targetNation, lowIndex, midIndex);
         
      }
      else {

         FindMiddle(nationItems, targetNation, midIndex + 1, highIndex);

      }

   }
}

int main() {
   string targetNation;
   vector<string> dataList;
   int numData;
   int i;
   string item;

   cin >> targetNation;
   cin >> numData;
   for (i = 0; i < numData; ++i) {
      cin >> item;
      dataList.push_back(item);
   }

   FindMiddle(dataList, targetNation, 0, dataList.size() - 1);

   return 0;
}
