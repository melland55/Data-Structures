#include <iostream>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "list.h"
#include "city.h"

using namespace std;

Stack::Stack()
{
    data.tail = data.head;
}


void Stack::push_back(City* city){
    data.push_back(city);
}

void Stack::pop_back(){
    if(data.head->next == nullptr){
        delete data.head;
        data.head = nullptr;
        data.tail = nullptr;
        return;
    }
    data.tail = data.tail->prev;
    delete data.tail->next;
    data.tail->next = nullptr;
}

Node<City*>* Stack::peek(){
    return data.tail;
}

bool Stack::isEmpty(){
    if(data.head == nullptr){
        return true;
    }
    return false;
}

void Stack::flip(){
    Stack stack;
    while(!this->isEmpty()){
        stack.push_back(this->peek()->data);
        this->pop_back();
    }
    *this = stack;
}

bool Stack::contains(char* str){
    Node<City*>* temp = data.head;
    while(temp != nullptr){
        if(strcmp(temp->data->name, str) == 0){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void Stack::print(ofstream & outfile){
    Node<City*>* temp = data.head;
    cout << temp->data->name;
    temp = temp->next;
    while(temp != nullptr){
        cout << " -> " << temp->data->name;
        temp = temp->next;
    }
    cout << ". Time: " << this->getTime() << " Cost: " << this->getPrice() << ".00" << endl;
}

int Stack::getPrice(){
    int sum = 0;
    if(this->isEmpty()){
        return 0;
    }
    Node<City*>* temp = data.head;
    while(temp->next != nullptr){
        Node<Flight>* j = temp->data->data.head;
        while(strcmp(j->data.name, temp->next->data->name) != 0){
            j = j->next;
        }
        sum += j->data.price;
        temp = temp->next;
    }
    return sum;
}

int Stack::getTime(){
    int sum = 0;
    if(this->isEmpty()){
        return 0;
    }
    Node<City*>* temp = data.head;
    while(temp->next != nullptr){
        Node<Flight>* j = temp->data->data.head;
        while(strcmp(j->data.name, temp->next->data->name) != 0){
            j = j->next;
        }
        sum += j->data.time;
        temp = temp->next;
    }
    return sum;
}
