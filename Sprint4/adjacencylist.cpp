#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "city.h"
#include "adjacencylist.h"

AdjacencyList::AdjacencyList(){

}

Node<City>* AdjacencyList::getHead(){
    return citys.head;
}

Node<City>* AdjacencyList::getTail(){
    return citys.head;
}

void AdjacencyList::add(char* departure, char* destination, int price, int length){
    Node<City>* temp = citys.head;
    bool dest = true;
    bool depart = true;
    while(temp != nullptr){
        if(strcmp(temp->data.name, departure) == 0){
            depart = false;
            Flight flight(destination, price, length);
            temp->data.data.push_back(flight);
        }else if(strcmp(temp->data.name, destination) == 0){
            dest =false;
            Flight flight(departure, price, length);
            temp->data.data.push_back(flight);
        }
        temp = temp->next;
    }
    if(depart){
        City city(departure);
        citys.push_back(city);
        Flight flight(destination, price, length);
        citys.tail->data.data.push_back(flight);
    }
    if(dest){
        City city(destination);
        citys.push_back(city);
        Flight flight(departure, price, length);
        citys.tail->data.data.push_back(flight);
    }
}

List<Stack> AdjacencyList::getFlights(char* depart, char* dest){
    List<Stack> list;
    int sum = 0;
    char* last;
    while(sum != 4){

        Stack stack;
        last = nullptr;
        int temp = sum;
        City* x = &find(depart)->data;
        stack.push_back(x);
        while(strcmp(stack.peek()->data->name, dest) != 0){
            City* y = findNext(stack, last);
            if(y != nullptr){
                stack.push_back(y);
                if(temp > 0 && strcmp(stack.peek()->data->name, dest) == 0){
                    data = &list.head->data;
                    temp--;
                    City* z = stack.peek()->data;
                    stack.pop_back();
                    last = z->name;
                }
            }else{
                return list;
            }
        }
        if(strcmp(stack.peek()->data->name, dest) == 0){
            sum++;
            list.push_back(stack);
        }else{
            break;
        }
    }
    return list;
}

Node<City>* AdjacencyList::find(char* str){
    Node<City>* temp = citys.head;
    while(temp != nullptr){
        if(strcmp(temp->data.name, str) == 0){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

Node<City>* AdjacencyList::findFlight(char* str, char* cur){
    Node<City>* city = this->find(cur);
    Node<Flight>* temp = city->data.data.head;
    while(temp != nullptr){
        if(strcmp(temp->data.name, str) == 0 && temp->next){
            return this->find(temp->next->data.name);
        }
        temp = temp->next;
    }
    return nullptr;
}

City* AdjacencyList::findNext(Stack& stack, char* &str){
    if(str == nullptr){
        Node<Flight>* temp = stack.peek()->data->data.head;
        while(temp != nullptr){
            if(!stack.contains(temp->data.name)){
                return &find(temp->data.name)->data;
            }
            temp = temp->next;
        }
        City* x = stack.peek()->data;
        stack.pop_back();
        str = x->name;
        if(stack.isEmpty()){
            return nullptr;
        }
        return findNext(stack, str);
    }else{
        Node<Flight>* temp = stack.peek()->data->data.head;
        while(temp->next != nullptr && strcmp(temp->data.name, str) != 0){
            temp = temp->next;
        }
        if(stack.peek()->data->data.tail == temp){
            City* x = stack.peek()->data;
            stack.pop_back();
            str = x->name;
            if(stack.isEmpty()){
                return nullptr;
            }
            return findNext(stack, str);
        }else{
            temp = temp->next;
            while(temp != nullptr){
                if(!stack.contains(temp->data.name)){
                    str = nullptr;
                    return &find(temp->data.name)->data;
                }
                temp = temp->next;
            }
            City* x = stack.peek()->data;
            stack.pop_back();
            str = x->name;
            return findNext(stack, str);
        }
    }
}
