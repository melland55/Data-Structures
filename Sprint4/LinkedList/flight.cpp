#include "flight.h"

Flight::Flight()
{
    name = "";
    price = 0;
    time = 0;
}

Flight::Flight(char* cityName, int cost, int duration){
    name = cityName;
    price = cost;
    time = duration;
}
