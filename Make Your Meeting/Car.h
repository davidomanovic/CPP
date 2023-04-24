#pragma once

class Car
{
    private:
        int freeSeats; // how many free seats in car
    
    public:
        bool hasFreeSeats() const;
        void reserveFreeSeat();
        Car(int seats){freeSeats = seats;}
};
