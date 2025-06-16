#include <iostream>
    using namespace std;

    int main() {
        int hoursWorked;
        int paycheckAmount;
        int payrate;

        cout << "enter hours worked: ";
        cin >> hoursWorked;
        cout << "Enter rate of pay: ";
        cin >> payrate;
        paycheckAmount = hoursWorked * payrate;
        cout << "The amount of the paycheck is $"
             << paycheckAmount << " dollars." << endl;
    }

making a change