#include "Receipt.h"

// =========================================
// CONSTRUCTOR
// =========================================

Receipt::Receipt(
    int rID,
    int tID,
    string type,
    string plate,
    int slot,
    double fee,
    int hours
) {
    receiptID = rID;
    ticketID = tID;

    vehicleType = type;
    plateNumber = plate;

    slotNumber = slot;

    totalFee = fee;
    duration = hours;

    exitTime = time(0);
}

// =========================================
// DISPLAY RECEIPT
// =========================================

void Receipt::displayReceipt() {

    cout << endl;

    cout << "====================================" << endl;

    cout << "         PAYMENT RECEIPT            " << endl;

    cout << "====================================" << endl;

    cout << "Receipt ID : "
         << receiptID << endl;

    cout << "Ticket ID  : "
         << ticketID << endl;

    cout << endl;

    cout << "Vehicle    : "
         << vehicleType << endl;

    cout << "Plate No   : "
         << plateNumber << endl;

    cout << "Slot No    : "
         << slotNumber << endl;

    cout << endl;

    cout << "Duration   : "
         << duration
         << " Hours" << endl;

    cout << "Total Fee  : "
         << totalFee
         << " Birr" << endl;

    cout << endl;

    cout << "====================================" << endl;

    cout << "Payment Status : PAID" << endl;

    cout << "====================================" << endl;
        

    cout << endl;

    cout << "====================================" << endl;

    cout << " Thank You For Using Our System " << endl;

    cout << "====================================" << endl;
}