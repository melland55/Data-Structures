#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#include "list.h"
#include "city.h"
#include "stack.h"

class AdjacencyList
{
public:
    AdjacencyList();
    Node<City>* getHead();
    Node<City>* getTail();
    void add(char* departure, char* destination, int price, int length);
    List<Stack> getFlights(char*, char*);
    Node<City>* findFlight(char* str, char* cur);
    Node<City>* find(char*);
    City* findNext(Stack&, char*&);
private:
    List<City> citys;
    Stack* data;
};

#endif // ADJACENCYLIST_H
