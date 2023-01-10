/*
    This program takes the information from remove.html to fully remove
    the name given from the client's database. After removing, the user
    will be redirectly back to functions to choose another function.
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
    
    std::string firstName;
    std::string lastName;
    if (Get.find("firstName")!=Get.end() && Get.find("lastName")!=Get.end()) {
        firstName = Get["firstName"];
        lastName = Get["lastName"];
    }
    // Connect to database with: database, server, userID, password
    mysqlpp::Connection conn(false); // Exceptions suppressed to keep code simple
    if(conn.connect("cse278", "localhost", "cse278", "MonSepM1am1")) {
        // Create a query
        mysqlpp::Query query = conn.query();
        // keep track of deleted clients.
        query << "DELETE FROM 01757392Clients WHERE firstName = '"+firstName+"' AND lastName = '"+lastName+"'";

        // Check the query for correctness
        query.parse();

        // Run the query and get the result
        mysqlpp::StoreQueryResult result = query.store();

        cout << "Content-type: text/html" << endl << endl;
        cout << "<html><head>" << endl;
        cout << "<title>delete client info</title>" << endl;
        cout << "<head>" << endl;
        cout << "<meta charset=\"UTF-8\">" << endl;
        cout << "<title>Removing client</title>" << endl;
        cout << "<link rel=\"stylesheet\" href=\"css/style.css\" media=\"screen\" type=\"text/css\" />" << endl;
        cout << "</head>" << endl;
        cout << "<p><br></br><font size=\"+3\"><pre> Client successfully removed, please wait. </pre></font></p>" << endl;
        cout << "<meta http-equiv = \"refresh\" content = \"2; url = http://os1.csi.miamioh.edu/~taylo550/functions.cgi\" />" << endl;
    }
}
