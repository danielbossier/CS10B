#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

// Include any necessary libraries here.

using namespace std;

int main() {
   ifstream inFS;
   string fileName;
   string photoName;

   cin >> fileName;

   inFS.open(fileName);

    if (!inFS.is_open()) {
        cout << fileName << " did not open." << endl;
        return 1;
    }

    while(getline(inFS, photoName)) {
        int pos = photoName.find("_photo.jpg");
        if (pos != string::npos) {
            photoName.replace(pos, 11, "_info.txt");
            cout << photoName << endl;
        }
    }


    inFS.close();

    return 0;
}


#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream inFS;
    string fileName;
    string lastName;
    string firstName;
    int midterm1;
    int midterm2;
    int finalScore;
    int averageScore;
    char letterGrade;
    double totalMidterm1 = 0;
    double midterm1Average;
    double totalMidterm2 = 0;
    double midterm2Average;
    double totalFinal = 0;
    double finalAverage;
    int numstudents = 0;
   /* TODO: Declare any necessary variables here. */
      
      
   /* TODO: Read a file name from the user and read the tsv file here. */
    cin >> fileName;

    inFS.open(fileName);

    if (!inFS.is_open()) {
        cout << fileName << " did not open." << endl;
        return 1;
    }

    ofstream outFS("report.txt");

    while(inFS >> lastName >> firstName >> midterm1 >> midterm2 >> finalScore) {
        averageScore = ((midterm1 + midterm2 + finalScore) / 3);
        if (averageScore >= 90) {
            letterGrade = 'A';
        } else if (averageScore >= 80) {
            letterGrade = 'B';
        } else if (averageScore >= 70) {
            letterGrade = 'C';
        } else if (averageScore >= 60) {
            letterGrade = 'D';
        } else if (averageScore < 60) {
            letterGrade = 'F';
        }
        outFS << lastName << '\t' << firstName <<  '\t' << midterm1 << '\t' << midterm2 << '\t' <<  finalScore << '\t' << letterGrade << endl;
        
        totalMidterm1 += midterm1;
        totalMidterm2 += midterm2;
        totalFinal += finalScore;
        ++numstudents;
        
    }
  
   /* TODO: Compute student grades and exam averages, then output results to a text file here. */
    
    outFS << fixed << setprecision(2);

    midterm1Average =  (totalMidterm1 / numstudents);
    midterm2Average = (totalMidterm2 / numstudents);
    finalAverage = (totalFinal / numstudents);
    
    outFS << endl << "Averages: midterm1 " << midterm1Average << ", midterm2 " << midterm2Average << ", final " << finalAverage << endl;

    inFS.close();
    outFS.close();

   return 0;
}




#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inFS;
    string fileName;
    string foodCategory;
    string foodName;
    string foodDescription;
    string line;
    string foodAvailability;

    cin >> fileName;

    inFS.open(fileName);

    if (!inFS.is_open()) {
        cout << fileName << " did not open." << endl;
        return 1;
    }

    while(getline(inFS, line)) {
        size_t tab1 = line.find('\t');
        size_t tab2 = line.find('\t', tab1 + 1);
        size_t tab3 = line.find('\t', tab2 + 1);

        foodCategory = line.substr(0, tab1);
        foodName = line.substr(tab1 + 1, tab2 - tab1 - 1);
        foodDescription = line.substr(tab2 + 1, tab3 - tab2 - 1);
        foodAvailability = line.substr(tab3 + 1);

        if (foodAvailability == "Available") {
            cout << foodName << " (" << foodCategory << ") -- " << foodDescription << endl;
        }
    }

    inFS.close();

   return 0;
}