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

    int slotNumber;

    double totalFee;
    int duration;

    time_t exitTime;

public:
    // Constructor
    Receipt(
        int rID,
        int tID,
        string type,
        string plate,
        int slot,
        double fee,
        int hours
    );

    // Display Receipt
    void displayReceipt();
};

#endif