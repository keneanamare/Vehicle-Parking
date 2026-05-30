#include "ParkingSystem.h"
#include "UI.h"
#include "Vehicle.h"

#include <sstream>

// =========================================
// CONSTRUCTOR
// =========================================

ParkingSystem::ParkingSystem() {

    nextTicketID = 1001;
    nextReceiptID = 2001;

    totalRevenue = 0;
    dailyRevenue = 0;

    // CAR SLOTS
    for(int i = 1; i <= 15; i++){
        slots.push_back(ParkingSlot(i, "Car"));
    }

    // BUS SLOTS
    for(int i = 16; i <= 30; i++){
        slots.push_back(ParkingSlot(i, "Bus"));
    }

    // TRUCK SLOTS
    for(int i = 31; i <= 40; i++){
        slots.push_back(ParkingSlot(i, "Truck"));
    }

    // BIKE SLOTS
    for(int i = 41; i <= 60; i++){
        slots.push_back(ParkingSlot(i, "Bike"));
    }

    // MOTORCYCLE SLOTS
    for(int i = 61; i <= 80; i++){
        slots.push_back(ParkingSlot(i, "Motorcycle"));
    }

    // LOAD SAVED DATA
    loadHistory();
    loadRevenue();
    loadActiveTickets();
}

// =========================================
// SHOW SLOT STATUS
// =========================================

void ParkingSystem::showSlots() {

    cout << endl;

    cout << "=================================" << endl;
    UI::setColor("cyan");
    cout << "          SLOT STATUS            " << endl;
    UI::resetColor();
    cout << "=================================" << endl;

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

    cout << "========================================" << endl;
    UI::setColor("cyan");
    cout << "        VEHICLE REGISTRATION            " << endl;
    UI::resetColor();
    cout << "========================================" << endl;

    cout << "[1] Car" << endl;
    cout << "[2] Bus" << endl;
    cout << "[3] Truck" << endl;
    cout << "[4] Bike" << endl;
    cout << "[5] Motorcycle" << endl;

    cout << "========================================" << endl;

    cout << "Select Vehicle Type : ";
    cin >> choice;

    if(choice < 1 || choice > 5){

    UI::setColor("red");
    cout << "\nInvalid Vehicle Type!" << endl;
    UI::resetColor();

    UI::delay(2);

    return;
}

// VEHICLE CREATION

    cout << "\nEnter Vehicle Plate Number : ";
    cin >> plate;

switch(choice){
    case 1:
        vehicle = new Car(plate);
        break;

    case 2:
        vehicle = new Bus(plate);
        break;

    case 3:
        vehicle = new Truck(plate);
        break;

    case 4:
        vehicle = new Bike(plate);
        break;

    case 5:
        vehicle = new Motorcycle(plate);
        break;

    default:
        UI::setColor("red");
        cout << "Invalid Choice. Try Again." << endl;
        UI::resetColor();
        UI::delay(2);

        parkVehicle(); // re-open same menu
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
        saveActiveTickets();

        cout << endl;

        UI::typingEffect("Initializing Parking Sequence...");
        UI::typingEffect("\nScanning Parking Database...");
        UI::delay(1);
        UI::typingEffect("\nSearching Available Slot...");
        UI::typingEffect("\nAllocating Smart Parking Slot...");
        UI::delay(1);

        UI::setColor("green");
        UI::typingEffect("\n[SUCCESS] Vehicle Parked Successfully");
        UI::resetColor();

        UI::delay(1);
        UI::clearScreen();

        UI::setColor("yellow");
        UI::typingEffect("\nGenerating Digital Ticket...");
        UI::delay(1);
        UI::resetColor();

        ticket.displayTicket();
        ticket.displayQRCode();

        nextTicketID++;

        delete vehicle;

        return;
    }
}

    UI::setColor("red");
    cout << "No Available Slots" << endl;
    UI::resetColor();

    delete vehicle;
}

// =========================================
// EXIT VEHICLE
// =========================================

