#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <string>
#include <iostream>
#include "getpost.h"

using namespace std;

int main(int argc, char* argv[]) {

    map<string,string> Get;
    initializePost(Get);

        // Connect to database with: database, server, userID, password
    mysqlpp::Connection conn(false); // Exceptions suppressed to keep code simple
    if(conn.connect("cse278", "localhost", "cse278", "MonSepM1am1")) {
        // Create a query
        mysqlpp::Query query = conn.query();
        query << "SELECT * FROM 01757392deletedClients;";  

        // Check the query for correctness
        query.parse();

        // Run the query and get the result
        mysqlpp::StoreQueryResult result = query.store();

        /*
            This section checks for errors and then makes a table that
            displays all deleted client information provided by the user.
            This table is used as a backup for accidently client deletes.
            There is no way to delete information from this table as it would
            defeat the purpose of the table.

            &emsp adds spaces in the table to make it look better.
            The table should fit the screen correctly width wise.
        */
        if(result) {
        cout << "Content-type: text/html" << endl << endl;
        cout << "<html><head>" << endl;
        cout << "<title>All deleted client info</title>" << endl;
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
