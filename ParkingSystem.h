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
    vector<Receipt> receipts;
    vector<string> history;

    int nextTicketID;
    int nextReceiptID;

    double totalRevenue;
    double dailyRevenue;

public:

    // Constructor
    ParkingSystem();

    // Core Functions
    void showSlots();

    void searchVehicle();

    void showStatistics();

    void showParkingOverview();

    void parkVehicle();

    void exitVehicle();

    void showRevenue();

    void generateDailyReport();

    void showParkingMap();

// FILE FUNCTIONS
    void saveHistory(
        string plate,
        string type,
        double fee
    );

    void saveRevenue();

    void savereceipt();

    void loadHistory();

    void loadRevenue();

    void viewHistory();

    void saveActiveTickets();

    void loadActiveTickets();
};

#endif