void ParkingSystem::exitVehicle() {

    int ticketID = -1;
    string plate;
    int option;

    cout << "========================================" << endl;
    UI::setColor("cyan");
    cout << "         VEHICLE EXIT SYSTEM            " << endl;
    UI::resetColor();
    cout << "========================================" << endl;

    cout << "[1] Exit By Ticket ID" << endl;
    cout << "[2] Exit By Plate Number" << endl;

    cout << "========================================" << endl;
    UI::setColor("green");
    cout << "Select Option : ";
    UI::resetColor();
    cin >> option;

    if(option == 1){

        cout << "\nEnter Ticket ID : ";
        cin >> ticketID;
    }

    else if(option == 2){

        cout << "\nEnter Plate Number : ";
        cin >> plate;
    }

    else{

        UI::setColor("red");
        cout << "\nInvalid Option!" << endl;
        UI::resetColor();

        UI::clearScreen();
        UI::delay(1);
        exitVehicle();
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if(
            (option == 1 &&
            tickets[i].getTicketID() == ticketID)
            ||

            (option == 2 &&
            tickets[i].getPlateNumber() == plate)
        ) {

            // TIME CALCULATION

            time_t currentTime = time(0);
            double seconds =
                difftime(currentTime,
                    tickets[i].getEntryTime()
                );
            
            int minutes = seconds / 60;
            int hours = minutes / 60;
            int remainingMinutes = minutes % 60;
            if(remainingMinutes > 0){
                hours++;
            }
            if(hours == 0){
                hours = 1;
            }

            // FEE CALCULATION

            double fee;
            
            if(tickets[i].getVehicleType() == "Car"){
                fee = hours * 10;
            }
            else if(tickets[i].getVehicleType() == "Bus"){
                fee = hours * 20;
            }
            else if(tickets[i].getVehicleType() == "Truck"){
                fee = hours * 15;
            }
            else if(tickets[i].getVehicleType() == "Bike"){
                fee = hours * 5;
            }
            else if(tickets[i].getVehicleType() == "Motorcycle"){
                fee = hours * 3;
            }
            totalRevenue += fee;
            dailyRevenue += fee;

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
                tickets[i].getEntryTime(),
                hours,
                remainingMinutes
            );

            receipts.push_back(receipt);
            savereceipt();

            UI::setColor("green");

            UI::typingEffect("\nVerifying Ticket Information...");
            UI::delay(1);
            UI::typingEffect("\nCalculating Parking Duration...");
            UI::delay(1);
            UI::typingEffect("\nCalculating Payment...");
            UI::delay(1);
            UI::resetColor();

            UI::clearScreen();

            UI::setColor("yellow");
            UI::loadingMessage("\nGenerating Smart Receipt ");
            UI::delay(1);
            UI::resetColor();

            receipt.displayReceipt();
            nextReceiptID++;

            saveHistory(
                tickets[i].getPlateNumber(),
                tickets[i].getVehicleType(),
                fee
            );

            saveRevenue();

            // REMOVE ACTIVE TICKET

            string record =
                tickets[i].getVehicleType() + " | " +
                tickets[i].getPlateNumber() + " | Slot " +
                to_string(tickets[i].getSlotNumber()) +
                " | Paid " +
                to_string(fee) + " Birr";

            history.push_back(record);

            tickets.erase(
                tickets.begin() + i
            );
            saveActiveTickets();
            return;
        }
    }

    UI::setColor("red");
    cout << "Ticket Not Found" << endl;
    UI::resetColor();
}

// =========================================
// SHOW REVENUE
// =========================================

void ParkingSystem::showRevenue() {

    cout << endl;

    cout << "=================================" << endl;
    UI::setColor("green");
    cout << " Total Revenue : " << totalRevenue << " Birr" << endl;
    UI::resetColor();
    cout << "=================================" << endl;
}

