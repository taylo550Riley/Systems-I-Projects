// Copyright Riley Taylor
// Dr. Mahmoud
/* 
    Please refer to the readme provided for implementation.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include "PracticalSocket.h"  // For Socket, ServerSocket, and SocketException
#include "server.h"
using std::string;
using std::cout;
using std::endl;

void HandleTCPClient(TCPSocket *sock);  // TCP client handling function

static bool auth;  // Global auth variable

int main(int argc, char *argv[]) {
    if (argc != 2) {                     // Test for correct number of arguments
        cerr << "Usage: " << argv[0] << " <Server Port>" << endl;
        exit(1);
    }
    // First arg: local port
    int echoServPort = atoi(argv[1]);

    try {
        TCPServerSocket servSock(echoServPort);     // Server Socket object

        for (;;) {   // Run forever
            // Wait for a client to connect
            HandleTCPClient(servSock.accept());
        }
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
        exit(1);
    }

    return(0);
}

// TCP client handling function
void HandleTCPClient(TCPSocket *sock) {
    cout << "Handling client ";
    try {
        cout << sock->getForeignAddress() << ":";
    } catch (const std::exception& e) {
        cerr << "Unable to get foreign address" << endl;
        cerr << e.what() << endl;
    }
    try {
        cout << sock->getForeignPort();
    } catch (const std::exception& e) {
        cerr << "Unable to get foreign port" << endl;
        cerr << e.what() << endl;
    }
    cout << endl;
    if (!auth) {
        auth = true;
        char username[32];
        sock->recv(username, sizeof(username));
        char password[32];
        sock->recv(password, sizeof(password));

        string strLoginUN;
        string strLoginPW;
        ifstream usernameFile;
        ifstream passwordFile;
        // Traverse usernames file
        usernameFile.open("usernames.txt");
        bool id = false;
        bool pw = false;
        int usernameCount = 0;
        int usernamePlace = 0;
        while (usernameFile >> strLoginUN) {
            usernameCount++;
            if (strcmp(strLoginUN.c_str(), username) == 0) {
                id = true;
                usernamePlace = usernameCount;
            }
        }
        usernameFile.close();

        // Traverse passwords file
        passwordFile.open("passwords.txt");
        int passwordCount = 0;
        int passwordPlace = 0;
        while (passwordFile >> strLoginPW) {
            passwordCount++;
            if (strcmp(strLoginPW.c_str(), password) == 0) {
                pw = true;
                passwordPlace = passwordCount;
            }
        }
        passwordFile.close();

        // a 0 sent to client means successful login
        // a 1 sent to client means unsuccessful login
        if (id == true && pw == true &&
            usernamePlace == passwordPlace) {
                int i = 0;
                sock->send(&i, sizeof(i));
            } else {
                int i = 1;
                sock->send(&i, sizeof(i));
        }
    }
    /*
      Implementation of the switch cases, server side will handle the logic.
      Functions can be found in server.h and server.cpp

      case 1: prints quiz results from client

      case 2: calls numberConv to convert the binary number
      sent from the client.

      case 3: stores roll() results into a vector and
      prints results.
    */
    char switchCase;
    sock->recv(&switchCase, sizeof(switchCase));
    switch (switchCase) {
        case '1': {
            int quizResult;
            sock->recv(&quizResult, sizeof(&quizResult));
            cout << "Your quiz results: " << quizResult << "/5" << endl;;
            cout << endl;
            break;
        }
        case '2': {
            char binaryNumArr[32];
            sock->recv(binaryNumArr, sizeof(binaryNumArr));
            char *tmpPtr;
            char *binaryNumArrPtr = &binaryNumArr[0];
            // Calculating the actual size of user num.
            int size = 0;
            for (tmpPtr = binaryNumArrPtr; *tmpPtr != '\0';
                tmpPtr++) {
                size++;
            }
            numberConv(binaryNumArr, size);
            cout << endl;
            break;
        }
        case '3': {
            vector<int> rollResults = roll();
            cout << "4-sided die result: " << rollResults[0] << endl;
            cout << "6-sided die result: " << rollResults[1] << endl;
            cout << "8-sided die result: " << rollResults[2] << endl;
            cout << "12-sided die result: " << rollResults[3] << endl;
            cout << "20-sided die result: " << rollResults[4] << endl;
            cout << endl;
            break;
        }
        case '4': {
            auth = false;
            cout << endl;
            break;
        }
    }
    delete sock;
}
