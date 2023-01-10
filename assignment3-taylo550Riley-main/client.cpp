// Copyright Riley Taylor
// Dr. Mahmoud
// implements the functions of clientapp.cpp

#include <iostream>
#include <bitset>
#include <string>
#include "client.h"
using std::cout;
using std::cin;
using std::string;
using std::endl;
/*
    printMenu will print a switch statement menu
    for the user at program start.
*/
void printMenu() {
    cout << "\nWelcome to my client/server application." << endl;
    cout << "1. C++ mini quiz!" << endl;
    cout << "2. Convert binary to other bases." << endl;
    cout << "3. Roll different sided dice." << endl;
    cout << "4. Exit" << endl;
    cout << "Enter a number to proceed: ";
}

/*
* quiz will prompt the user to answer 5 basic C++ questions.
* The function will keep track of the user's correct answers
* and will return the total score out of 5 possible points.
* The client will send the results to the server to print.
*/
int quiz() {
    int count = 0;
    char answer;
    cout << "\n1) What is the output of this program?" << endl;
    cout << "\tint x = 5;\n\tint *ptr = &x;" << endl;
    cout << "\tx = x* (*p);\n\tcout << p;" << endl;
    cout << "1. 25\n2. 5\n3. Compile error\n4. Run time error" << endl;
    cout << "Your answer: ";
    cin >> answer;
    while (answer != '1' && answer != '2' &&
            answer != '3' && answer != '4') {
                cout << "answer = " << answer << endl;
        cout << "\nPlease choose either 1, 2, 3, or 4: ";
        cin >> answer;
    }
    if (answer == '1') {
        count++;
    }
    cout << "\n2) Convert the following binary number to hex" << endl;
    cout << "100101101101000" << endl;
    cout << "1. 0x0D69" << endl;
    cout << "2. 0x96D0" << endl;
    cout << "3. 0x4B68" << endl;
    cout << "4. 0x86B4" << endl;
    cout << "Your answer: ";
    cin >> answer;
    while (answer != '1' && answer != '2' &&
            answer != '3' && answer != '4') {
        cout << "\nPlease choose either 1, 2, 3, or 4: ";
        cin >> answer;
    }
    if (answer == '3') {
        count++;
    }

    cout << "\n3) What is the output of this program?" << endl;
    cout << "\tint arr[] = {5,6,2,3};" << endl;
    cout << "\tint *ptr = (arr + 2);" << endl;
    cout << "\tcout << *ptr + 4;" << endl;
    cout << "1. 10\n2. 6\n3. 7\n4. 8" << endl;
    cout << "Your answer: ";
    cin >> answer;
    while (answer != '1' && answer != '2' &&
            answer != '3' && answer != '4') {
        cout << "\nPlease choose either 1, 2, 3, or 4: ";
        cin >> answer;
    }
    if (answer == '2') {
        count++;
    }

    cout << "\n4) Given the following code:" << endl;
    cout << "\tint arrayList[5];\n\tvector<int> vectorList(5);" << endl;
    cout << "arrayList[6] = 777 will yield a compiler error." << endl;
    cout << "1. True\n2. False" << endl;
    cout << "Your answer: ";
    cin >> answer;
    while (answer != '1' && answer != '2') {
        cout << "\nPlease choose either 1 or 2: ";
        cin >> answer;
    }
    if (answer == '2') {
        count++;
    }

    cout << "\n5) Using the same code from the previous question:" << endl;
    cout << "vectorList[6] = 777 will yield a compiler error." << endl;
    cout << "1. True\n2. False" << endl;
    cout << "Your answer: ";
    cin >> answer;
    while (answer != '1' && answer != '2') {
        cout << "\nPlease choose either 1 or 2: ";
        cin >> answer;
    }
    if (answer == '2') {
        count++;
    }
    return count;
}
