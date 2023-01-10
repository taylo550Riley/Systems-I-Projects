/*
 * This program shows how to use the MySQL++ wrapper for the MySQL C APIs.
 * It connects a CGI program to a MySQL database.
 * Author: Qusay Mahmoud
 
    This program is used to process register.html when a user submits an
    account to be registered. It is a fairly simple program that will
    store user's registration information to a table in mysql. After processing,
    the program will reroute the user back to the login page where they can
    login with the new information they registered.
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

    std::string username;
    std::string password;
    std::string email;
    std::string firstName, lastName;
    std::string streetAddress, city, state, zipCode, country;
    if (Get.find("username")!=Get.end() && Get.find("password")!=Get.end() && Get.find("email")!=Get.end()
        && Get.find("firstName")!=Get.end() && Get.find("lastName")!=Get.end() && Get.find("streetAddress")!=Get.end()
        && Get.find("city")!=Get.end() && Get.find("state")!=Get.end() && Get.find("zipCode")!=Get.end()
        && Get.find("country")!=Get.end()) {
            username = Get["username"];
            password = Get["password"];
            email = Get["email"];
            firstName = Get["firstName"];
            lastName = Get["lastName"];
            streetAddress = Get["streetAddress"];
            city = Get["city"];
            state = Get["state"];
            zipCode = Get["zipCode"];
            country = Get["country"];
    }

    // Connect to database with: database, server, userID, password
    mysqlpp::Connection conn(false); // Exceptions suppressed to keep code simple
    if(conn.connect("cse278", "localhost", "cse278", "MonSepM1am1")) {

        // Create a query
        mysqlpp::Query query = conn.query();

        query << "INSERT into 01757392Users (username, password, email, firstName, lastName, streetAddress, city, state, zipCode, country) VALUES('"+username+"', "
                "'"+password+"', '"+email+"', '"+firstName+"', '"+lastName+"', '"+streetAddress+"', "
                "'"+city+"', '"+state+"', '"+zipCode+"', '"+country+"');";

        query.parse();  // check to ensure it is correct

        // Run the query -- note INSERT does not return results so we are using SimpleResult
        mysqlpp::SimpleResult result = query.execute(username, password, email, firstName,
        lastName, streetAddress, city, state, zipCode, country);

        // Redirects back to login page after registration
        if(result) {
            cout << "Content-type: text/html" << endl << endl;
            cout << "<html><head>" << endl;
            cout << "<head>" << endl;
            cout << "<meta charset=\"UTF-8\">" << endl;
            cout << "<title>Database Functions</title>" << endl;
            cout << "<link rel=\"stylesheet\" href=\"css/style.css\" media=\"screen\" type=\"text/css\" />" << endl;
            cout << "</head>" << endl;
            cout << "<p><br></br><font size=\"+3\"><pre> Registration successful, redirecting back to log-in page, please wait. </pre></font></p>" << endl;
            cout << "<meta http-equiv = \"refresh\" content = \"3; url = http://os1.csi.miamioh.edu/~taylo550/index.html\" />" << endl;
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
