#include <iostream>
#include <occi.h>

using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;

int main(void)
{
    /* OCCI Variables */
    Environment* env = nullptr;
    Connection* conn = nullptr;
    /* Used Variables */
    string user = "dbs211_211h17";
    string pass = "16824777";
    string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";
    // Query statements are created as followed
    string query = "SELECT e.employeenumber, e.firstname, e.lastname, o.phone, e.extension FROM employees e JOIN offices o USING(officecode) WHERE LOWER(o.city) = 'san francisco' ORDER BY 1";
    string query2 = "SELECT DISTINCT e.reportsto, m.firstname, m.lastname, o.phone, m.extension FROM employees e JOIN employees m ON e.reportsto = m.employeenumber JOIN offices o ON m.officecode = o.officecode ORDER BY 1";
    try {
        env = Environment::createEnvironment(Environment::DEFAULT);     // Create environment to set up for connection
        conn = env->createConnection(user, pass, srv);                  // Create connection
        
        Statement* stmt = conn->createStatement(query);     // Create the first query statement
        
        ResultSet* rs = stmt->executeQuery();               // Save the query results to rs
        
        if (!rs->next()) {      // Make sure there is result that can be displayed, if not, display the message
            cout << "ResultSet is empty." << endl;
        }
        else {
            cout << "------------------------- Report 1 (Employee Report) -----------------------------------" << endl;
            cout << "Employee ID   First Name         Last Name          Phone             Extension" << endl;
            cout << "------------  -----------------  -----------------  ----------------  ---------" << endl;

            // In order not to skip the first result as there's already one next() in the if statement, a do while loop is used. 
            do {
                int num = rs->getInt(1);            // Get the employee ID as int
                string first = rs->getString(2);    // Get the first name as string
                string last = rs->getString(3);     // Get the last name as string
                string phone = rs->getString(4);    // Get the phone number as string
                string ext = rs->getString(5);      // Get the extension number as string
                // cout.setf to make sure the displayed result is left aligned and the cout.width sets the field width
                cout.setf(ios::left); cout.width(14); cout << num;      
                cout.width(19); cout << first; 
                cout.width(19); cout << last;
                cout.width(18); cout << phone;
                cout.width(11); cout << ext << endl;
            } while (rs->next());
            cout << endl;
        }

        stmt = conn->createStatement(query2);       // Create the second query statement
        rs = stmt->executeQuery();                  // Save the query results to rs
        if (!rs->next()) {
            cout << "ResultSet is empty." << endl;
        }
        else {
            cout << "------------------------- Report 2 (Manager Report) -----------------------------------" << endl;
            cout << "Employee ID   First Name         Last Name          Phone             Extension" << endl;
            cout << "------------  -----------------  -----------------  ----------------  ---------" << endl;
            do {
                int num = rs->getInt(1);
                string first = rs->getString(2);
                string last = rs->getString(3);
                string phone = rs->getString(4);
                string ext = rs->getString(5);
                cout.setf(ios::left); cout.width(14); cout << num;
                cout.width(19); cout << first;
                cout.width(19); cout << last;
                cout.width(18); cout << phone;
                cout.width(11); cout << ext << endl;
            } while (rs->next());
        }

        conn->terminateStatement(stmt);             // terminate the query statements
        env->terminateConnection(conn);             // terminate the connection
        Environment::terminateEnvironment(env);     // terminate the environment
    }
    catch (SQLException& sqlExcp) {
        cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
    }
    return 0;
}


