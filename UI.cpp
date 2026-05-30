#include "UI.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <ctime>
#include <string>

// =========================================
// LOADING ANIMATION
// =========================================

void UI::loadingAnimation() {

    cout << endl;

    cout << "Loading System";

    for(int i = 0; i < 5; i++) {

        cout << ".";

        usleep(400000);
    }

    cout << endl;
}

// =========================================
// WELCOME SCREEN
// =========================================

void UI::showWelcome() {

    cout << endl;

    UI::setColor("green");

    UI::typingEffect("Connecting To Central Parking Server...");
    UI::typingEffect("\nLoading Smart Parking Modules...");
    UI::typingEffect("\nSystem Initialization Complete.");

    UI::resetColor();

    cout << "\n========================================" << endl;
    UI::setColor("cyan");
    cout << "    MENSCHEN FUR MENSCHEN FOUNDATION    " << endl;
    cout << " AGRO TECHNICAL AND TECHNOLOGY COLLAGE  " << endl;
    UI::resetColor();
    cout << "========================================" << endl;
    UI::setColor("cyan");
    cout << "     SMART PARKING TERMINAL SYSTEM      " << endl;
    UI::resetColor();
    cout << "========================================" << endl;
    UI::setColor("cyan");
    cout << "  Intelligent Automated Parking System  " << endl;
    UI::resetColor();
    cout << "========================================" << endl;   
}

// =========================================
// DATE & TIME
// =========================================

void UI::showDateTime() {

    time_t now = time(0);
    char* dt = ctime(&now);

    UI::setColor("cyan");
    cout << " Current Time: "<< dt << endl;
    UI::resetColor();
}

// =========================================
// CLEAR SCREEN
// =========================================

void UI::clearScreen() {
    system("clear");
}

// =========================================
//  PAUSE SCREEN
// =========================================

