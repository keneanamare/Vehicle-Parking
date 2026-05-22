#ifndef PARKINGSYSTEM_H
#define PARKINGSYSTEM_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Vehicle.h"
#include "ParkingSlot.h"
#include "Ticket.h"
#include "Receipt.h"

using namespace std;

class ParkingSystem {

private:

    vector<ParkingSlot> slots;
    vector<Ticket> tickets;

    int nextTicketID;
    int nextReceiptID;

    double totalRevenue;

public:

    // Constructor
    ParkingSystem();

    // Core Functions
    void showSlots();

    void parkVehicle();

    void exitVehicle();

    void showRevenue();

// FILE FUNCTIONS
    void saveHistory(
        string plate,
        string type,
        double fee
    );

    void saveRevenue();

    void viewHistory();
};

#endif