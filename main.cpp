// main.cpp
#include <iostream>
#include <vector>
#include "Cottage.h"
#include "Apartment.h"

void displayProperties(const std::vector<RealEstate>& properties);
void modifyProperty(std::vector<RealEstate>& properties);
double calculateMaxArea(const std::vector<RealEstate>& properties);

int main() {
    std::vector<RealEstate> properties;
    int choice;
    
    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Cottage\n";
        std::cout << "2. Add Apartment\n";
        std::cout << "3. Display Properties\n";
        std::cout << "4. Modify Property\n";
        std::cout << "5. Calculate Maximum Area\n";
        std::cout << "6. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;
        std::cin.ignore(); // Очистка буфера ввода

        switch (choice) {
            case 1: {
                std::string location;
                double area;
                int floors;

                std::cout << "Enter location: ";
                std::getline(std::cin, location);
                std::cout << "Enter area: ";
                std::cin >> area;
                std::cout << "Enter number of floors: ";
                std::cin >> floors;

                properties.push_back(new Cottage(location, area, floors));
                break;
            }
            case 2: {
                std::string location;
                double area;
                int roomCount;

                std::cout << "Enter location: ";
                std::getline(std::cin, location);
                std::cout << "Enter area: ";
                std::cin >> area;
                std::cout << "Enter number of rooms: ";
                std::cin >> roomCount;

                properties.push_back(new Apartment(location, area, roomCount));
                break;
            }
            case 3:
                displayProperties(properties);
                break;
            case 4:
                modifyProperty(properties);
                break;
            case 5: {
                double maxArea = calculateMaxArea(properties);
                std::cout << "Maximum Area: " << maxArea << std::endl;
                break;
            }
            case 6:
                for (auto& prop : properties) {
                    delete prop; // Освобождение памяти
                }
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void displayProperties(const std::vector<RealEstate>& properties) {
    for (size_t i = 0; i < properties.size(); i++) {
        std::cout << "Property " << i + 1 << ": ";
        properties[i]->display();
    }
}

void modifyProperty(std::vector<RealEstate>& properties) {
    int index;

    std::cout << "Enter the index of the property to modify: ";
    std::cin >> index;

    if (index < 1 || index > properties.size()) {
        std::cout << "Invalid index!\n";
        return;
    }

    RealEstate property = properties[index - 1];
    if (Cottage cottage = dynamic_cast<Cottage>(property)) {
        int newFloors;
        std::cout << "Enter new number of floors: ";
        std::cin >> newFloors;
        cottage->setFloors(newFloors);
    } else if (Apartment apartment = dynamic_cast<Apartment>(property)) {
        int newRoomCount;
        std::cout << "Enter new number of rooms: ";
        std::cin >> newRoomCount;
        apartment->setRoomCount(newRoomCount);
    }
}

double calculateMaxArea(const std::vector<RealEstate>& properties) {
    double maxArea = 0;

    for (const auto& property : properties) {
        if (property->getArea() > maxArea) {
            maxArea = property->getArea();
        }
    }

    return maxArea;
}