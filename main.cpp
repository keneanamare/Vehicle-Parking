#include <iostream>

#include "Admin.h"
#include "ParkingSystem.h"
#include "UI.h"

using namespace std;

int main() {

    ParkingSystem system;
    Admin admin;

    int choice;

    UI::clearScreen();

    UI::showWelcome();

    UI::showDateTime();

    UI::loadingAnimation();


    do {

        cout << endl;

        cout << "SYSTEM STATUS : ONLINE" << endl;
        cout << "AVAILABLE TERMINALS : ACTIVE" << endl;
        cout << "========================================" << endl;
        cout << "           MAIN TERMINAL MENU           " << endl;
        cout << "========================================" << endl;
        cout << "[1] System Information" << endl;
        cout << "[2] View Parking Slots" << endl;
        cout << "[3] Park Vehicle" << endl;
        cout << "[4] Vehicle Exit & Payment" << endl;
        cout << "[5] Admin Panel" << endl;
        cout << "[6] Exit System" << endl;
        cout << "========================================" << endl;
        cout << "Select Option: ";
        cin >> choice;

        switch(choice) {

            // =================================
            // SYSTEM INFORMATION
            // =================================

            case 1:

                cout << endl;

                cout << "========================================" << endl;

                cout << " SMART AUTOMATED PARKING MANAGEMENT" << endl;

                cout << "========================================" << endl;

                cout << "Features:" << endl;

                cout << "- Automatic Slot Allocation" << endl;

                cout << "- Ticket Generation" << endl;

                cout << "- Receipt Generation" << endl;

                cout << "- Revenue Tracking" << endl;

                cout << "- Vehicle Management" << endl;

                cout << "- Real-Time Slot Status" << endl;

                cout << "========================================" << endl;

                cout << "========================================" << endl;
                cout << "             DEVELOPED BY               " << endl;
                cout << "========================================" << endl;
                cout << "             GROUP MEMBERS              " << endl;
                cout << "========================================" << endl;
                cout << " 1. ABDI MOHAMMED           ATTC/001/24 " << endl;
                cout << " 2. BIRUK TIBEBU            ATTC/012/24 " << endl;
                cout << " 3. KENEAN AMARE            ATTC/051/24 " << endl;
                cout << " 4. LEUL ASHENAFI           ATTC/053/24 " << endl;
                cout << " 5. SAMUEL TEKLAY           ATTC/083/24 " << endl;
                cout << "========================================" << endl;

                break;

            // =================================
            // VIEW SLOTS
            // =================================

            case 2:

                system.showSlots();

                break;

            // =================================
            // PARK VEHICLE
            // =================================

            case 3:

                system.parkVehicle();

                break;

            // =================================
            // EXIT VEHICLE
            // =================================

            case 4:

                system.exitVehicle();

                break;

            // =================================
            // ADMIN PANEL
            // =================================

            case 5:

                if(admin.login()) {

                    int adminChoice;

                    do {

                    cout << endl;

                    cout << "=================================" << endl;

                    cout << "         ADMIN PANEL             " << endl;

                    cout << "=================================" << endl;

                    cout << "1. View Revenue" << endl;

                    cout << "2. View Parking History" << endl;

                    cout << "3. Return To Main Menu" << endl;

                    cout << "=================================" << endl;

                    cout << "Enter Choice: ";

                    cin >> adminChoice;

                switch(adminChoice) {

                    case 1:

                        system.showRevenue();

                        break;

                    case 2:

                        system.viewHistory();

                        break;

                    case 3:

                        cout << "Returning..." << endl;

                        break;

                    default:

                        cout << "Invalid Choice" << endl;
                    }

                } while(adminChoice != 3);
            }

                break;

            // =================================
            // EXIT SYSTEM
            // =================================

            case 6:

                cout << endl;

                cout << "========================================" << endl;

                cout << "      SYSTEM SHUTDOWN SUCCESSFUL" << endl;

                cout << "========================================" << endl;

                cout << " Thank You For Using Our System " << endl;

                cout << "========================================" << endl;
                
                break;

            // =================================
            // INVALID CHOICE
            // =================================

            default:

                cout << endl;

                cout << "Invalid Choice" << endl;
        }

    } while(choice != 6);

    return 0;
}