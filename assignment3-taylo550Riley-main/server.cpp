// Copyright Riley Taylor
// Dr. Mahmoud
// implements the functions of serverapp.cpp

#include <iostream>
#include <string>
#include <cmath>
#include <random>
#include <vector>
#include "server.h"
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
/*
    numberConv converts a binary number into an octal, decimal, and hex number.
    It takes an array of chars and the size of the array.
    This function utilizes the pow function provided by cmath.
*/
void numberConv(char conv[], int size) {
    int decValue = 0;
    int j = size - 1;
    char *tmpPtr;
    char *convPtr = &conv[0];
    for (tmpPtr = convPtr; *tmpPtr != '\0'; tmpPtr++) {
        if (*tmpPtr == '1') {
            decValue += pow(2, j);
        }
        j--;
    }
    cout << "Octal: " << std::oct << decValue << endl;
    cout << "Decimal: " << std::dec << decValue << endl;
    cout << "Hex: 0x" << std::hex << decValue << endl;
}
/*
    the roll function will roll 5 different kinds of dice and return
    their face value to the client. Utilizes a vector and
    std::random_device::operator() from the random header.
    rd() produces a true random number.
*/
vector<int> roll() {
    vector<int> rollResults;
    std::random_device rd;
    int fourSided = (rd() % 4) + 1;
    int sixSided = (rd() % 6) + 1;
    int eightSided = (rd() % 8) + 1;
    int twelveSided = (rd() % 12) + 1;
    int twentySided = (rd() % 20) + 1;

    rollResults.push_back(fourSided);
    rollResults.push_back(sixSided);
    rollResults.push_back(eightSided);
    rollResults.push_back(twelveSided);
    rollResults.push_back(twentySided);
    return rollResults;
}
