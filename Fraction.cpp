#include <iostream>
using namespace std;

int main()
{
    int num = 202;
    int denom = 303;
    int i = 0;
    int lower = num;


    if (denom % num == 0) {
        int temp = num;
        num = num / num;
        denom = denom / temp;
    }
    if (num > denom) {
        lower = denom;
    }

    //cout << num << "/" << denom << endl;

    for (i = lower; i > 0; --i) {
        if (num % i == 0 && denom % i == 0) {
            num = num / i;
            denom = denom / i;
            break;
        }
    }
    cout << num << " / " << denom << endl;
}

    // if (num % 101 == 0 && denom % 101 == 0) {
    //     num = num / 101;
    //     denom = denom / 101;
    // }
    // if (num % 5 == 0 && denom % 5 == 0) {
    //     num = num / 5;
    //     denom = denom / 5;
    // }
    // if (num % 4 == 0 && denom % 4 == 0) {
    //     num = num / 4;
    //     denom = denom / 4;
    // }
    // if (num % 3 == 0 && denom % 3 == 0) {
    //     num = num / 3;
    //     denom = denom / 3;
    // }
    // if (num % 2 == 0 && denom % 2 == 0) {
    //     num = num / 2;
    //     denom = denom / 2;
    // }
    

    //cout << num << " / " << denom << endl;


