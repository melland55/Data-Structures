#include "flight.h"
#include <stdio.h>
#include <string.h>

Flight::Flight()
{
    name = "";
    price = 0;
    time = 0;
}

Flight::Flight(const Flight &flight)
{
    name = new char[100];
    strncpy(name, flight.name, 100);
    price = flight.price;
    time = flight.time;
}

Flight::~Flight(){
    delete[] name;
}



Flight& Flight::operator=(const Flight& flight){
    name = new char[100];
    strncpy(name, flight.name, 100);
    price = flight.price;
    time = flight.time;
    return *this;
}

Flight::Flight(char* cityName, int cost, int duration){
    name = new char[100];
    strncpy(name, cityName, 100);
    price = cost;
    time = duration;
}
