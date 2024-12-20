// Apartment.cpp
#include "Apartment.h"

Apartment::Apartment(const std::string& loc, double area, int roomCount) 
    : RealEstate(loc, area), roomCount(roomCount) {}

void Apartment::display() const {
    RealEstate::display(); // Вызов метода родительского класса
    std::cout << "Room count: " << roomCount << std::endl;
}

void Apartment::setRoomCount(int rc) {
    if (rc > 0) {
        roomCount = rc;
    } else {
        std::cout << "Number of rooms must be positive!" << std::endl;
    }
}