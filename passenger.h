#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>
using namespace std;

class Passenger
{
    //private data members
    private:
    string passengerName;
    int passengerAge;
    string passportNumber;

    public:
    Passenger(string name, int age, string passport) //parametrized constructor
    {
        passengerName = name;
        passengerAge = age; 
        passportNumber = passport;
    }

    string getPassengerName() //getter functions to access private data members
    {
        return passengerName;
    }

    int getPassengerAge()
    {
        return passengerAge;
    }

    string getPassportNumber()
    {
        return passportNumber;
    }

    friend void displayPassengerDetails(Passenger passenger); //friend function which allows us to display passenger details without having to use dot operator in main
};

void displayPassengerDetails(Passenger passenger) 
{
    //accessing the private members of the Passenger class directly
    cout << "=== Passenger details ===" << endl;
    cout << "Passenger Name: " << passenger.getPassengerName() << endl;
    cout << "Passenger Age: " << passenger.getPassengerAge() << endl;
    cout << "Passport Number: " << passenger.getPassportNumber() << endl;
    cout << "=======================" << endl;;
}

#endif