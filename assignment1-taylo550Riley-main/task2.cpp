// Copyright 2022
// 3 tails in a row
// Author: Riley Taylor

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// n will take in either a 0 (heads) or a 1 (tails).

int main() {
    int tailsCount = 0;  // keeps track of the number of tails in a row
    int finalCount = 0;  // keeps track of tries
    srand(time(0));      // used from Guessnumber.cc
    while (tailsCount != 3) {
    int n = rand() % 2;  // will produce either a 0 or 1
        if (n == 1) {
            cout << "Tails" << endl;
            tailsCount++;
        } else {
            cout << "Heads" << endl;
            tailsCount = 0;  // resets tail count
        }
            finalCount++;
    }
    cout << "Number of tries to get 3 consecutive tails: "
        << finalCount << endl;
    return 0;
}
