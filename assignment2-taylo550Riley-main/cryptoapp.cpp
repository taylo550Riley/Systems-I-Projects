// Copyright Riley Taylor
// Dr. Mahmoud
// This program will decrypt or encrypt a text file
// and its output in another text file.
#include <iostream>
#include <vector>
#include <fstream>
#include "crypto.h"
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;

void printMenu();  // prints menu when program starts

int main() {
    int userChoice;
    int count = 0;
    string inFile;
    string outFile;
    string line;
    vector<int> v;
    // check to see if the user wants to exit
    // if not, print the menu again.
    bool exitSwitch = false;
    while (!exitSwitch) {
        printMenu();
        cin >> userChoice;
        if (userChoice != 1 && userChoice != 2 && userChoice != 3) {
            cerr << endl << "Wrong input, please enter your choice again."
                << endl << endl;
        }

        switch (userChoice) {
            // Encryption case
            case 1:
                {
                // User enters input and output files
                cout << "Enter the input file to encrypt: ";
                cin >> inFile;
                ifstream inputfile(inFile);
                if (inputfile.fail()) {
                    cerr << "Error opening file\n";
                    inputfile.close();
                    exit(1);
                }
                cout << "Enter output file name: ";
                cin >> outFile;
                ofstream outputfile(outFile);
                if (!outputfile.is_open()) {
                    cerr << "Could not open file " << outFile << endl;
                    outputfile.close();
                    exit(1);
                }
                // calls encrypt in crypto.cpp
                while (!inputfile.eof()) {
                    getline(inputfile, line);
                    if (count > 0) {
                        outputfile << endl;
                    }
                    count++;
                    int length = line.length();
                    for (int i = 0; i < length; i++) {
                        char c = line[i];
                        outputfile << encrypt(c);
                    }
                }
                cout << endl <<  "The program has processed \""
                << inFile << "\"" << endl;
                v = stats(inputfile);
                cout << v[0] << " characters" << endl;
                cout << v[1] << " words" << endl;
                cout << v[2] << " lines\n" << endl;
                inputfile.close();
                outputfile.close();
                count = 0;
                break;
                }

            // Decryption case
            case 2:
                // User enters input and output files
                {
                cout << "Enter the input file to decrypt: ";
                cin >> inFile;
                ifstream inputfile(inFile);
                if (inputfile.fail()) {
                    cerr << "Error opening file\n";
                    inputfile.close();
                    exit(1);
                }
                cout << "Enter output file name: ";
                cin >> outFile;
                ofstream outputfile(outFile);
                if (!outputfile.is_open()) {
                    cerr << "Could not open file " << outFile << endl;
                    exit(1);
                }
                // calls decrypt in crypto.cpp
                while (!inputfile.eof()) {
                    getline(inputfile, line);
                    if (count > 0) {
                        outputfile << endl;
                    }
                    count++;
                    int length = line.length();
                    for (int i = 0; i < length; i++) {
                        char c = line[i];
                        outputfile << decrypt(c);
                    }
                }
                cout << endl <<  "The program has processed \""
                << inFile << "\"" << endl;
                v = stats(inputfile);
                cout << v[0] << " characters" << endl;
                cout << v[1] << " words" << endl;
                cout << v[2] << " lines\n" << endl;
                inputfile.close();
                outputfile.close();
                count = 0;
                break;
            }
            case 3:
                return 0;
        }
    }
    return 0;
}


void printMenu() {
    cout << "Welcome to My Cryptographic Techniques" << endl;
    cout << "Please enter your selection" << endl;
    cout << "1. Encrypt" << endl;
    cout << "2. Decrypt" << endl;
    cout << "3. Exit" << endl;
}
