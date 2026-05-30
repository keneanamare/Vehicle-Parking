#include "ParkingSlot.h"
#include "UI.h"

// =========================================
// CONSTRUCTOR
// =========================================

ParkingSlot::ParkingSlot(int id, string type) {
    slotID = id;
    slotType = type;
    occupied = false;
}

// =========================================
// OCCUPY SLOT
// =========================================

void ParkingSlot::occupySlot() {
    occupied = true;
}

// =========================================
// FREE SLOT
// =========================================

void ParkingSlot::freeSlot() {
    occupied = false;
}

// =========================================
// GETTERS
// =========================================

int ParkingSlot::getSlotID() {
    return slotID;
}

string ParkingSlot::getSlotType() {
    return slotType;
}

bool ParkingSlot::isOccupied() {
    return occupied;
}

// =========================================
// DISPLAY SLOT
// =========================================

void ParkingSlot::displaySlot() {

    cout << "Slot " << slotID << " [" << slotType << "] : ";

    if(occupied){
        UI::setColor("red");
        cout << "Occupied";
        UI::resetColor();
    }
    else{
        UI::setColor("green");
        cout << "Available";
        UI::resetColor();
    }
    cout << endl;
}