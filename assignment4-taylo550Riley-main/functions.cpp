/* 
    This program controls all the functions in the functions page. Will direct the
    user to the appropriate place when a button is pressed.
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

    cout << "Content-type: text/html" << endl << endl;
    cout << "<html>" << endl;
    cout << "<head>" << endl;
    cout << "<meta charset=\"UTF-8\">" << endl;
    cout << "<title>Database Functions</title>" << endl;
    cout << "<link rel=\"stylesheet\" href=\"css/style.css\" media=\"screen\" type=\"text/css\" />" << endl;
    cout << "</head>" << endl;
    cout << "<body>" << endl;
    cout << "<html lang=\"en-US\">" << endl;
    cout << "<head>";
    cout << "<meta charset=\"utf-8\">" << endl;
    cout << "<title>Add or Update Client Information</title>" << endl;
    cout << "<link rel=\"stylesheet\" href=\"http://fonts.googleapis.com/css?family=Open+Sans:400,700\">" << endl;
    cout << "</head>" << endl;
    cout << "<body>" << endl;
    cout << "<div class=\"container\">" << endl;
    cout << "<div id=\"login\">" << endl;

    // add function
    cout << "<form action=\"add.html\" method=\"POST\">" << endl;
    cout << "<fieldset class=\"clearfix\">" << endl;
    cout << "<p style=\"Color:white;text-align:center;font-size:120%;\">Add a new client or update an older entry</p>" << endl;
    cout << "<p><input type=\"submit\" value=\"Add\"></p>" << endl;
    cout << "</fieldset>" << endl;
    cout << "</form>" << endl;
    // --------------

    // update function
    cout << "<form action=\"update.html\" method=\"POST\">" << endl;
    cout << "<fieldset class=\"clearfix\">" << endl;
    cout << "<p><input type=\"submit\" value=\"Update\"></p>" << endl;
    cout << "</fieldset>" << endl;
    cout << "</form>" << endl;
    // --------------

    // View ALL client information
    cout << "<form action=\"viewallinfo.cgi\" method=\"POST\">" << endl;
    cout << "<fieldset class=\"clearfix\">" << endl;
    cout << "<p><input type=\"submit\" value=\"View All Client information\"></p>" << endl;
    cout << "</fieldset>" << endl;
    cout << "</form>" << endl;
    // --------------

    // View ALL deleted client information
    cout << "<form action=\"viewalldeletedclientinfo.cgi\" method=\"POST\">" << endl;
    cout << "<fieldset class=\"clearfix\">" << endl;
    cout << "<p><input type=\"submit\" value=\"View deleted Client information\"></p>" << endl;
    cout << "</fieldset>" << endl;
    cout << "</form>" << endl;
    // --------------

    // View client information
    cout << "<form action=\"viewclientinfo.cgi\" method=\"POST\">" << endl;
    cout << "<fieldset class=\"clearfix\">" << endl;
    cout << "<p style=\"Color:white;text-align:center;font-size:120%;\">Enter client's first name and last name to view information</p>" << endl;
    cout << "<p><span class=\"fontawesome-user\"></span><input type=\"text\" name=\"firstName\" value=\"First Name\" onBlur=\"if(this.value == '') this.value = 'First Name'\" onFocus=\"if(this.value == 'First Name') this.value = ''\" required></p> <!-- JS because of IE support; better: placeholder=\"First Name\" -->" << endl;
    cout << "<p><span class=\"fontawesome-user\"></span><input type=\"text\"  name=\"lastName\" value=\"Last Name\" onBlur=\"if(this.value == '') this.value = 'Last Name'\" onFocus=\"if(this.value == 'Last Name') this.value = ''\" required></p> <!-- JS because of IE support; better: placeholder=\"Last Name\" -->" << endl;
    cout << "<p><input type=\"submit\" value=\"View this client's information\"></p>" << endl;
    cout << "</fieldset>" << endl;
    cout << "</form>" << endl;
    // --------------

    // delete client information
    cout << "<form action=\"remove.cgi\" method=\"POST\">" << endl;
    cout << "<fieldset class=\"clearfix\">" << endl;
    cout << "<p style=\"Color:white;text-align:center;font-size:120%;\">Enter client's first name and last name to backup and delete</p>" << endl;
    cout << "<p><span class=\"fontawesome-user\"></span><input type=\"text\" name=\"firstName\" value=\"First Name\" onBlur=\"if(this.value == '') this.value = 'First Name'\" onFocus=\"if(this.value == 'First Name') this.value = ''\" required></p> <!-- JS because of IE support; better: placeholder=\"First Name\" -->" << endl;
    cout << "<p><span class=\"fontawesome-user\"></span><input type=\"text\"  name=\"lastName\" value=\"Last Name\" onBlur=\"if(this.value == '') this.value = 'Last Name'\" onFocus=\"if(this.value == 'Last Name') this.value = ''\" required></p> <!-- JS because of IE support; better: placeholder=\"Last Name\" -->" << endl;
    cout << "<p><input type=\"submit\" value=\"Backup and delete this client\"></p>" << endl;
    cout << "</fieldset>" << endl;
    cout << "</form>" << endl;
    // --------------

    cout << "</div> <!-- end login -->" << endl;
    cout << "</div>" << endl;
    cout << "</body>" << endl;
    cout << "</html>" << endl;
    cout << "</body>" << endl;
    cout << "</html>";
}