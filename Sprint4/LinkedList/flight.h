#ifndef FLIGHT_H
#define FLIGHT_H


class Flight
{
public:
    Flight();
    Flight(char* cityName, int cost, int duration);
    char* name;
    int price;
    int time;
};

#endif // FLIGHT_H
