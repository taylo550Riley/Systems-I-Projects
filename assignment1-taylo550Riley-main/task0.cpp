// Copyright 2022
// Add a description....
// ...
// Author: your name

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// add comments

int main() {
    char c;  // letter to encrypt
    char e;  // encrypted letter
    int k;   // cipher key
    cout << "Welcome to my encryption program" << endl;
    cout << "Enter an uppercase letter to encrypt: ";
    cin >> c;
    cout <<  "Enter a cipher key: ";
    cin >> k;
    e = (c - 'A' + k) % 26 + 'A';  // Caesar encryption formula
    cout << c << " with cipher key " << k << " is encrypted as: " << e << endl;
    return (0);
}
