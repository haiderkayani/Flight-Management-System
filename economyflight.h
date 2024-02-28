#ifndef ECONOMYFLIGHT_H
#define ECONOMYFLIGHT_H

#include "flight.h"
#include "passenger.h"

class EconomyFlight: public Flight
{
    private:
    static const int MAX_PASSENGERS = 150; //setting max passengers for economy class
    Passenger* passengers[MAX_PASSENGERS];
    int numberOfPassengers;
    
    public:
    EconomyFlight(int number, string dep, string arrival, int seats): Flight(number, dep, arrival, seats){} //parametrized constructor

    //virtual destructor
    virtual ~EconomyFlight() {}

    bool addPassenger(Passenger passenger, string passport) override
    {
        if(numberOfPassengers < MAX_PASSENGERS)
        {
            passengers[numberOfPassengers] = new Passenger(passenger.getPassengerName(), passenger.getPassengerAge(), passenger.getPassportNumber());
            numberOfPassengers++;
            return true;
        }
        else
        {
            return false;
        }
    }

    // int getNumberofPassengers() override
    // {
    //     return numberOfPassengers;
    // }

    // Passenger* getPassenger(int index) override
    // {
    //     if(index>=0 && index<numberOfPassengers)
    //     {
    //         return passengers[index];
    //     }
    //     return NULL;
    // }

    void display() override
    {
        cout << "\nEconomy class: " << endl;
        Flight::display();
    }
};

#endif