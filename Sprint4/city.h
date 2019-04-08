#ifndef CITY_H
#define CITY_H
#include "list.h"
#include "flight.h"


class City
{
public:
    City();
    ~City();
    City(char* str);
    City(const City &city);
    City& operator=(const City& city);
    char* name;
    List<Flight> data;
};

#endif // CITY_H
