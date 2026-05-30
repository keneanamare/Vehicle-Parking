#include <iostream>

#include "ParkingSystem.h"
#include "Admin.h"
#include "User.h"
#include "UI.h"

using namespace std;

int main() {

    ParkingSystem system;
    Admin admin;
    User user;

    int choice;

    UI::showWelcome();
    UI::showDateTime();

    do {

        cout << endl;

        UI::typingEffect("SYSTEM STATUS        : ONLINE");
        UI::typingEffect("SMART TERMINALS      : ACTIVE");

        cout << endl;

        cout << "========================================" << endl;
        UI::setColor("cyan");
        cout << "        SMART PARKING SYSTEM            " << endl;
        UI::resetColor();
        cout << "========================================" << endl;

        cout << endl;

        cout << " [1] System Information" << endl;
        cout << " [2] User Panel" << endl;
        cout << " [3] Admin Panel" << endl;
        cout << " [0] Shutdown System" << endl;

        cout << endl;

        cout << "========================================" << endl;
        UI::setColor("green");
        cout << "Select Option : ";
        UI::resetColor();
        cin >> choice;

        UI::loadingAnimation();

        switch(choice) {

            case 1:

                UI::clearScreen();
                UI::showSystemInfo();
                UI::pauseScreen();
                UI::clearScreen();

                break;

            case 2:

                UI::clearScreen();
    
                user.userMenu(system);

                break;

            case 3:

                UI::clearScreen();

                if(admin.login()) {

                    admin.adminMenu(system);
                }

                break;

            case 0:

                UI::clearScreen();

                UI::shutdown();

                UI::delay(1);

                break;

            default:

                UI::setColor("red");

                cout << "\nInvalid Choice!" << endl;

                UI::resetColor();

                UI::delay(1);
        }

    } while(choice != 0);

    return 0;
}