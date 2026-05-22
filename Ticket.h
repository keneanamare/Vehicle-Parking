#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <ctime>
using namespace std;

class Ticket {
private:
    int ticketID;
    int slotNumber;

    string plateNumber;
    string vehicleType;

    time_t entryTime;

public:
    // Constructor
    Ticket(
        int id,
        int slot,
        string plate,
        string type,
        time_t time
    );

    // Getters
    int getTicketID();
    int getSlotNumber();

    string getPlateNumber();
    string getVehicleType();

    time_t getEntryTime();

    // Display Ticket
    void displayTicket();
};

#endif