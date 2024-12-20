// Apartment.h
#ifndef APARTMENT_H
#define APARTMENT_H

#include "RealEstate.h"

class Apartment : public RealEstate {
private:
    int roomCount; // Количество комнат

public:
    Apartment(const std::string& loc, double area, int roomCount);
    
    void display() const override; // Переопределение виртуальной функции
    void setRoomCount(int rc);      // Собственный метод для изменения количества комнат
};

#endif // APARTMENT_H