#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "list.h"
#include "city.h"

using namespace std;

char** separate(char* data, char** wordList);
void add(char* departure, char* destination, int price, int length);

List<City> citys;
int main(int argc, char *argv[])
{
    if(argc == 1){

    }
    ifstream infile;
    infile.open("/home/student/Desktop/LinkedList/input");
    int n;
    infile >> n;
    char* t = new char[100];
    infile.getline(t, 100);
    for(int i = 0; i < n; i++){
        infile.getline(t, 100);
        char** wordList = new char*[4];
        char** words = separate(t, wordList);
        add(words[0], words[1], atoi(words[2]), atoi(words[3]));
        delete []wordList;
    }
    Node<City>* temp = citys.head;
    while(temp != nullptr){
        cout << temp->data.name << endl;
        temp = temp->next;
    }

    delete []t;
}

char** separate(char* data, char** wordList){
    char* str = strtok(data, "|");
    int num = 0;
    while(str != NULL){
        wordList[num] = str;
        num++;
        str = strtok(NULL, "|");
    }
    return wordList;
}

void add(char* departure, char* destination, int price, int length){
    Node<City>* temp = citys.head;
    bool dest = true;
    bool depart = true;
    while(temp != nullptr){
        if(temp->data.name == departure){
            Flight flight(destination, price, length);
            temp->data.data.pop_back(flight);
            depart = false;
        }else if(temp->data.name == destination){
            Flight flight(departure, price, length);
            temp->data.data.pop_back(flight);
            dest = false;
        }
        temp = temp->next;
    }
    if(depart){
        City city(departure);
        citys.pop_back(city);
    }
    if(dest){
        City city(destination);
        citys.pop_back(city);
    }
}