void ParkingSystem::saveHistory(
    string plate,
    string type,
    double fee
)
{
    ofstream file(
        "data/history.txt",
        ios::app
    );

    if(file.is_open())
    {
        time_t currentTime = time(0);

        file
            << plate << " | "
            << type << " | "
            << fee << " Birr | "
            << ctime(&currentTime);

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
// =============================
//     PARKING HISTORY 
// =============================

void ParkingSystem::viewHistory(){
    cout << "\n========================================" << endl;
    UI::setColor("cyan");
    cout << "           PARKING HISTORY             " << endl;
    UI::resetColor();
    cout << "========================================" << endl;

    if(history.empty()){
        UI::setColor("red");
        cout << "No Parking History Found." << endl;
        UI::resetColor();
    }
    else{
        for(string record : history){
            cout << record << endl;
        }
    }
    cout << "========================================" << endl;
}

// =======================================
//           SEARCH VEHICLE
// =======================================
void ParkingSystem::searchVehicle(){
    int choice;

    cout << "\n========================================" << endl;
    UI::setColor("cyan");
    cout << "            SEARCH VEHICLE              " << endl;
    UI::resetColor();
    cout << "========================================" << endl;

    cout << "[1] Search By Plate Number" << endl;
    cout << "[2] Search By Ticket ID" << endl;

    cout << "========================================" << endl;

    cout << "Enter Choice: ";
    cin >> choice;

    bool found = false;

    // =====================================
    // SEARCH BY PLATE NUMBER
    // =====================================

    if(choice == 1){
        string plate;

        cout << "Enter Plate Number: ";
        cin >> plate;

        for(Ticket ticket : tickets){
            if(ticket.getPlateNumber() == plate){
                cout << "\n========================================" << endl;
                UI::setColor("green");
                cout << "           VEHICLE FOUND                " << endl;
                UI::resetColor();
                cout << "========================================" << endl;

                cout << " Vehicle Type : " << ticket.getVehicleType() << endl;
                cout << " Plate Number : " << ticket.getPlateNumber() << endl;
                cout << " Slot Number  : " << ticket.getSlotNumber() << endl;
                cout << " Ticket ID    : " << ticket.getTicketID() << endl;

                // TIME CALCULATION

                time_t currentTime = time(0);
                double seconds =
                    difftime(
                        currentTime,
                        ticket.getEntryTime()
                    );

                int minutes = seconds / 60;
                int hours = minutes / 60;
                int remainingMinutes = minutes % 60;

                cout << " Parked Time  : " << hours << " Hour(s) " << remainingMinutes << " Minute(s)" << endl;
                cout << "========================================" << endl;

                found = true;

                break;
            }
        }
    }

    // =====================================
    // SEARCH BY TICKET ID
    // =====================================

    else if(choice == 2){
        int id;

        cout << "Enter Ticket ID: ";
        cin >> id;

        for(Ticket ticket : tickets){
            if(ticket.getTicketID() == id){
                cout << "\n========================================" << endl;
                UI::setColor("green");
                cout << "           VEHICLE FOUND                " << endl;
                UI::resetColor();
                cout << "========================================" << endl;

                cout << " Vehicle Type : " << ticket.getVehicleType() << endl;
                cout << " Plate Number : " << ticket.getPlateNumber() << endl;
                cout << " Slot Number  : " << ticket.getSlotNumber() << endl;
                cout << " Ticket ID    : " << ticket.getTicketID() << endl;

                time_t currentTime = time(0);
                double seconds =
                    difftime(
                        currentTime,
                        ticket.getEntryTime()
                    );

                int minutes = seconds / 60;
                int hours = minutes / 60;
                int remainingMinutes = minutes % 60;

                cout << " Parked Time  : " << hours << " Hour(s) " << remainingMinutes << " Minute(s)" << endl;
                cout << "========================================" << endl;

                found = true;

                break;
            }
        }
    }

    else{
        UI::setColor("red");
        cout << "\nInvalid Choice" << endl;
        UI::resetColor();
        UI::delay(2);
        UI::clearScreen();
        return;
    }

    if(!found){
        UI::setColor("red");
        cout << "\nVehicle Not Found" << endl;
        UI::resetColor();
        searchVehicle();
    }
}

// =====================================
//       PARKING STATISTICS  
// =====================================
void ParkingSystem::showStatistics(){
    int totalVehicles = history.size();

    int activeVehicles = tickets.size();

    cout << "\n========================================" << endl;
    UI::setColor("yellow");
    cout << "         PARKING STATISTICS            " << endl;
    UI::resetColor();
    cout << "========================================" << endl;

    cout << " Total Vehicles Processed : " << totalVehicles << endl;
    cout << " Currently Parked Vehicles: " << activeVehicles << endl;
    cout << " Total Revenue            : " << totalRevenue << " Birr" << endl;

    cout << "========================================" << endl;
}

// =====================================
//     PARKING STATUS OVERVIEW
// =====================================
void ParkingSystem::showParkingOverview(){
    int available = 0;
    int occupied = 0;

    for(ParkingSlot slot : slots){
        if(slot.isOccupied()){
            UI::setColor("red");
            occupied++;
            UI::resetColor();
        }
        else{
            UI::setColor("green");
            available++;
            UI::resetColor();
        }
    }

    cout << "\n========================================" << endl;
    UI::setColor("cyan");
    cout << "       PARKING STATUS OVERVIEW         " << endl;
    UI::resetColor();
    cout << "========================================" << endl;

    cout << " Total Slots     : " << slots.size() << endl;
    cout << " Occupied Slots  : " << occupied << endl;
    cout << " Available Slots : " << available << endl;

    cout << "========================================" << endl;
}

// ====================================
//    DAILY REPORT
// ====================================

void ParkingSystem::generateDailyReport(){
    int occupied = 0;
    int available = 0;

    int cars = 0;
    int buses = 0;
    int trucks = 0;
    int bikes = 0;
    int motorcycles = 0;

    // COUNT ACTIVE VEHICLES

    for(Ticket ticket : tickets){
        string type =
            ticket.getVehicleType();

        if(type == "Car")
            cars++;

        else if(type == "Bus")
            buses++;

        else if(type == "Truck")
            trucks++;

        else if(type == "Bike")
            bikes++;

        else if(type == "Motorcycle")
            motorcycles++;
    }

    // SLOT STATUS

    for(ParkingSlot slot : slots){
        if(slot.isOccupied())
            occupied++;
        else
            available++;
    }

    // CURRENT DATE

    time_t now = time(0);

    char* dateTime = ctime(&now);

    // DISPLAY REPORT

    cout << "\n========================================" << endl;
    UI::setColor("cyan");
    cout << "           DAILY REPORT                 " << endl;
    UI::resetColor();
    cout << "========================================" << endl;

    cout << "Date : " << dateTime << endl;

    cout << "========================================" << endl;
    UI::setColor("green");
    cout << "          ACTIVE VEHICLES" << endl;
    UI::resetColor();
    cout << "========================================" << endl;

    cout << "  Cars         : " << cars << endl;
    cout << "  Buses        : " << buses << endl;
    cout << "  Trucks       : " << trucks << endl;
    cout << "  Bikes        : " << bikes << endl;
    cout << "  Motorcycles  : " << motorcycles << endl;

    cout << "========================================" << endl;

    cout << "  Occupied Slots : " << occupied << endl;
    cout << "  Available Slots: "<< available << endl;
    cout << "  Today's Revenue : " << dailyRevenue << " Birr" << endl; 
    cout << "  Overall Revenue : " << totalRevenue << " Birr" << endl;

    cout << "========================================" << endl;

    // SAVE REPORT FILE

    ofstream report(
        "data/daily_report.txt"
    );

    if(report.is_open())
    {
        report << "========== DAILY REPORT ==========\n";

        report << "  Date: " << dateTime << endl;
        report << "  Cars: " << cars << endl;
        report << "  Buses: " << buses << endl;
        report << "  Trucks: " << trucks << endl;
        report << "  Bikes: " << bikes << endl;
        report << "  Motorcycles: " << motorcycles << endl;
        report << "  Occupied Slots: " << occupied << endl;
        report << "  Available Slots: " << available << endl;
        report << "  Total Revenue: " << totalRevenue << " Birr" << endl;

        report << "========================================" << endl;

        report.close();
    }
}

// ================================
//      PARKING MAP VIEW 
// ================================

void ParkingSystem::showParkingMap(){
    cout << "\n========================================" << endl;
    UI::setColor("cyan");
    cout << "           PARKING MAP VIEW             " << endl;
    UI::resetColor();
    cout << "========================================" << endl;

    // =====================================
    // CAR SECTION
    // =====================================

    UI::setColor("cyan");
    cout << "\n    CAR SLOTS\n" << endl;
    UI::resetColor();
    cout << "========================================" << endl;
    for(int i = 0; i < 15; i++){
        if(slots[i].isOccupied()){
            UI::setColor("red");
            cout << "[X]";
            UI::resetColor();
        }else{
            UI::setColor("green");
            cout << "[A]";
            UI::resetColor();
        }
        cout << "C" << slots[i].getSlotID() << "  ";

        if((i + 1) % 5 == 0)
            cout << endl;
    }

    // =====================================
    // BUS SECTION
    // =====================================

    cout << "========================================" << endl;
    UI::setColor("cyan");
    cout << "\n   BUS SLOTS\n" << endl;
    UI::resetColor();
    cout << "========================================" << endl;

    for(int i = 15; i < 30; i++){
        if(slots[i].isOccupied()){
            UI::setColor("red");
            cout << "[X]";
            UI::resetColor();
        }else{
            UI::setColor("green");
            cout << "[A]";
            UI::resetColor();
        }
        cout << "BS" << slots[i].getSlotID() << "  ";

        if((i - 14) % 5 == 0)
            cout << endl;
    }

    // =====================================
    // TRUCK SECTION
    // =====================================

    cout << "========================================" << endl;
    UI::setColor("cyan");
    cout << "\n  TRUCK SLOTS\n" << endl;
    UI::resetColor();
    cout << "========================================" << endl;

    for(int i = 30; i < 40; i++){
        if(slots[i].isOccupied()){
            UI::setColor("red");
            cout << "[X]";
            UI::resetColor();
        }else{
            UI::setColor("green");
            cout << "[A]";
            UI::resetColor();
        }
        cout << "T" << slots[i].getSlotID() << "  ";

        if((i - 29) % 5 == 0)
            cout << endl;
    }

    // =====================================
    // BIKE SECTION
    // =====================================

    cout << "========================================" << endl;
    UI::setColor("cyan");
    cout << "\n   BIKE SLOTS\n" << endl;
    UI::resetColor();
    cout << "========================================" << endl;

    for(int i = 40; i < 60; i++){
        if(slots[i].isOccupied()){
            UI::setColor("red");
            cout << "[X]";
            UI::resetColor();
        }else{
            UI::setColor("green");
            cout << "[A]";
            UI::resetColor();
        }
        cout << "BK" << slots[i].getSlotID() << " ";

        if((i - 39) % 5 == 0)
            cout << endl;
    }

    // =====================================
    // MOTORCYCLE SECTION
    // =====================================

    cout << "========================================" << endl;
    UI::setColor("cyan");
    cout << "\n  MOTORCYCLE SLOTS\n" << endl;
    UI::resetColor();
    cout << "========================================" << endl;
    for(int i = 60; i < 80; i++){
        if(slots[i].isOccupied()){
            UI::setColor("red");
            cout << "[X]";
            UI::resetColor();
        }else{
            UI::setColor("green");
            cout << "[A]";
            UI::resetColor();
        }
        cout << "M" << slots[i].getSlotID() << " ";

        if((i - 59) % 5 == 0)
            cout << endl;
    }
    cout << "========================================" << endl;

    cout << endl;

    cout << "\n========================================" << endl;
    UI::setColor("green");
    cout << "   [A] = Available Slot" << endl;
    UI::resetColor();
    UI::setColor("red");
    cout << "   [X] = Occupied Slot" << endl;
    UI::resetColor();
    cout << "========================================" << endl;
}

// =======================================
//     SAVE ACTIVE TICKETS
// =======================================

void ParkingSystem::saveActiveTickets(){
    ofstream file(
        "data/active_tickets.txt"
    );

    if(file.is_open()){
        for(Ticket ticket : tickets){
            file
                << ticket.getTicketID() << "|"
                << ticket.getSlotNumber() << "|"
                << ticket.getPlateNumber() << "|"
                << ticket.getVehicleType() << "|"
                << ticket.getEntryTime()
            << endl;
        }

        file.close();
    }
}

// =====================================
//    LOAD ACTIVE TICKET
// =====================================

void ParkingSystem::loadActiveTickets(){
    ifstream file(
        "data/active_tickets.txt"
    );

    if(file.is_open()){
        string line;

        while(getline(file, line)){
            stringstream ss(line);

            string ticketID,
                   slot,
                   plate,
                   type,
                   entry;

            getline(ss, ticketID, '|');
            getline(ss, slot, '|');
            getline(ss, plate, '|');
            getline(ss, type, '|');
            getline(ss, entry, '|');

            Ticket ticket(

                stoi(ticketID),
                stoi(slot),
                plate,
                type,
                stol(entry)
            );

            tickets.push_back(ticket);

            if(stoi(ticketID) >= nextTicketID){
                nextTicketID = stoi(ticketID) + 1;
            }

            // RESTORE SLOT OCCUPANCY

            for(auto &slotObj : slots){
                if(
                    slotObj.getSlotID()
                    ==
                    stoi(slot)
                ){
                    slotObj.occupySlot();
                }
            }
        }
        file.close();
    }
}

// =========================================
//      LOAD HISTORY
// =========================================

void ParkingSystem::loadHistory(){
    ifstream file("data/history.txt");

    string line;

    while(getline(file, line)){
        history.push_back(line);
    }
    file.close();
}

// ========================================
//          LOAD REVENUE
// ========================================

void ParkingSystem::loadRevenue(){
    ifstream file("data/revenue.txt");

    if(file.is_open()){
        file >> totalRevenue;
        file.close();
    }
}

// ========================================
//     SAVE RECEIPT
// ========================================

void ParkingSystem::savereceipt() {

    ofstream file(
        "data/receipt.txt"
    );

    if (file.is_open()) {

        file << totalRevenue;
        file.close();
    }
}