#include "Receipt.h"
#include "UI.h"

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
    time_t entry,
    int h,
    int minutes
)
{
    receiptID = rID;
    ticketID = tID;
    vehicleType = type;
    plateNumber = plate;
    slotNumber = slot;
    totalFee = fee;
    entryTime = entry;
    hours = h;
    remainingMinutes = minutes;
    exitTime = time(0);
}

// =========================================
// DISPLAY RECEIPT
// =========================================

void Receipt::displayReceipt() {

    cout << endl;

    cout << "========================================" << endl;
    UI::setColor("yellow");
    cout << "       PAYMENT RECEIPT               " << endl;
    UI::resetColor();
    cout << "========================================" << endl;
    cout << "   Receipt ID : " << receiptID << endl;
    cout << "   Ticket ID  : " << ticketID << endl;

    cout << endl;

    cout << "   Vehicle    : " << vehicleType << endl;
    cout << "   Plate No   : " << plateNumber << endl;
    cout << "   Slot No    : " << slotNumber << endl;

    cout << endl;

    char* entryDate = ctime(&entryTime);
     cout << "  Entry Time : " << entryDate;

    char* exitDate = ctime(&exitTime);
     cout << "  Exit Time  : " << exitDate;

    cout << endl;

    cout << "   Parking Duration : " << hours << " Hour(s) : " << remainingMinutes << " Minute(s)" << endl;
    cout << "   Total Fee  : " << totalFee << " Birr" << endl;

    cout << endl;

    cout << "=========================================" << endl;
    UI::setColor("green");
    cout << "        Payment Status : PAID" << endl;
    UI::resetColor();
    cout << "=========================================" << endl;
    
    cout << endl;

    cout << "=========================================" << endl;
    UI::setColor("blue");
    cout << "   Thank You For Using Our System!!!     " << endl;
    UI::resetColor();
    cout << "=========================================" << endl;
}