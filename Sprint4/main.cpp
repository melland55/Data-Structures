#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include "list.h"
#include "adjacencylist.h"


using namespace std;

char** separate(char* data, char** wordList);

int main(int argc, char *argv[])
{
    if(argc == 1){
        return Catch::Session().run();
    }


    ifstream infile;
    infile.open(argv[1]);
    ifstream inflights;
    inflights.open(argv[2]);
    ofstream outfile;
    outfile.open(argv[3]);
    int n;
    infile >> n;
    AdjacencyList list;
    char* t = new char[100];
    infile.getline(t, 100);
    for(int i = 0; i < n; i++){
        infile.getline(t, 100);
        char** wordList = new char*[4];
        char** words = separate(t, wordList);
        list.add(words[0], words[1], atoi(words[2]), atoi(words[3]));
        delete []wordList;
    }
    inflights >> n;
    inflights.getline(t, 100);
    for(int i = 0; i < n; i++){
        inflights.getline(t, 100);
        char** wordList = new char*[4];
        char** words = separate(t, wordList);
        outfile << "Fight " << (i + 1) << ": " << words[0] << ", " << words[1];
        List<Stack> flights = list.getFlights(words[0], words[1]);
        if(strcmp(words[2], "T") == 0){
            outfile << " (Time)" << endl;
            Node<Stack>* cur = flights.head;
            Stack* max;
            Stack* med;
            Stack* min;
            int sum = 1;
            while(cur != nullptr){
                if(sum == 1){
                    min = &cur->data;
                }else if(sum == 2){
                    if(min->getTime() < cur->data.getTime()){
                        med = &cur->data;
                    }else{
                        med = min;
                        min = &cur->data;
                    }
                }else if(sum == 3){
                    if(min->getTime() < cur->data.getTime()){
                        if(med->getTime() < cur->data.getTime()){
                            max = &cur->data;
                        }else{
                            max = med;
                            med = &cur->data;
                        }
                    }else{
                        max = med;
                        med = min;
                        min = &cur->data;
                    }
                }else{
                    if(cur->data.getTime() < min->getTime()){
                        max = med;
                        med = min;
                        min = &cur->data;
                    }else if(cur->data.getTime() < med->getTime()){
                        max = med;
                        med = &cur->data;
                    }else if(cur->data.getTime() < max->getTime()){
                        max = &cur->data;
                    }
                }
                sum++;
                cur = cur->next;
            }
            if(min != nullptr){
                outfile << "Path 1: ";
                min->flip();
                Node<City*>* temp = min->peek();
                outfile << temp->data->name;
                temp = temp->next;
                while(temp != nullptr){
                    outfile << " -> " << temp->data->name;
                    temp = temp->next;
                }
                outfile << ". Time: " << min->getTime() << " Cost: " << min->getPrice() << ".00" << endl;
            }
            if(med != nullptr){
                outfile << "Path 2: ";
                med->flip();
                Node<City*>* temp = med->peek();
                outfile << temp->data->name;
                temp = temp->next;
                while(temp != nullptr){
                    outfile << " -> " << temp->data->name;
                    temp = temp->next;
                }
                outfile << ". Time: " << med->getTime() << " Cost: " << med->getPrice() << ".00" << endl;
            }
            if(max != nullptr){
                outfile << "Path 3: ";
                max->flip();
                Node<City*>* temp = max->peek();
                outfile << temp->data->name;
                temp = temp->next;
                while(temp != nullptr){
                    outfile << " -> " << temp->data->name;
                    temp = temp->next;
                }
                outfile << ". Time: " << max->getTime() << " Cost: " << max->getPrice() << ".00" << endl;
            }
        }else{
            outfile << " (Cost)" << endl;
            Node<Stack>* cur = flights.head;
            Stack* max;
            Stack* med;
            Stack* min;
            int sum = 1;
            while(cur != nullptr){
                if(sum == 1){
                    min = &cur->data;
                }else if(sum == 2){
                    if(min->getPrice() < cur->data.getPrice()){
                        med = &cur->data;
                    }else{
                        med = min;
                        min = &cur->data;
                    }
                }else if(sum == 3){
                    if(min->getPrice() < cur->data.getPrice()){
                        if(med->getPrice() < cur->data.getPrice()){
                            max = &cur->data;
                        }else{
                            max = med;
                            med = &cur->data;
                        }
                    }else{
                        max = med;
                        med = min;
                        min = &cur->data;
                    }
                }else{
                    if(cur->data.getPrice() < min->getPrice()){
                        max = med;
                        med = min;
                        min = &cur->data;
                    }else if(cur->data.getPrice() < med->getPrice()){
                        max = med;
                        med = &cur->data;
                    }else if(cur->data.getPrice() < max->getPrice()){
                        max = &cur->data;
                    }
                }
                sum++;
                cur = cur->next;
            }
            if(min != nullptr){
                outfile << "Path 1: ";
                min->flip();
                Node<City*>* temp = min->peek();
                outfile << temp->data->name;
                temp = temp->next;
                while(temp != nullptr){
                    outfile << " -> " << temp->data->name;
                    temp = temp->next;
                }
                outfile << ". Time: " << min->getTime() << " Cost: " << min->getPrice() << ".00" << endl;
            }
            if(med != nullptr){
                outfile << "Path 2: ";
                med->flip();
                Node<City*>* temp = med->peek();
                outfile << temp->data->name;
                temp = temp->next;
                while(temp != nullptr){
                    outfile << " -> " << temp->data->name;
                    temp = temp->next;
                }
                outfile << ". Time: " << med->getTime() << " Cost: " << med->getPrice() << ".00" << endl;
            }
            if(max != nullptr){
                outfile << "Path 3: ";
                max->flip();
                Node<City*>* temp = max->peek();
                outfile << temp->data->name;
                temp = temp->next;
                while(temp != nullptr){
                    outfile << " -> " << temp->data->name;
                    temp = temp->next;
                }
                outfile << ". Time: " << max->getTime() << " Cost: " << max->getPrice() << ".00" << endl;
            }
        }
        outfile << endl;
        delete []wordList;
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
