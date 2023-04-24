#include "Person.h"
#include "Car.h"

// Implement constructor with member initializer list
Person::Person(std::string n, std::string e, std::unique_ptr<Car> personCar)
    : name(n), email(e), personCar(std::move(personCar))
{
}

// Implement get-/set
std::string Person::getName() const{return name;}
std::string Person::getEmail() const{return email;}
void Person::setEmail(std::string e){this->email = e;}

// has car and available seats check

bool Person::hasAvailableSeats() const
{
    if (personCar && personCar->hasFreeSeats())
    {
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << "Name: " << p.getName() << std::endl;
    os << "Email: " << p.getEmail() << std::endl;

    // Progammet kræsjer om person ikke har bil
    if (p.personCar != nullptr)
    {
        auto seats = p.personCar->hasFreeSeats();
        os << "Free seats in car: " << seats << std::endl;
    }
    else
    {
        os << p.getName() << " has no car." << std::endl;
    }
    os << "\n";
    return os;
}


