// Copyright Riley Taylor
// Dr. Mahmoud
// header file for task1
#include <vector>
#include <fstream>
#ifndef CRYPTO_H_
#define CRYPTO_H_
// given a char c return the encrypted character
char encrypt(char c);
// given a char c retun the decrypted character
char decrypt(char c);
// given a reference to an open file,
// return a vector with the # of characters, words, lines
std::vector<int> stats(std::ifstream& infile);
#endif  // CRYPTO_H_
