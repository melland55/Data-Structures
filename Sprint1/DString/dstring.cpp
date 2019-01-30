#include "dstring.h"
#include <cstring>
#include <iostream>
#include <vector>

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
    //length = strlen(str.length);
    data = new char[length + 1];
    strcpy(data, str.data);
}

//Returns the length of the DString
int DString::getLength(){
    return length;
}

DString & DString::operator=(DString& str){
    delete []data;
    data = new char[str.length + 1];
    memcpy(data, str.data, str.length + 1);
    return *this;
}

DString & DString::operator=(char* c){
    delete []data;
    data = new char[strlen(c)];
    memcpy(data, c, strlen(c) + 1);
    return *this;
}

ostream &operator<<(ostream &out, const DString &str){
    return out<<str.data;
}

istream &operator<<(istream &in, const DString &str){
    return in>>str.data;
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








