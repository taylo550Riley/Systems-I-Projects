/*
    This program is used to process login credentials given from index.html.
    It checks to see if the username and password provided by the user
    matches that of the 01757392Users table in the mysql database. If the
    user enters the incorrect information, they will be sent back to index.html
    to try again. Otherwise, it will log the user in and move to functions.cgi.
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
    std::string u;
    std::string p;
    bool success = false;
    if (Get.find("username")!=Get.end() && Get.find("password")!=Get.end()) {
        username = Get["username"];
        password = Get["password"];
    }
    // Connect to database with: database, server, userID, password
    mysqlpp::Connection conn(false); // Exceptions suppressed to keep code simple
    if(conn.connect("cse278", "localhost", "cse278", "MonSepM1am1")) {
        // Create a query
        mysqlpp::Query query = conn.query();
        query << "SELECT username, password FROM 01757392Users WHERE username = '"+username+"' AND password = '"+password+"'";

        // Check the query for correctness
        query.parse();

        // Run the query and get the result
        mysqlpp::StoreQueryResult result = query.store();

        // Check credentials and move the user appropriately.
        if(result) {
        cout << "Content-type: text/html" << endl << endl;
        cout << "<html><head>" << endl;
        cout << "<head>" << endl;
        cout << "<meta charset=\"UTF-8\">" << endl;
        cout << "<title>Database Functions</title>" << endl;
        cout << "<link rel=\"stylesheet\" href=\"css/style.css\" media=\"screen\" type=\"text/css\" />" << endl;
        cout << "</head>" << endl;
            for(int i = 0; i < result.num_rows(); i++) {
                u = result[i]["username"].c_str();
                p = result[i]["password"].c_str();
                if(username == u && password == p) {
                    success = true;
                    break;
                } else {
                    success = false;
                }
            }
        }
        if(success == true) {
            cout << "<p><br></br><font size=\"+3\"><pre> Login successful, please wait. </pre></font></p>" << endl;
            cout << "<meta http-equiv = \"refresh\" content = \"2; url = http://os1.csi.miamioh.edu/~taylo550/functions.cgi\" />" << endl;

        } else {
            cout << "<p><br></br><font size=\"+3\"><pre> Incorrect username or password, redirecting back to homepage. </pre></font></p>" << endl;
            cout << "<meta http-equiv = \"refresh\" content = \"2; url = http://os1.csi.miamioh.edu/~taylo550/index.html\" />" << endl;

        }
        cout << "</head></html>" << endl;
        return(0);
    }
}