void UI::pauseScreen(){
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

// =========================================
//  LOADING MESSEGE
// =========================================

void UI::loadingMessage(string message){
    cout << "\n";
    cout << message;

    for(int i = 0; i < 4; i++){
        cout << ".";
        cout.flush();

        sleep(1);
    }
    cout << "\n\n";
}

// ==========================================
//  TEXTING MESSAGE
// ==========================================

void UI::typingEffect(string text){
    for(char c : text){
        cout << c << flush;
        usleep(30000);
    }
    cout << endl;
}

// =========================================
//     COLOR TERMINAL UI
// =========================================

void UI::setColor(string color){
    if(color == "red")
        cout << "\033[1;31m";

    else if(color == "green")
        cout << "\033[1;32m";

    else if(color == "yellow")
        cout << "\033[1;33m";

    else if(color == "blue")
        cout << "\033[1;34m";

    else if(color == "cyan")
        cout << "\033[1;36m";
}

void UI::resetColor(){
    cout << "\033[0m";
}

// =========================================
// SHUTDOWN SCREEN
// =========================================

void UI::shutdown(){
    cout << "========================================" << endl;
    UI::setColor("cyan");
    cout << "        SYSTEM SHUTDOWN SEQUENCE        " << endl;
    UI::resetColor();
    cout << "========================================" << endl;

    UI::loadingMessage("\nClosing Parking Sessions...");
    sleep(1);

    UI::loadingMessage("\nSaving Parking Records...");
    sleep(1);

    UI::loadingMessage("\nDisconnecting Terminals...");
    sleep(1);

    UI::loadingMessage("\nSystem Shutdown Complete.");
    sleep(1);

    cout << endl;

    cout << "========================================" << endl;
    UI::setColor("green");
    cout << "   THANK YOU FOR USING OUR SYSTEM       " << endl;
    UI::resetColor();
    cout << "========================================" << endl;
}

// =========================================
// SYSTEM INFORMATION
// =========================================

void UI::showSystemInfo() {

    cout << endl;

    cout << "========================================";
    UI::setColor("cyan");
    cout << " ** SYSTEM INFORMATION ** ";
    UI::resetColor();
    cout << "========================================" << endl;

    cout << endl;

    UI::setColor("cyan");
    cout << " Project Name :" << endl;
    UI::resetColor();
    cout << "\tIntelligent Smart Parking Management System With Automated Slot Allocation And Fee calculation." << endl;

    cout << endl;

    UI::setColor("cyan");
    cout << " Developed Using :" << endl;
    UI::resetColor();
    cout << "\tC++ Object Oriented Programming." << endl;

    cout << endl;

    UI::setColor("cyan");
    cout << " Core Concepts Used :" << endl;
    UI::resetColor();
    cout << "\t- Classes & Objects" << endl;
    cout << "\t- Inheritance" << endl;
    cout << "\t- Polymorphism" << endl;
    cout << "\t- File Handling" << endl;
    cout << "\t- Encapsulation" << endl;
    cout << "\t- Dynamic Memory" << endl;
    cout << "\t- Vectors" << endl;
    cout << "\t- Modular Programming" << endl;

    cout << endl;

    UI::setColor("cyan");
    cout << " System Features :" << endl;
    UI::resetColor();
    cout << "\t- Vehicle Parking" << endl;
    cout << "\t- Smart Slot Allocation" << endl;
    cout << "\t- QR Ticket Simulation" << endl;
    cout << "\t- Receipt Generation" << endl;
    cout << "\t- Parking Reports" << endl;
    cout << "\t- Search Vehicle" << endl;
    cout << "\t- Revenue Tracking" << endl;
    cout << "\t- Admin Dashboard" << endl;

    cout << endl;

    UI::setColor("cyan");
    cout << " Supported Vehicles :" << endl;
    UI::resetColor();
    cout << "\t- Car" << endl;
    cout << "\t- Bus" << endl;
    cout << "\t- Truck" << endl;
    cout << "\t- Bike" << endl;
    cout << "\t- Motorcycle" << endl;

    cout << endl;

    UI::setColor("cyan");
    cout << " Project Objectives:" << endl;
    UI::resetColor();
    cout << "\t- Automate parking management operations" << endl;
    cout << "\t- Reduce manual parking management problems" << endl;
    cout << "\t- Manage available and occupied parking slots" << endl;
    cout << "\t- Generate parking tickets automatically" << endl;
    cout << "\t- Calculate parking fees based on parking duration" << endl;
    cout << "\t- Generate payment receipts" << endl;
    cout << "\t- Demonstrate practical implementation of OOP concepts" << endl;
    cout << "\t- Improve software modularity and scalability" << endl;

    cout << endl;

    UI::setColor("cyan");
    cout << " Storage Type :" << endl;
    UI::resetColor();
    cout << "\tText File Database System." << endl;

    UI::setColor("cyan");
    cout << " Platform :" << endl;
    UI::resetColor();
    cout << "\tLinux and Windows Terminal" << endl;

    cout << endl;

    UI::setColor("cyan");
    cout << " Version :" << endl;
    UI::resetColor();
    cout << "\tVersion 1.0" << endl;

    cout << endl;

    cout << "========================================" << endl;
    UI::setColor("blue");
    cout << "   ******** DEVELOPED BY ********       " << endl;
    UI::resetColor();
    cout << "========================================" << endl;
    UI::setColor("blue");
    cout << "   ******** GROUP MEMBERS ********      " << endl;
    UI::resetColor();
    cout << "========================================" << endl;
    cout << "       [NAME]                   [ID]    " << endl;
    cout << " [1] ABDI MOHAMMED           ATTC/001/24" << endl;
    cout << " [2] BIRUK TIBEBU            ATTC/012/24" << endl;
    cout << " [3] KENEAN AMARE            ATTC/051/24" << endl;
    cout << " [4] LEUL ASHENAFI           ATTC/053/24" << endl;
    cout << " [5] SAMUEL TEKLAY           ATTC/083/24" << endl;
    cout << "========================================" << endl;
}

// =========================================
// DELAY FUNCTION
// =========================================

void UI::delay(int seconds){

#ifdef _WIN32
    Sleep(seconds * 1000);
#else
    sleep(seconds);
#endif

}