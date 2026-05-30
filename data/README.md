# 🚗 Intelegent Smart Parking Management System with Automatic Slot Allocation and Fee Calculation

## 📌 Project Overview
The Smart Parking Management System is an Object-Oriented Programming (OOP) project developed using C++. The system is designed to automate and manage vehicle parking operations efficiently. It allows vehicles to enter and exit the parking area, allocates parking slots automatically, generates parking tickets and receipts, calculates parking fees, and tracks parking slot availability.

This project demonstrates real-world implementation of Object-Oriented Programming concepts such as classes, objects, encapsulation, inheritance, polymorphism, abstraction, constructors, destructors, modular programming, and software design principles.

# 🎯 Project Objectives

- Automate parking management operations
- Reduce manual parking management problems
- Manage available and occupied parking slots
- Generate parking tickets automatically
- Calculate parking fees based on parking duration
- Generate payment receipts
- Demonstrate practical implementation of OOP concepts
- Improve software modularity and scalability

# 🛠️ Technologies Used

| Technology | Purpose |
|------------|---------|
| C++ | Core Programming Language |
| OOP Concepts | Software Design |
| STL Vector | Dynamic Data Storage |
| File Handling (Optional) | Data Persistence |
| HTML/CSS/JavaScript (Future Upgrade) | Web Interface |

# 📚 OOP Concepts Implemented

## 1. Classes and Objects
The project uses multiple classes such as:
- Vehicle
- Car
- Bike
- Bus
- Motor cycle
- Truck
- ParkingSlot
- Ticket
- Receipt
- ParkingSystem
- UI

Objects are created from these classes to simulate real-world parking operations.

## 2. Encapsulation
Private data members are used to protect system data such as:
- ticketID
- plateNumber
- occupied status
- parking fee

Public getter and setter functions provide controlled access to data.

## 3. Inheritance
The project uses single inheritance.

Example:
    class Car : public Vehicle

How to compile and run the program

first do this in your compiler
    g++ main.cpp Vehicle.cpp ParkingSlot.cpp Ticket.cpp Receipt.cpp ParkingSystem.cpp UI.cpp User.cpp -o ParkingSystem
then run this command
    ./ParkingSystem