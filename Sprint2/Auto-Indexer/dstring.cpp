#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include "dvector.h"
#include "dstring.h"

using namespace std;

//Basic String Constructor
DString::DString()
{
    length = 0;
    data = new char[0];
}

//String Constructor with c-string argument
DString::DString(const char* cstring)
{
    length = strlen(cstring);
    data = new char[length + 1];
    strcpy(data, cstring);
}

//String constructor with another DString as the argument
DString::DString(const DString &str)
{
    length = strlen(str.data);
    data = new char[length + 1];
    strcpy(data, str.data);
}

//Returns the length of the DString
int DString::getLength(){
    return length;
}

char* DString::getData(){
    return data;
}

//Function to set data with char array as argument
void DString::setData(char *str){
    strcpy(data, str);
    length = strlen(data);
}

//overloading operator = for comparison between DString and DString
DString & DString::operator=(const DString& str){
    if(this != &str){
        delete []data;
        data = new char[str.length + 1];
        strcpy(data, str.data);
        length = str.length;
    }
    return *this;
}

//function to delete data
DString::~DString(){
    delete []data;
}

//overloading operator = to work with char arrays
DString & DString::operator=(char* c){
        delete []data;
        data = new char[strlen(c) + 1];
        strcpy(data, c);
        length = strlen(c);
        return *this;
}

bool operator>(DString x, DString y){
    int z;
    z = strcmp(x.getData(), y.getData());
    if(z <= 0){
        return false;
    }else{
        return true;
    }
}

bool operator<(DString x, DString y){
    int z;
    z = strcmp(x.getData(), y.getData());
    if(z < 0){
        return true;
    }else{
        return false;
    }
}

ostream &operator<<(ostream &out, const DString &str){
    return out<<str.data;
}

istream &operator>>(istream &in, DString &str){
    char* temp;
    in >> temp;
    str = temp;
    return in;
}

bool operator==(const DString &str1, const DString &str2){
    if(strcmp(str1.data, str2.data) == 0){
        return true;
    }else{
        return false;
    }
}

bool operator==(const DString &str1, const char* c){
    if(strcmp(str1.data, c) == 0){
        return true;
    }else{
        return false;
    }
}

DString &DString::operator+=(DString str){
    char* temp = new char[length + str.getLength()];
    for(int i = 0; i <= length; i++){
        temp[i] = data[i];
    }
    for(int i = length; i <= str.length + length; i++){
        temp[i] = str.data[i - length];
    }
    delete []data;
    data = new char[strlen(temp)];
    strcpy(data, temp);
    length = strlen(temp);
    return *this;
}

DString &DString::operator+(DString str){
    char* temp = new char[length + str.getLength()];
    for(int i = 0; i <= length; i++){
        temp[i] = data[i];
    }
    for(int i = length; i <= str.length + length; i++){
        temp[i] = str.data[i - length];
    }
    delete []data;
    data = new char[strlen(temp)];
    strcpy(data, temp);
    length = strlen(temp);
    return *this;
}

//seperates a DString by spaces into a vector of smaller DStrings
vector<DString> DString::separate(){
    char *str = strtok(data, " ");
        vector<DString> wordList;
        while(str != NULL){
            DString *word = new DString(str);
            wordList.push_back(*word);
            str = strtok(NULL, " ");
        }
    return wordList;
}

//Makes DString all lower case
void DString::lowercase(){
    for(int i = 0; i <= length; i++){
        data[i] = tolower(data[i]);
    }
}

//Removes double quotes from a DString
void DString::removeQuotes(){
    int count = 0;
    for(int i = 0; i <= length; i++){
        if(data[i] == '\"'){
            count++;
        }
    }
    char* temp = new char[length - count];
    int sum = 0;
    for(int i = 0; i <= length; i++){
        if(data[i] != '\"'){
            temp[sum] = data[i];
            sum++;
        }
    }
    delete []data;
    data = new char[sum];
    for(int i = 0; i <= sum; i++){
        data[i] = temp[i];
    }
    length = sum - count;
}

//Removes not alpha characters from a DString
void DString::removeNum(){
    int sum = 0;
    for(int i = 0; i <= length; i++){
        if(isupper(data[i])){
            data[i] = tolower(data[i]);
        }
        if(islower(data[i])){
            sum++;
        }
    }

    char* temp = new char[sum];
    sum = 0;
    for(int i = 0; i <= length; i++){
        if(islower(data[i])){
            temp[sum] = data[i];
            sum++;
        }
    }

    delete []data;
    data = new char[strlen(temp)];
    strcpy(data, temp);
    for(unsigned int i = 0; i <= strlen(data); i++){
    }
    length = strlen(temp);
}

//Parses DString by commas into a vector of DStrings
vector<DString> DString::parseCSV(){
    char *str = strtok(data, ",");
        vector<DString> wordList;
        while(str != NULL){
            DString *word = new DString(str);
            wordList.push_back(*word);
            str = strtok(NULL, ",");
        }
    return wordList;
}

DVector<DString> DString::parseIndex(){
    DVector<DString> wordList;
    char* temp = new char[length + 1];
    strcpy(temp, data);
    char *str = strtok(temp, " ");
    while(str != NULL){
        DString *word = new DString(str);
        wordList.pushback(*word);
        str = strtok(NULL, " ");
    }
    int sum = 0;
    for(int i = 0; i < wordList.getSize(); i++){
        if(wordList[i].getData()[0] == '['){
            wordList[i] += " ";
            int j = i + 1;
            while(wordList[j].getData()[wordList[j].getLength() - 1] != ']'){
                wordList[i] += wordList[j];
                wordList.remove(j);
                wordList[i] += " ";
            }
            wordList[i] += wordList[j];
            wordList.remove(j);
        }
    }
    length = strlen(data);
    return wordList;
}

void DString::removeBrackets(){
    if(data[0] == '[' || data[0] == '<'){
        length = strlen(data);
        char temp[length - 2];
        for(int i = 1; i < length - 1; i++){
            temp[i - 1] = data[i];
        }
        temp[length - 2] = NULL;
        delete []data;
        data = new char[strlen(temp)];
        length -= 2;
        strcpy(data, temp);
    }
}





