#ifndef UI_H
#define UI_H

#include <iostream>
using namespace std;

class UI {

public:

    static void loadingAnimation();

    static void showWelcome();

    static void showDateTime();

    static void clearScreen();

    static void pauseScreen();

    static void loadingMessage(string message);

    static void typingEffect(string text);

    static void setColor(string color);

    static void resetColor();

    static void shutdown();

    static void showSystemInfo();

    static void delay(int seconds);
};

#endif