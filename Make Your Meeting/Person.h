#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "Car.h"
#include <utility>

class Person
{
    private:
        std::string name, email;
        std::unique_ptr<Car> personCar;

    public: 

        // Constructor that sets name, email and car given parameters
        Person(std::string n, std::string e, std::unique_ptr<Car> personCar = nullptr);

        // Declare get/set
        std::string getName() const;
        std::string getEmail() const;
        void setEmail(std::string e);

        // Check if you have car and available seats
        bool hasAvailableSeats() const;

        // Overload << operator
        friend std::ostream& operator<<(std::ostream& os, const Person& p);
};
