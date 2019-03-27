#ifndef DSTRING_H
#define DSTRING_H
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include "dvector.h"
#include "dstring.h"

using namespace std;

class DString
{
public:
    DString();
    DString(const char*);
    DString(const DString&);
    int getLength();
    char* getData();
    void setData(char *str);
    DString &operator=(const DString&);
    ~DString();
    DString &operator=(char*);
    friend bool operator>(DString x, DString y);
    friend bool operator<(DString x, DString y);
    friend ostream &operator<<(ostream &out, const DString &str);
    friend istream &operator>>(istream &in, DString &str);
    friend bool operator==(const DString &str1, const DString &str2);
    friend bool operator==(const DString &str1, const char* c);
    DString &operator+(DString str);
    DString &operator+=(DString str);
    vector<DString> separate();
    void lowercase();
    void removeQuotes();
    void removeNum();
    void inFile(ifstream& in);
    vector<DString> parseCSV();
    void removeBrackets();
    DVector<DString> parseIndex();
private:
    int length;
    char* data;
};


#endif // DSTRING_H
