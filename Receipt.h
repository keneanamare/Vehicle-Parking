#ifndef RECEIPT_H
#define RECEIPT_H

#include <iostream>
#include <ctime>
using namespace std;

class Receipt {
private:
    int receiptID;
    int ticketID;

    string vehicleType;
    string plateNumber;
    time_t entryTime;
    time_t exitTime;

    int slotNumber;
    double totalFee;
    int hours;
    int remainingMinutes;

public:
    // Constructor
    Receipt(
        int rID,
        int tID,
        string type,
        string plate,
        int slot,
        double fee,
        time_t entry,
        int h,
        int minutes
    );

    // Display Receipt
    void displayReceipt();
};

#endif