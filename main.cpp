#include "airline.h"
#include "businessflight.h"
#include "economyflight.h"
#include <iostream>
#include <stdexcept>

int main() 
{
    //creating flights
    BusinessFlight* flight1 = new BusinessFlight(202, "London", "Paris", 50);
    EconomyFlight* flight2 = new EconomyFlight(303, "Tokyo", "Beijing", 100);

    //creating airlines
    Airline airline;
    airline.addFlight(flight1);
    airline.addFlight(flight2);

    int choice;
    bool exit = false;

    while (!exit) 
    {
        //try block which contiains main code
        try 
        {
            //menu options to choose
            cout << "Welcome to the Flight Management System" << endl;
            cout << "1. Display all flights" << endl;
            cout << "2. Reserve a seat" << endl;
            cout << "3. Display passenger details" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";

            cin >> choice;

            switch(choice) 
            {
                case 1:
                {
                    //displaying all current flights
                    airline.displayFlights();
                    break;
                }

                case 2: 
                {
                    //reserve seat
                    int flightNumber, seatsToBook;
                    string name, passport;
                    int age;

                    cout << "Enter flight number: ";
                    cin >> flightNumber;

                    cout << "Enter number of seats to book: ";
                    cin >> seatsToBook;

                    if(seatsToBook <= 0) //validating input 
                    {
                        cout << "Invalid input." << endl;
                        break;
                    }

                    cout << "Enter passenger name: ";
                    cin.ignore(); //ignoring newline character
                    getline(cin, name);

                    cout << "Enter passenger age: ";
                    cin >> age;

                    if(age <= 0) //validating input
                    {
                        cout << "Invalid age." << endl;
                        break;
                    }

                    cout << "Enter passenger passport number: ";
                    cin.ignore(); 
                    getline(cin, passport); //gets entire string instead of just first word

                    if(passport.empty()) //validating input
                    {
                        cout << "Invalid passport number." << endl;
                        break;
                    }

                    Passenger passenger(name, age, passport);
                    bool reservationStatus = airline.reserveSeat(flightNumber, seatsToBook, passenger, passport);
                    if(reservationStatus) 
                    {
                        cout << "Seat(s) reserved successfully!" << endl;
                    } 
                    else 
                    {
                        cout << "Failed to reserve seat(s)." << endl;
                    }
                    break;
                }

                case 3: 
                {
                    //displaying passenger details
                    string passport;
                    cout << "Enter passenger passport number: ";
                    cin.ignore(); 
                    getline(cin, passport);

                    //searching for passenger by passport no.
                    Passenger passengerToDisplay("", 0, passport);

                    cout << "=== Passenger details ===" << endl;
                    if(passengerToDisplay.getPassengerName() != "") //checking if passenger actually has name
                    {
                        //passenger found
                        displayPassengerDetails(passengerToDisplay);
                    } 
                    else 
                    {
                        //passenger not found
                        cout << "Passenger with passport number '" << passport << "' not found." << endl;
                    }
                    cout << "=========================" << endl;
                    break;
                }

                case 4:
                {
                    //exit app
                    exit = true;
                    break;
                }

                default:
                {
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            }
            cout << endl;
        }
        catch(exception e) //to deal with exceptions like invalid arguments or out of range arguments
        {
            cerr << "Error: " << e.what() << endl;
        }
        catch(...) //to deal with any other error 
        {
            cerr << "Unknown error occured." << endl;
        }
    }

    //cleaning up memory
    delete flight1;
    delete flight2;

    return 0;
}
