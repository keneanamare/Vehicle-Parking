#include "UI.h"

#include <unistd.h>
#include <ctime>

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

    cout << "========================================"
         << endl;

    cout << "     SMART PARKING TERMINAL SYSTEM"
         << endl;

    cout << "========================================"
         << endl;

    cout << "  Intelligent Automated Parking"
         << endl;

    cout << "========================================"
         << endl;
}

// =========================================
// DATE & TIME
// =========================================

void UI::showDateTime() {

    time_t now = time(0);

    char* dt = ctime(&now);

    cout << "Current Time: "
         << dt
         << endl;
}

// =========================================
// CLEAR SCREEN
// =========================================

void UI::clearScreen() {

    system("clear");
}