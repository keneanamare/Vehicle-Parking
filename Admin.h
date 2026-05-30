#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>

using namespace std;

#include "ParkingSystem.h"

class Admin {

private:

    string username;
    string password;

public:

    Admin();

    bool login();
    void adminMenu(ParkingSystem &system);
};

#endif