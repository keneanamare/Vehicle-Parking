#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <ctime>
using namespace std;

// =========================================
// BASE VEHICLE CLASS
// =========================================

class Vehicle {
protected:
    string plateNumber;
    string vehicleType;
    time_t entryTime;

public:
    Vehicle(string plate, string type);

    // Pure Virtual Function
    virtual double calculateFee(int hours) = 0;

    // Getters
    string getPlateNumber();
    string getVehicleType();
    time_t getEntryTime();

    // Display Function
    virtual void displayInfo();

    // Virtual Destructor
    virtual ~Vehicle();
};

// =========================================
// CAR CLASS
// =========================================

class Car : public Vehicle {
public:
    Car(string plate);

    double calculateFee(int hours) override;
};

// =========================================
// BIKE CLASS
// =========================================

class Bike : public Vehicle {
public:
    Bike(string plate);

    double calculateFee(int hours) override;
};

// =========================================
// TRUCK CLASS
// =========================================

class Truck : public Vehicle {
public:
    Truck(string plate);

    double calculateFee(int hours) override;
};

#endif