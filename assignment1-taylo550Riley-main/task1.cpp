// Copyright 2022
// Decryption of a single letter
// Author: Riley Taylor

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Decryption of task0

int main() {
    char c;  // decrypted letter
    char e;  // letter to decrypt
    int k;   // cipher key
    cout << "Welcome to my decryption program" << endl;
    cout << "Enter an uppercase letter to decrypt: ";
    cin >> c;
    cout <<  "Enter a cipher key: ";
    cin >> k;
    e = (((c - 'A' - k) % 26) + 26) % 26 + 'A';  // Decryption formula
    cout << c << " with cipher key " << k << " is decrypted as: " << e << endl;
    return (0);
}
