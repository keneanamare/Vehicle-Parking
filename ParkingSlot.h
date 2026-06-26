#ifndef PARKINGSLOT_H
#define PARKINGSLOT_H

#include <iostream>
using namespace std;

class ParkingSlot {
private:
    int slotID;
    string slotType;
    bool occupied;

public:
    // Constructor
    ParkingSlot(int id, string type);

    // Slot Operations
    void occupySlot();
    void freeSlot();

    // Getters
    int getSlotID();
    string getSlotType();
    bool isOccupied();

    // Display Function
    void displaySlot();
};
#endif