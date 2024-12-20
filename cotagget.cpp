// Cottage.cpp
#include "Cottage.h"

Cottage::Cottage(const std::string& loc, double area, int floors) 
    : RealEstate(loc, area), floors(floors) {}

void Cottage::display() const {
    RealEstate::display(); // Вызов метода родительского класса
    std::cout << "Floors: " << floors << std::endl;
}

void Cottage::setFloors(int f) {
    if (f > 0) {
        floors = f;
    } else {
        std::cout << "Number of floors must be positive!" << std::endl;
    }
}