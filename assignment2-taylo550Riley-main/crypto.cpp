// Copyright Riley Taylor
// Dr. Mahmoud
// implements functions for the cryptoapp
#include <iostream>
#include <fstream>
#include <string>
#include "crypto.h"

using std::string;
using std::cerr;
using std::endl;
/*
    encrypt takes a character and adds 5
    to it's ascii value, if the value is greater
    than 'z' then it will loop back to 'a'.

    returns a char
*/
char encrypt(char c) {
    if (c >= 'a' && c <= 'z') {
        c = c % 97 + 5 + 'a';
        if (c > 'z') {
            c = c - 'z' + 'a' - 1;
        }
        return c;
    } else if (c >= 'A' && c <= 'Z') {
        c = c % 65 + 5 + 'A';
        if (c > 'Z') {
            c = c - 'Z' + 'A' - 1;
        }
        return c;
    } else {
        return c;
    }
}
/*
    decrypt takes a character and subtracts 5
    from it's ascii value, if the value is less than
    than 'a' then it will loop backwards from 'z'.

    returns a char
*/
char decrypt(char c) {
    if (c >= 'a' && c <= 'z') {
        c = c % 97 - 5 + 'a';
        if (c > 'z') {
            c = c % 97 - 5 + 'a';
        }
        if (c < 'a') {
            c = c + 'z' - 'a' + 1;
        }
        return c;
    } else if (c >= 'A' && c <= 'Z') {
        c = c % 65 - 5 + 'A';
        if (c < 'A') {
            c = c - 'A' + 'Z' + 1;
        }
        return c;
    } else {
        return c;
    }
}
/*
    stats takes a reference to an inputfile
    and will read information from the file including
    the characters, spaces, and lines
    
    returns a vector of the information.
*/
std::vector<int> stats(std::ifstream& infile) {
    if (infile.fail()) {
        cerr << "Error opening file\n";
        infile.close();
        exit(1);
    }
    infile.seekg(0, std::ios::beg);  // reset the file
    std::vector<int> v;
    int characters = 0;
    int words = 0;
    int lines = 0;
    string line;
    while (!infile.eof()) {
        getline(infile, line);
        lines++;
        words++;  // border case if word is at end of line
        int length = line.length();
        for (int i = 0; i < length; i++) {
            char c = line[i];
            if (c == ' ') {
                words++;
            }
            characters++;
        }
    }
    v.push_back(characters);
    v.push_back(words);
    v.push_back(lines);
    infile.close();
    return v;
}
