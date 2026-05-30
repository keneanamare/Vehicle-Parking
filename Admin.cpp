#include "Admin.h"
#include "UI.h"

// =========================================
// CONSTRUCTOR
// =========================================

Admin::Admin() {

username = "abkls";
password = "012358";

}

// =========================================
// LOGIN FUNCTION
// =========================================

bool Admin::login() {

    string user;
    string pass;

    int attempts = 3;

    while(attempts > 0) {

        cout << endl;

        cout << "========================================" << endl;
        UI::setColor("blue");
        cout << "              ADMIN LOGIN               " << endl;
        UI::resetColor();
        cout << "========================================" << endl;

        cout << "Enter Username : ";
        cin >> user;

        cout << "Enter Password : ";
        cin >> pass;

        UI::setColor("cyan");
        UI::loadingMessage("Authenticating User");
        UI::resetColor();

        if(user == username && pass == password) {

            UI::clearScreen();

            UI::setColor("green");
            cout << "\n[SUCCESS] ACCESS GRANTED!" << endl;
            UI::resetColor();

            UI::delay(1);

            return true;
        }

        attempts--;

        UI::clearScreen();

        UI::setColor("red");
        cout << "\nInvalid Username or Password!" << endl;
        cout << "Remaining Attempts : "
             << attempts << endl;
        UI::resetColor();

        UI::delay(2);

        UI::clearScreen();
    }

    UI::setColor("red");
    cout << "\n[SECURITY] Maximum Login Attempts Reached!" << endl;
    UI::loadingMessage("Returning To Main Menu");
    UI::resetColor();
    UI::clearScreen();
    UI::delay(2);

    return false;
}
// =====================================
// ADMIN DASHBOARD
// =========================================

void Admin::adminMenu(ParkingSystem &system) {

    int adminChoice;

    do {

        UI::clearScreen();

        cout << endl;

        cout << "========================================" << endl;
        UI::setColor("blue");
        cout << "          ADMIN DASHBOARD               " << endl;
        UI::resetColor();
        cout << "========================================" << endl;

        cout << "   [1] System Revenue" << endl;
        cout << "   [2] Parking History" << endl;
        cout << "   [3] Search Vehicle" << endl;
        cout << "   [4] Parking Statistics" << endl;
        cout << "   [5] Parking Status Overview" << endl;
        cout << "   [6] Generate Daily Report" << endl;
        cout << "   [7] Parking Map View" << endl;
        cout << "   [0] Return To Main Menu" << endl;

        cout << "========================================" << endl;

        cout << "Enter Choice : ";
        cin >> adminChoice;

        switch(adminChoice) {

            case 1:

                UI::clearScreen();

                system.showRevenue();

                UI::pauseScreen();

                break;

            case 2:

                UI::clearScreen();

                system.viewHistory();

                UI::pauseScreen();

                break;

            case 3:

                UI::clearScreen();

                system.searchVehicle();

                UI::pauseScreen();

                break;

            case 4:

                UI::clearScreen();

                system.showStatistics();

                UI::pauseScreen();

                break;

            case 5:

                UI::clearScreen();

                system.showParkingOverview();

                UI::pauseScreen();

                break;

            case 6:

                UI::clearScreen();

                system.generateDailyReport();

                UI::pauseScreen();

                break;

            case 7:

                UI::clearScreen();

                system.showParkingMap();

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

    } while(adminChoice != 0);
}