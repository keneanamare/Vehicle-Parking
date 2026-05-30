#include "User.h"
#include "UI.h"

// =========================================
// USER MENU
// =========================================

void User::userMenu(ParkingSystem &system) {

    int choice;

    do {

        UI::clearScreen();

        cout << endl;

        UI::setColor("green");
        UI::loadingMessage("WELCOME TO USER INTERFACE");
        UI::resetColor();

        cout << endl;

        cout << "========================================" << endl;
        UI::setColor("blue");
        cout << "              USER PANEL                " << endl;
        UI::resetColor();
        cout << "========================================" << endl;

        cout << " [1] View Parking Slots" << endl;
        cout << " [2] Park Vehicle" << endl;
        cout << " [3] Vehicle Exit & Payment" << endl;
        cout << " [0] Return To Main Menu" << endl;

        cout << "========================================" << endl;
        UI::setColor("green");
        cout << "Select Option : ";
        UI::resetColor();
        cin >> choice;

        UI::loadingAnimation();

        switch(choice) {

            case 1:

                UI::clearScreen();

                system.showSlots();

                UI::pauseScreen();

                break;

            case 2:

                UI::clearScreen();

                system.parkVehicle();

                UI::pauseScreen();

                break;

            case 3:

                UI::clearScreen();

                system.exitVehicle();

                UI::pauseScreen();

                break;

            case 0:

                UI::clearScreen();

                UI::setColor("cyan");

                UI::loadingMessage("Returning To Main Menu");

                UI::resetColor();

                UI::clearScreen();

                UI::delay(1);

                break;

            default:

                UI::setColor("red");

                cout << "\nInvalid Choice!" << endl;

                UI::resetColor();

                UI::delay(1);
        }

    } while(choice != 0);
}