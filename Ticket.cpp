#include "Ticket.h"

// =========================================
// CONSTRUCTOR
// =========================================

Ticket::Ticket(
    int id,
    int slot,
    string plate,
    string type,
    time_t time
) {
    ticketID = id;
    slotNumber = slot;

    plateNumber = plate;
    vehicleType = type;

    entryTime = time;
}

// =========================================
// GETTERS
// =========================================

int Ticket::getTicketID() {
    return ticketID;
}

int Ticket::getSlotNumber() {
    return slotNumber;
}

string Ticket::getPlateNumber() {
    return plateNumber;
}

string Ticket::getVehicleType() {
    return vehicleType;
}

time_t Ticket::getEntryTime() {
    return entryTime;
}

// =========================================
// DISPLAY TICKET
// =========================================

void Ticket::displayTicket() {

    cout << endl;
    cout << "=================================" << endl;
    cout << "        PARKING TICKET           " << endl;
    cout << "=================================" << endl;

    cout << "Ticket ID      : "
         << ticketID << endl;

    cout << "Vehicle Type   : "
         << vehicleType << endl;

    cout << "Plate Number   : "
         << plateNumber << endl;

    cout << "Allocated Slot : "
         << slotNumber << endl;

    cout << "=================================" << endl;
}