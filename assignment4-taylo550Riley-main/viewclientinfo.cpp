/*
    This program allows the user to view a specified client's information.
    The user must type in the correct first and last name of the client in order
    to successfully pull up the information. The information will be displayed
    nicely in a table. If the user does not exist, then the table will not display
    any information and the user must return and try again with different information.
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
    //std::string petName;
    if (Get.find("firstName")!=Get.end() && Get.find("lastName")!=Get.end()) {
        firstName = Get["firstName"];
        lastName = Get["lastName"];
    }
    // Connect to database with: database, server, userID, password
    mysqlpp::Connection conn(false); // Exceptions suppressed to keep code simple
    if(conn.connect("cse278", "localhost", "cse278", "MonSepM1am1")) {
        // Create a query
        mysqlpp::Query query = conn.query();
        query << "SELECT * FROM 01757392Clients WHERE firstName = '"+firstName+"' AND lastName = '"+lastName+"'";

        // Check the query for correctness
        query.parse();

        // Run the query and get the result
        mysqlpp::StoreQueryResult result = query.store();

        // Creates table for specified client's information
        if(result) {
        cout << "Content-type: text/html" << endl << endl;
        cout << "<html><head>" << endl;
        cout << "<title>Client info</title>" << endl;
        cout << "<head>" << endl;
        cout << "<meta charset=\"UTF-8\">" << endl;
        cout << "<title>Database Functions</title>" << endl;
        cout << "<link rel=\"stylesheet\" href=\"css/style.css\" media=\"screen\" type=\"text/css\" />" << endl;
        cout << "</head>" << endl;
        cout << "<style>" << endl;
        cout << "table, th, td {" << endl;
        cout << "border: 2px solid;" << endl;
        cout << "}" << endl;
        cout << "</style>" << endl;
        cout << "<table width: 100%; table-layout:fixed><th>First Name&emsp;&emsp;</th><th>Last Name&emsp;&emsp;</th><th>Phone Number&emsp;&emsp;</th><th>Address&emsp;&emsp;</th><th>Pet Name&emsp;&emsp;</th><th>Breed&emsp;&emsp;</th><th>Age&emsp;&emsp;</th><th>Allergies&emsp;&emsp;</th><th>Size&emsp;&emsp;</th><th>Groomed Before?&emsp;&emsp;</th><th>General Behavior&emsp;&emsp;</th><th>Cage Shy?&emsp;&emsp;</th><th>Vet</th></tr>\n";
            for(int i = 0; i < result.num_rows(); i++) {
               cout <<"<tr><td>" << result[i]["firstName"] << "</td>" <<
                "<td>" << result[i]["lastName"] << "</td>" <<
                "<td>" << result[i]["phoneNumber"] << "</td>" <<
                "<td>" << result[i]["address"] << "</td>" <<
                "<td>" << result[i]["petName"] << "</td>" <<
                "<td>" << result[i]["breed"] << "</td>" <<
                "<td>" << result[i]["age"] << "</td>" <<
                "<td>" << result[i]["allergies"] << "</td>" <<
                "<td>" << result[i]["size"] << "</td>" <<
                "<td>" << result[i]["groomedBefore"] << "</td>" <<
                "<td>" << result[i]["generalBehavior"] << "</td>" <<
                "<td>" << result[i]["cageShy"] << "</td>" <<
                "<td>" << result[i]["vet"] << "</td></tr>" << endl;
            }
        }
        cout << "</head></html>" << endl;
        return(0);
    }
}
