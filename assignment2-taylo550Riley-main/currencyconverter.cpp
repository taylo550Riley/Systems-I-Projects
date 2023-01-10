// Copyright Riley Taylor
// Dr. Mahmoud
// implements functions for currencyconverterapp
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "cconverter.h"
using std::cout;
using std::endl;
using std::ofstream;
/*
    printMenu will print a menu for the user at
    program start.
*/
void printMenu() {
    cout << "Welcome to my currency converter program!" << endl;
    cout << "Please choose the currency you want to convert" << endl;
    cout << "1. USD" << endl;
    cout << "2. CAD" << endl;
    cout << "3. Euro" << endl;
    cout << "4. Pound sterling" << endl;
    cout << "5. Mexican peso" << endl;
    cout << "6. SK Won" << endl;
    cout << "7. Exit" << endl;
}
/*
    printToFile will print converted currencies to a
    user specified file. ceil will allow me to round the values
    from the vector passed to 2 decimal places. 
*/
void printToFile(std::vector<double> v, std::ofstream& outfile, double amount) {
    if (v[0] == 1) {
        outfile << "--- Converting " << amount << " USD ---" << endl;
        outfile << std::ceil(v[1] * 100) / 100 << "\tCanadian dollars" << endl;
        outfile << std::ceil(v[2] * 100) / 100 << "\tEuros" << endl;
        outfile << std::ceil(v[3] * 100) / 100 << "\tPound sterling" << endl;
        outfile << std::ceil(v[4] * 100) / 100 << "\tMexican pesos" << endl;
        outfile << std::ceil(v[5] * 100) / 100 << "\tSK Won";
    } else if (v[0] == 2) {
        outfile << "--- Converting " << amount << " CAD ---" << endl;
        outfile << std::ceil(v[1] * 100) / 100 << "\tUSD" << endl;
        outfile << std::ceil(v[2] * 100) / 100 << "\tEuros" << endl;
        outfile << std::ceil(v[3] * 100) / 100 << "\tPound sterling" << endl;
        outfile << std::ceil(v[4] * 100) / 100 << "\tMexican pesos" << endl;
        outfile << std::ceil(v[5] * 100) / 100 << "\tSK Won";
    } else if (v[0] == 3) {
        outfile << "--- Converting " << amount << " Euro ---" << endl;
        outfile << std::ceil(v[1] * 100) / 100 << "\tUSD" << endl;
        outfile << std::ceil(v[2] * 100) / 100 << "\tCAD" << endl;
        outfile << std::ceil(v[3] * 100) / 100 << "\tPound sterling" << endl;
        outfile << std::ceil(v[4] * 100) / 100 << "\tMexican pesos" << endl;
        outfile << std::ceil(v[5] * 100) / 100 << "\tSK Won";
    } else if (v[0] == 4) {
        outfile << "--- Converting " << amount << " Pound sterling ---" << endl;
        outfile << std::ceil(v[1] * 100) / 100 << "\tUSD" << endl;
        outfile << std::ceil(v[2] * 100) / 100 << "\tCAD" << endl;
        outfile << std::ceil(v[3] * 100) / 100 << "\tEuros" << endl;
        outfile << std::ceil(v[4] * 100) / 100 << "\tMexican pesos" << endl;
        outfile << std::ceil(v[5] * 100) / 100 << "\tSK Won";
    } else if (v[0] == 5) {
        outfile << "--- Converting " << amount << " Mexican pesos ---" << endl;
        outfile << std::ceil(v[1] * 100) / 100 << "\tUSD" << endl;
        outfile << std::ceil(v[2] * 100) / 100 << "\tCAD" << endl;
        outfile << std::ceil(v[3] * 100) / 100 << "\tEuros" << endl;
        outfile << std::ceil(v[4] * 100) / 100 << "\tPound sterling" << endl;
        outfile << std::ceil(v[5] * 100) / 100 << "\tSK Won";
    } else if (v[0] == 6) {
        outfile << "--- Converting " << amount << " SK Won ---" << endl;
        outfile << std::ceil(v[1] * 100) / 100 << "\tUSD" << endl;
        outfile << std::ceil(v[2] * 100) / 100 << "\tCAD" << endl;
        outfile << std::ceil(v[3] * 100) / 100 << "\tEuros" << endl;
        outfile << std::ceil(v[4] * 100) / 100 << "\tPound sterling" << endl;
        outfile << std::ceil(v[5] * 100) / 100 << "\tMexican pesos";
    }
    return;
}
/*
    printToScreen will print the information from the file
    to the screen depending if the user wants it to display.
    It follows the same logic as printToFile, but will not run
    if the user chooses not to.
*/
void printToScreen(bool toPrint, std::vector<double> v, double amount) {
    if (toPrint == true) {
        if (v[0] == 1) {
            cout << std::ceil(v[1] * 100) / 100 << "\tCanadian dollars" << endl;
            cout << std::ceil(v[2] * 100) / 100 << "\tEuros" << endl;
            cout << std::ceil(v[3] * 100) / 100 << "\tPound sterling" << endl;
            cout << std::ceil(v[4] * 100) / 100 << "\tMexican pesos" << endl;
            cout << std::ceil(v[5] * 100) / 100 << "\tSK Won" << endl;
        } else if (v[0] == 2) {
            cout << std::ceil(v[1] * 100) / 100 << "\tUSD" << endl;
            cout << std::ceil(v[2] * 100) / 100 << "\tEuros" << endl;
            cout << std::ceil(v[3] * 100) / 100 << "\tPound sterling" << endl;
            cout << std::ceil(v[4] * 100) / 100 << "\tMexican pesos" << endl;
            cout << std::ceil(v[5] * 100) / 100 << "\tSK Won" << endl;
        } else if (v[0] == 3) {
            cout << std::ceil(v[1] * 100) / 100 << "\tUSD" << endl;
            cout << std::ceil(v[2] * 100) / 100 << "\tCAD" << endl;
            cout << std::ceil(v[3] * 100) / 100 << "\tPound sterling" << endl;
            cout << std::ceil(v[4] * 100) / 100 << "\tMexican pesos" << endl;
            cout << std::ceil(v[5] * 100) / 100 << "\tSK Won" << endl;
        } else if (v[0] == 4) {
            cout << std::ceil(v[1] * 100) / 100 << "\tUSD" << endl;
            cout << std::ceil(v[2] * 100) / 100 << "\tCAD" << endl;
            cout << std::ceil(v[3] * 100) / 100 << "\tEuros" << endl;
            cout << std::ceil(v[4] * 100) / 100 << "\tMexican pesos" << endl;
            cout << std::ceil(v[5] * 100) / 100 << "\tSK Won" << endl;
        } else if (v[0] == 5) {
            cout << std::ceil(v[1] * 100) / 100 << "\tUSD" << endl;
            cout << std::ceil(v[2] * 100) / 100 << "\tCAD" << endl;
            cout << std::ceil(v[3] * 100) / 100 << "\tEuros" << endl;
            cout << std::ceil(v[4] * 100) / 100 << "\tPound sterling" << endl;
            cout << std::ceil(v[5] * 100) / 100 << "\tSK Won" << endl;
        } else if (v[0] == 6) {
            cout << std::ceil(v[1] * 100) / 100 << "\tUSD" << endl;
            cout << std::ceil(v[2] * 100) / 100 << "\tCAD" << endl;
            cout << std::ceil(v[3] * 100) / 100 << "\tEuros" << endl;
            cout << std::ceil(v[4] * 100) / 100 << "\tPound sterling" << endl;
            cout << std::ceil(v[5] * 100) / 100 << "\tMexican pesos" << endl;
        }
    } else {
        return;
    }
}
/*
    convert will convert whichever currency the user wants
    from the list. it will populate a vector so it can be used
    in printing to a file and/or to the screen.

    returns a double vector of converted currencies.

*/
std::vector<double> convert(int userChoice, double amount) {
    std::vector<double> v;
    v.push_back(userChoice);
    // USD to other
    if (userChoice == 1) {
        v.push_back(amount / 0.72);  // CAD
        v.push_back(amount * 1.03);  // Euro
        v.push_back(amount * 0.9);  // pound
        v.push_back(amount * 20.07);  // mxn peso
        v.push_back(amount * 1441.69);  // Won
        return v;
    // CAD to other
    } else if (userChoice == 2) {
        v.push_back(amount * 0.72);  // USD
        v.push_back(amount * 0.74);  // Euro
        v.push_back(amount * 0.64);  // pound
        v.push_back(amount * 14.46);  // mxn peso
        v.push_back(amount * 1038.35);  // Won
        return v;
    // Euro to other
    } else if (userChoice == 3) {
        v.push_back(amount * 0.97);  // USD
        v.push_back(amount * 1.35);  // CAD
        v.push_back(amount * 0.87);  // pound
        v.push_back(amount * 19.52);  // mxn peso
        v.push_back(amount * 1401.47);  // Won
        return v;
    // Pound to other
    } else if (userChoice == 4) {
        v.push_back(amount * 1.12);  // USD
        v.push_back(amount * 1.56);  // CAD
        v.push_back(amount * 1.15);  // Euro
        v.push_back(amount * 22.43);  // mxn peso
        v.push_back(amount * 1610.66);  // Won
        return v;
    // Mexican peso to other
    } else if (userChoice == 5) {
        v.push_back(amount * 0.05);  // USD
        v.push_back(amount * 0.069);  // CAD
        v.push_back(amount * 0.051);  // Euro
        v.push_back(amount * 0.045);  // pound
        v.push_back(amount * 71.78);  // Won
        return v;
    // SK Won to other
    } else if (userChoice == 6) {
        v.push_back(amount * 0.00069);  // USD
        v.push_back(amount * 0.00096);  // CAD
        v.push_back(amount * 0.00071);  // Euro
        v.push_back(amount * 0.00062);  // pound
        v.push_back(amount * 0.014);  // mxn peso
        return v;
    } else {
        return v;
    }
}
