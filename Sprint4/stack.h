#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "list.h"
#include "flight.h"
#include "city.h"
#include "stack.h"

using namespace std;

class Stack
{
public:
    Stack();
    void push_back(City*);
    void pop_back();
    Node<City*>* peek();
    bool isEmpty();
    void flip();
    bool contains(char*);
    void print(ofstream & outfile);
    int getPrice();
    int getTime();
private:
    List<City*> data;
};

#endif // STACK_H
