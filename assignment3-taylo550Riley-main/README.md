[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9123570&assignment_repo_type=AssignmentRepo)

Riley Taylor
Dr. Mahmoud
Programming assignment 3

I have tried to implement most of the things we have learned so far in this project. Listing them here:
    - Loops (while/for/if)
    - File I/O
    - Pointers
    - strcmp
    - similar rand() function
    - client/server
    - vector / arrays
    - switch statements
    - header files
    - makefile
    - math functions and number conversion functions

Clientapp implementation:

    clientapp is the client side of the project that handles mostly the user's choice when choosing a function. client.cpp has clientapp functions which are listed in client.h. The switch case has explanations within that file for each case. I have implemented a while loop that will constantly refresh the sock once the user is finished with one of the functions. It will also check if the user has logged in or not, if the user closes the client and then re-opens the client, they must re-enter authentication in order to access the functions. The server will not close if the user chooses to exit the client. Switch cases are accessed with chars rather than integers because of odd c++ errors with integers and switch cases.

Serverapp implementation:

    serverapp is the server side of the project that handles information sent from the client. server.cpp has serverapp functions which are listed in server.h. The server will receive which switch case the user chose and will run the appropriate function. The authentiction will keep track of if the user is first entering the client and will not ask again until client is exited. Explanations of the switch statements are provided in serverapp.cpp and are relatively straight forward. Switch cases are accessed with chars rather than integers because of odd c++ errors with integers and switch cases.

makefile:

    make all
        makes the server and client

    make run-
        runs the server or client

    make cpplint-
        runs cpplint on server or client files
        excluded: practicalsocket files