/*
    This program will add a client to the database. It allows the user to provide
    relevant information about the client. After a client is added, it will
    redirect the user back to the functions page.
*/
#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <string>
#include <iostream>
#include "getpost.h"

using namespace std;

int main(int argc, char* argv[]) {

    map<string,string> Get;
    initializePost(Get);

    // Client information
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string address;

    // Pet information
    std::string petName;
    std::string breed;
    std::string age;
    std::string allergies;
    std::string size;
    std::string groomedBefore;
    std::string generalBehavior;
    std::string cageShy;
    std::string vet;
    if (Get.find("firstName")!=Get.end() && Get.find("lastName")!=Get.end() && Get.find("phoneNumber")!=Get.end()
        && Get.find("address")!=Get.end() && Get.find("petName")!=Get.end() && Get.find("breed")!=Get.end()
        && Get.find("age")!=Get.end() && Get.find("allergies")!=Get.end() && Get.find("size")!=Get.end() && Get.find("groomedBefore")!=Get.end()
        && Get.find("generalBehavior")!=Get.end() && Get.find("cageShy")!=Get.end() && Get.find("vet")!=Get.end()) {
            firstName = Get["firstName"];
            lastName = Get["lastName"];
            phoneNumber = Get["phoneNumber"];
            address = Get["address"];
            petName = Get["petName"];
            breed = Get["breed"];
            age = Get["age"];
            allergies = Get["allergies"];
            size = Get["size"];
            groomedBefore = Get["groomedBefore"];
            generalBehavior = Get["generalBehavior"];
            cageShy = Get["cageShy"];
            vet = Get["vet"];
    }

    // Connect to database with: database, server, userID, password
    mysqlpp::Connection conn(false); // Exceptions suppressed to keep code simple
    if(conn.connect("cse278", "localhost", "cse278", "MonSepM1am1")) {

        // Create a query
        mysqlpp::Query query = conn.query();

        query << "INSERT into 01757392Clients (firstName, lastName, phoneNumber, address, petName, breed, age, allergies, size, groomedBefore, generalBehavior, cageShy, vet) VALUES('"+firstName+"', '"+lastName+"', '"+phoneNumber+"', '"+address+"', '"+petName+"', '"+breed+"', '"+age+"', '"+allergies+"', '"+size+"', '"+groomedBefore+"', '"+generalBehavior+"', '"+cageShy+"', '"+vet+"');";
        query.parse();  // check to ensure it is correct

        // Run the query -- note INSERT does not return results so we are using SimpleResult
        mysqlpp::SimpleResult result = query.execute(firstName, lastName, phoneNumber, address,
        petName, breed, age, allergies, size, groomedBefore, generalBehavior, cageShy, vet);

        // Always check for errors
        if(result) {
            cout << "Content-type: text/html" << endl << endl;
            cout << "<html><head>" << endl;
            cout << "<head>" << endl;
            cout << "<meta charset=\"UTF-8\">" << endl;
            cout << "<title>Database Functions</title>" << endl;
            cout << "<link rel=\"stylesheet\" href=\"css/style.css\" media=\"screen\" type=\"text/css\" />" << endl;
            cout << "</head>" << endl;
            cout << "<p><br></br><font size=\"+3\"><pre>add successful, redirecting back functions page, please wait.</pre></font></p>" << endl;
            cout << "<meta http-equiv = \"refresh\" content = \"3; url = http://os1.csi.miamioh.edu/~taylo550/functions.cgi\" />" << endl;
            cout << "</head></html>" << endl;
        } else {
            cerr << "Query error: " << query.error() << endl;
        }
        return(0);
    } else {
        cerr << "Connection failed: " << conn.error() <<endl;
        return(1);
    }
}
