#ifndef DSTRING_H
#define DSTRING_H
#include <iostream>
#include <vector>
using namespace std;

class DString
{
public:
    DString();
    DString(const char*);
    DString(const DString&);
    int getLength();
    DString &operator=(DString&);
    DString &operator=(char*);
    friend ostream &operator<<(ostream &out, const DString &str);
    friend istream &operator<<(istream &in, const DString &str);
    friend bool operator==(const DString &str1, const DString &str2);
    friend bool operator==(const DString &str1, const char* c);
    vector<DString> separate();
private:
    char* data;
    int length;
};


#endif // DSTRING_H
