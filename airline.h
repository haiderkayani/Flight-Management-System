#ifndef AIRLINE_H
#define AIRLINE_H

#include "flight.h"
#include "passenger.h"

class Airline
{
    private:
    static const int MAX_FLIGHTS = 100; //max flights the system can manage at one time
    Flight* flights[MAX_FLIGHTS];
    int numberOfCurrentFlights;

    public:
    Airline() //default constructor
    {
        for(int i=0; i<MAX_FLIGHTS; i++)
        {
            flights[i] = NULL;
        }
        numberOfCurrentFlights = 0;
    };
    ~Airline() //destructor
    {
        for(int i=0; i<numberOfCurrentFlights; i++)
        {
            delete flights[i];
        }
    };

    void addFlight(Flight* flight)
    {
        if(numberOfCurrentFlights < MAX_FLIGHTS)
        {
            flights[numberOfCurrentFlights] = flight;
            numberOfCurrentFlights++;
        }
        else
        {
            cout << "Error. Maximum number of flights reached." << endl;
        }
    }

    void displayFlights()
    {
        cout << "==== All Flights ====" << endl;
        for(int i=0; i<numberOfCurrentFlights; i++)
        {
            flights[i]->display();
        }
        cout << "=====================" << endl;
    }

    bool reserveSeat(int flightNumber, int bookSeats, Passenger passenger, string passport)
    {
        for(int i=0; i<numberOfCurrentFlights; i++)
        {
            if(flights[i]->getFlightNumber() == flightNumber)
            {
                if(flights[i]->reserveSeats(bookSeats))
                {
                    flights[i]->addPassenger(passenger, passport);
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        return false;
    }

    // void displayPassengerDetails(string passport)
    // {
    //     bool passengerfound = false;
    //     cout << "=== Passenger details ===" << endl;
    //     for(int i=0; i<numberOfCurrentFlights; i++)
    //     {
    //         Flight* flight = flights[i];
    //         for(int j=0; j<flight->getNumberofPassengers(); j++)
    //         {
    //             Passenger* passenger = flight->getPassenger(j);
    //             if(passenger->getPassportNumber() == passport)
    //             {
    //                 passengerfound = true;
    //                 cout << "Flight " << flight->getFlightNumber() << " - " << flight->getDepartureCity() << " to " << flight->getArrivalCity() << endl;
    //                 cout << "Passenger Name: " << passenger->getPassengerName() << ", Age: " << passenger->getPassengerAge() << ", Passport: " << passenger->getPassportNumber() << endl;
    //             }
    //         }
    //     }
    //     if (!passengerfound)
    //     {
    //         cout << "Passenger with passport number '" << passport << "' not found." << endl;
    //     }
    //     cout << "===========================" << endl;        
    // }
};

#endif