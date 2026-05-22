#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
using namespace std;

class Admin {

private:

    string username;
    string password;

public:

    // Constructor
    Admin();

    // Login Function
    bool login();
};

#endif