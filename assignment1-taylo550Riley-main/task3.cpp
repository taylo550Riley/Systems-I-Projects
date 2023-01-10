// Copyright 2022
// Calculating pi
// Author: Riley Taylor

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

// This program will approximate the value of pi.
// The user will give the program number of points
// the more points the more accurate pi will be.
// This is a classic probability problem for pi.

int main() {
    double sqArea = 1;
    double circArea = M_PI * pow((sqArea / 2), 2) * 100;
    double circleHits = 0;
    int squareHits = 0;
    double userNum = 0;

    cout << "Welcome to the pi approximation program!" << endl;
    cout << "Enter number of dots you want to test: ";
    cin >> userNum;

    srand(time(0));
    for (int i = 0; i < userNum; i++) {
        int randNum = rand() % 100;  // random number from 0-100
        if (randNum < circArea) {
            circleHits++;
        } else {
            squareHits++;
        }
    }

    double approxPi = (circleHits / userNum) * 4;
    cout << "The number of dots you tested was " << userNum
        << " and your approximation of pi is " << approxPi << endl;

    cout << "Would you like to display the " <<
        "number of circle and square hits? (Y/N) ";
    char ans;
    cin >> ans;
    if (ans == 'Y' || ans == 'y') {
        cout << "Number of circle hits: " << circleHits << endl;
        cout << "Number of square hits: " << squareHits << endl;
    }

    return 0;
}
