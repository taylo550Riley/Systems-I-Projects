// Copyright Riley Taylor
// Dr. Mahmoud
// header file for currency converter
#include <vector>
#include <fstream>
#ifndef CCONVERTER_H_
#define CCONVERTER_H_
// prints menu when program starts
void printMenu();
// optional print to screen for the user
void printToScreen(bool toPrint, std::vector<double> v, double amount);
// prints information to an output file
void printToFile(std::vector<double> v, std::ofstream &outfile, double amount);
// holds converted currencies in a vector
std::vector<double> convert(int userChoice, double amount);
#endif  // CCONVERTER_H_
