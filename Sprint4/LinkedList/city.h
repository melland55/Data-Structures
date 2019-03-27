#ifndef CITY_H
#define CITY_H
#include "list.h"
#include "flight.h"


class City
{
public:
    City();
    City(char* str);
    char* name;
    List<Flight> data;
};

#endif // CITY_H
