#include "ParkingSystem.h"

// =========================================
// CONSTRUCTOR
// =========================================

ParkingSystem::ParkingSystem() {

    nextTicketID = 1001;
    nextReceiptID = 2001;

    totalRevenue = 0;

    // CAR SLOTS

    for (int i = 1; i <= 20; i++) {

        slots.push_back(
            ParkingSlot(i, "Car")
        );
    }

    // BIKE SLOTS

    for (int i = 21; i <= 27; i++) {

        slots.push_back(
            ParkingSlot(i, "Bike")
        );
    }

    // TRUCK SLOTS

    for (int i = 28; i <= 30; i++) {

        slots.push_back(
            ParkingSlot(i, "Truck")
        );
    }
}

// =========================================
// SHOW SLOT STATUS
// =========================================

void ParkingSystem::showSlots() {

    cout << endl;

    cout << "================================="
         << endl;

    cout << "        SLOT STATUS"
         << endl;

    cout << "================================="
         << endl;

    for (auto &slot : slots) {

        slot.displaySlot();
    }
}

// =========================================
// PARK VEHICLE
// =========================================

void ParkingSystem::parkVehicle() {

    int choice;
    string plate;

    Vehicle* vehicle = nullptr;

    cout << endl;

    cout << "Select Vehicle Type"
         << endl;

    cout << "1. Car" << endl;
    cout << "2. Bike" << endl;
    cout << "3. Truck" << endl;

    cout << "Enter Choice: ";
    cin >> choice;

    cout << "Enter Plate Number: ";
    cin >> plate;

    // VEHICLE CREATION

    if (choice == 1)
        vehicle = new Car(plate);

    else if (choice == 2)
        vehicle = new Bike(plate);

    else if (choice == 3)
        vehicle = new Truck(plate);

    else {
        cout << "Invalid Choice"
             << endl;
        return;
    }

    // SLOT SEARCHING

    for (auto &slot : slots) {

        if (
            !slot.isOccupied()
            &&
            slot.getSlotType()
            ==
            vehicle->getVehicleType()
        ) {

            slot.occupySlot();

            // CREATE TICKET

            Ticket ticket(

                nextTicketID,

                slot.getSlotID(),

                vehicle->getPlateNumber(),

                vehicle->getVehicleType(),

                vehicle->getEntryTime()
            );

            tickets.push_back(ticket);

            cout << endl;

            cout << "Searching Available Slots..."
                 << endl;

            cout << "Slot Allocated Successfully"
                 << endl;

            ticket.displayTicket();

            nextTicketID++;

            delete vehicle;

            return;
        }
    }

    cout << "No Available Slots"
         << endl;

    delete vehicle;
}

// =========================================
// EXIT VEHICLE
// =========================================

void ParkingSystem::exitVehicle() {

    int ticketID;

    cout << "Enter Ticket ID: ";
    cin >> ticketID;

    for (int i = 0;
         i < tickets.size();
         i++) {

        if (
            tickets[i].getTicketID()
            ==
            ticketID
        ) {

            // TIME CALCULATION

            time_t currentTime = time(0);

            double duration =
                difftime(
                    currentTime,
                    tickets[i].getEntryTime()
                ) / 3600;

            if (duration < 1)
                duration = 1;

            // FEE CALCULATION

            double fee;

            if (
                tickets[i].getVehicleType()
                ==
                "Car"
            )
                fee = duration * 10;

            else if (
                tickets[i].getVehicleType()
                ==
                "Bike"
            )
                fee = duration * 5;

            else
                fee = duration * 15;

            totalRevenue += fee;

            // FREE SLOT

            for (auto &slot : slots) {

                if (
                    slot.getSlotID()
                    ==
                    tickets[i].getSlotNumber()
                ) {

                    slot.freeSlot();
                }
            }

            // CREATE RECEIPT

            Receipt receipt(

                nextReceiptID,

                tickets[i].getTicketID(),

                tickets[i].getVehicleType(),

                tickets[i].getPlateNumber(),

                tickets[i].getSlotNumber(),

                fee,

                duration
            );

            receipt.displayReceipt();

            nextReceiptID++;

            saveHistory(

                tickets[i].getPlateNumber(),

                tickets[i].getVehicleType(),

                fee
            );

            saveRevenue();

            // REMOVE ACTIVE TICKET

            tickets.erase(
                tickets.begin() + i
            );

            return;
        }
    }

    cout << "Ticket Not Found"
         << endl;
}

// =========================================
// SHOW REVENUE
// =========================================

void ParkingSystem::showRevenue() {

    cout << endl;

    cout << "================================="
         << endl;

    cout << " Total Revenue : "
         << totalRevenue
         << " Birr"
         << endl;

    cout << "================================="
         << endl;
}
void ParkingSystem::saveHistory(
    string plate,
    string type,
    double fee
) {

    ofstream file(
        "data/history.txt",
        ios::app
    );

    if (file.is_open()) {

        file
            << plate << " | "
            << type << " | "
            << fee << " Birr"
            << endl;

        file.close();
    }
}
void ParkingSystem::saveRevenue() {

    ofstream file(
        "data/revenue.txt"
    );

    if (file.is_open()) {

        file << totalRevenue;

        file.close();
    }
}
void ParkingSystem::viewHistory() {

    ifstream file(
        "data/history.txt"
    );

    string line;

    cout << endl;

    cout << "================================="
         << endl;

    cout << "       PARKING HISTORY"
         << endl;

    cout << "================================="
         << endl;

    while (getline(file, line)) {

        cout << line << endl;
    }

    file.close();
}
