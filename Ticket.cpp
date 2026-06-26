#include "Ticket.h"
#include "UI.h"

// =========================================
// CONSTRUCTOR
// =========================================

Ticket::Ticket(
    int id,
    int slot,
    string plate,
    string type,
    time_t entryTime
)
{
    ticketID = id;
    slotNumber = slot;
    plateNumber = plate;
    vehicleType = type;
    this->entryTime = entryTime;
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
    UI::setColor("yellow");
    cout << "        PARKING TICKET           " << endl;
    UI::resetColor();
    cout << "=================================" << endl;

    cout << "   Ticket ID      : " << ticketID << endl;
    cout << "   Vehicle Type   : " << vehicleType << endl;
    cout << "   Plate Number   : " << plateNumber << endl;
    cout << "   Allocated Slot : " << slotNumber << endl;

    cout << "=================================" << endl;
}

// ==========================================
//        DISPLAY TICKET
// ==========================================
void Ticket::displayQRCode(){
    cout << endl;
    cout << "+----------------------+" << endl;
    srand(ticketID);

    for(int i = 0; i < 5; i++){
        cout << "| ";

        for(int j = 0; j < 20; j++){
            if(rand() % 2 == 0)
                cout << "#";
            else
                cout << " ";
        }

        cout << " |" << endl;
    }
    cout << "+----------------------+" << endl;

    cout << endl;

    cout << "QR Verification Active" << endl;
    cout << "=================================" << endl;
}