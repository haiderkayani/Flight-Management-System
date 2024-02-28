#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
#include <string>
#include "passenger.h"
using namespace std;

class Flight
{
    private:
    int flightNumber;
    string departureCity;
    string arrivalCity;
    int totalSeats;
    int reservedSeats;

    public:
    Flight(int number, string dep, string arrival, int seats) //parametrized constructor
    {
        flightNumber = number;
        departureCity = dep;
        arrivalCity = arrival;
        totalSeats = seats;
        reservedSeats = 0;
    }

    //virtual destructor
    virtual ~Flight() {}

    int getFlightNumber() //getter functions to return private data memebrs
    {
        return flightNumber;
    }

    string getDepartureCity()
    {
        return departureCity;
    }

    string getArrivalCity()
    {
        return arrivalCity;
    }

    int getTotalSeats()
    {
        return totalSeats;
    }

    int getReservedSeats()
    {
        return reservedSeats;
    }

    bool reserveSeats(int bookSeats)
    {
        int remainingSeats = totalSeats - reservedSeats;
        if(bookSeats <= remainingSeats)
        {
            reservedSeats = bookSeats + reservedSeats;
            return true;
        }
        else
        {
            return false;
        }
    }

    virtual bool addPassenger(Passenger passenger, string passport) = 0; //virtual function which is overriden in business and economy header files

    // virtual int getNumberofPassengers() = 0;

    // virtual Passenger* getPassenger(int index) = 0;

    // friend void displayPassengerDetails(Passenger passenger);

    virtual void display()
    {
        cout << "Flight " << flightNumber << " from " << departureCity << " to " << arrivalCity << ":" << endl;
        cout << "Capacity: " << totalSeats << endl;
        cout << "Reserved seats: " << reservedSeats << endl;
    }
};

#endif