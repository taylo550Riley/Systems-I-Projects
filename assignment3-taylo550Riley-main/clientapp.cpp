// Copyright Riley Taylor
// Dr. Mahmoud
/* 
    Please refer to the readme provided for implementation.
*/

#include <iostream>           // For cerr and cout
#include <cstring>
#include "PracticalSocket.h"  // For Socket and SocketException
#include "client.h"

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char *argv[]) {
    if (argc != 3) {     // Test for correct number of arguments
        cerr << "Usage: " << argv[0]
             << "./client <Server Name> <Server Port#>" << endl;
        exit(1);
    }

    string servAddress = argv[1];  // First arg: server address
    unsigned int echoServPort = (atoi(argv[2]));
    char switchCase;
    bool loop = true;
    bool auth = false;
    try {
        while (loop) {
        // Establish connection with the echo server
        TCPSocket sock(servAddress, echoServPort);
        // Authentication -------
        if (auth == false) {
            string username;
            string password;
            cout << "Sign in to continue." << endl;
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;
            char usernameArr[32];
            int usernameSize = username.length();
            int passwordSize = password.length();
            for (int i = 0; i < usernameSize; i++) {
                usernameArr[i] = username[i];
            }
            usernameArr[username.length()] = '\0';
            char passwordArr[32];
            for (int i = 0; i < passwordSize; i++) {
                passwordArr[i] = password[i];
            }
            passwordArr[password.length()] = '\0';
            sock.send(usernameArr, 32);
            sock.send(passwordArr, 32);

            int checkAuth;
            sock.recv(&checkAuth, sizeof(checkAuth));
            if (checkAuth == 1) {
                cout << "Username or password is incorrect." << endl;
                exit(0);
            } else {
                cout << "Login successful." << endl;
                auth = true;
            }
        }
        // end Authentication --------
        printMenu();
        cin >> switchCase;
        cout << endl;

        /*
            case 1: user chooses quiz, handeled mostly by client.
            the results are sent to the server to print.

            case 2: user chooses binary number conversion.
            sends a char array.

            case 3: user chooses dice rolls, only sends
            the switch case to the server.

            case 4: user chooses to exit the program.
            The server will stay up, must be closed manually.
        */
        switch (switchCase) {
            // quiz case
            case '1': {
                sock.send(&switchCase, sizeof(switchCase));
                int quizResult = quiz();
                sock.send(&quizResult, sizeof(quizResult));
                break;
            }
            // binary conversion case max length of 31
            case '2': {
                string binaryNum;
                cout << "Please enter a binary number to convert: ";
                cin >> binaryNum;
                int len = binaryNum.length();
                // limiting to 31 because 2^31 will be max int val.
                if (len > 31) {
                    cout << "Please choose a " <<
                            "smaller binary number next time.\n";
                    break;
                }
                bool notBinary = false;
                for (int i = 0; i < len; i++) {
                    if (binaryNum[i] != '0' && binaryNum[i] != '1') {
                        notBinary = true;
                        break;
                    }
                }
                if (notBinary) {
                    cout << "This is not a binary number." << endl;
                    break;
                }
                char binaryNumArr[32];
                for (int i = 0; i < len; i++) {
                    binaryNumArr[i] = binaryNum[i];
                }
                binaryNumArr[len] = '\0';
                sock.send(&switchCase, sizeof(switchCase));
                sock.send(binaryNumArr, 32);
                break;
            }
            case '3': {
                sock.send(&switchCase, sizeof(switchCase));
                break;
            }
            case '4': {
                sock.send(&switchCase, sizeof(switchCase));
                cout << "Goodbye!" << endl;
                exit(0);
            }
        }
    }
    } catch(std::exception &e) {
        cerr << e.what() << endl;
        exit(1);
    }

    return(0);
}
