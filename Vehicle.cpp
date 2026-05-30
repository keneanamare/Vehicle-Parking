#include "Vehicle.h"

// =========================================
// VEHICLE CONSTRUCTOR
// =========================================

Vehicle::Vehicle(string plate, string type) {
    plateNumber = plate;
    vehicleType = type;
    entryTime = time(0);
}

// =========================================
// GETTERS
// =========================================

string Vehicle::getPlateNumber() {
    return plateNumber;
}

string Vehicle::getVehicleType() {
    return vehicleType;
}

time_t Vehicle::getEntryTime() {
    return entryTime;
}

// =========================================
// DISPLAY FUNCTION
// =========================================

void Vehicle::displayInfo() {
    cout << "Plate Number : " << plateNumber << endl;
    cout << "Vehicle Type : " << vehicleType << endl;
}

// =========================================
// DESTRUCTOR
// =========================================

Vehicle::~Vehicle() {
    // Destructor
}

// =========================================
// CAR IMPLEMENTATION
// =========================================

Car::Car(string plate)
    : Vehicle(plate, "Car") {}

double Car::calculateFee(int hours) {
    return hours * 10;
}

// =========================================
// BIKE IMPLEMENTATION
// =========================================

Bike::Bike(string plate)
    : Vehicle(plate, "Bike") {}

double Bike::calculateFee(int hours) {
    return hours * 5;
}

// =========================================
// TRUCK IMPLEMENTATION
// =========================================

Truck::Truck(string plate)
    : Vehicle(plate, "Truck") {}

double Truck::calculateFee(int hours) {
    return hours * 15;
}
// ========================================
// Bus IMPLEMENTATION
// ========================================
Bus::Bus(string plate)
    : Vehicle(plate, "Bus"){}

double Bus::calculateFee(int hours)
{
    return hours * 20;
}

// ========================================
// MOTORCYCLE IMPLEMENTATION
// ========================================

Motorcycle::Motorcycle(string plate)
    : Vehicle(plate, "Motorcycle"){}

double Motorcycle::calculateFee(int hours)
{
    return hours * 20;
}
