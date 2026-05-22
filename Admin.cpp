#include "Admin.h"

// =========================================
// CONSTRUCTOR
// =========================================

Admin::Admin() {

    username = "admin";
    password = "1234";
}

// =========================================
// LOGIN FUNCTION
// =========================================

bool Admin::login() {

    string user;
    string pass;

    cout << endl;

    cout << "================================="
         << endl;

    cout << "         ADMIN LOGIN"
         << endl;

    cout << "================================="
         << endl;

    cout << "Username: ";
    cin >> user;

    cout << "Password: ";
    cin >> pass;

    if (
        user == username
        &&
        pass == password
    ) {

        cout << endl;

        cout << "Login Successful"
             << endl;

        return true;
    }

    else {

        cout << endl;

        cout << "Invalid Username or Password"
             << endl;

        return false;
    }
}