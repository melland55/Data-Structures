#include "city.h"
#include <stdio.h>
#include <string.h>

City::City(){

}

City::City(const City &city){
    name = new char[100];
    strncpy(name, city.name, 100);
    data = city.data;
}

City::~City(){
    delete[] name;
}


City& City::operator=(const City& city){
    name = new char[100];
    strncpy(name, city.name, 100);
    data = city.data;
    return *this;
}

City::City(char* str){
    name = new char[100];
    strncpy(name, str, 100);
}
