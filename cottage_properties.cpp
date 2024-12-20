#ifndef COTTAGE_H
#define COTTAGE_H

#include "RealEstate.h"

class Cottage : public RealEstate {
private:
    int floors; // Количество этажей

public:
    Cottage(const std::string& loc, double area, int floors);
    
    void display() const override; // Переопределение виртуальной функции
    void setFloors(int f);          // Собственный метод для изменения количества этажей
};

#endif