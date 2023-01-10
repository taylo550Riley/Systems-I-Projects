// Copyright 2022
// Bitwise operators, powers of 2, even/odd
// Author: Riley Taylor

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// This program will figure out if a user input
// number is even or odd and if it is a power of 2.

int main() {
    int num = 0;

    cout << "Enter an unsigned number: ";
    cin >> num;

    if ((num & 1) == 1) {
        cout << num << " is an odd number" << endl;
    } else {
        cout << num << " is an even number" << endl;
    }

    // num & num - 1 should be all zeros if it
    // is a power of 2.
    if ((num & (num - 1)) == 0) {
        cout << num << " is a power of 2" << endl;
    } else {
        cout << num << " is not a power of 2" << endl;
    }
    return 0;
}
