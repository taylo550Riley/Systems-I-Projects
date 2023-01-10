// Copyright Riley Taylor
// Dr. Mahmoud
/* 
    This program will convert different kinds of currencies to
    other currencies. It will also feature file writing to store
    the data from the conversions. The currency conversions will be
    hard-coded and values will reflect values from October 15th. The
    program also utilizes vectors.

    The user will be able to choose a few things throughout the program.
        1) What currency and amount to convert
        2) Optional print to screen/console
        3) What output file to write to
    
    This program is useful for outputting more than just 1 currency conversion.
*/
#include <iostream>
#include <fstream>
#include "cconverter.h"
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::ofstream;

int main() {
    int userChoice;
    double amount = 0.0;
    char print;
    bool toPrint = false;
    string outFile;
    printMenu();
    // Terminate the program if the user chooses a value
    // outside of the menu.
    cin >> userChoice;
        if (userChoice < 1 || userChoice > 7) {
            cerr << endl << "Wrong input, please run the program again."
                << endl << endl;
            exit(1);
        } else if (userChoice == 7) {
            return 0;
        }
    // Output file to store converted currency values.
    cout << "Enter output file name to print results to: ";
        cin >> outFile;
        ofstream outputfile(outFile);
        if (!outputfile.is_open()) {
            cerr << "Could not open file " << outFile << endl;
            exit(1);
        }
    // Optional print to screen
    cout << "Would you like the print the results to the screen? (Y/N): ";
    cin >> print;
    if (print != 'Y' && print != 'y'
        && print != 'N' && print != 'n') {
            cerr << endl << "Wrong input, expected Y or N."
            << endl << endl;
            return 0;
        } else {
            toPrint = true;
        }
    // Allows the user to convert a specific amount
    cout << "How much would you like to convert? $";
    cin >> amount;
    while (amount < 0) {
        cout << "Please re-enter a positive number to convert: ";
        cin >> amount;
    }
    cout << endl;
    printToFile(convert(userChoice, amount), outputfile, amount);
    printToScreen(toPrint, convert(userChoice, amount), amount);
    cout << endl;
    return 0;
}
