#ifndef DSTRING_H
#define DSTRING_H
#include <iostream>
using namespace std;

class DString
{
public:
    DString();
    DString(char*);
    DString(DString&);
    int getLength();
    DString &operator=(DString&);
    DString &operator=(char*);
    friend ostream &operator<<(ostream &out, const DString &str);
    friend istream &operator<<(istream &in, const DString &str);
private:
    char* data;
    int length;
};


#endif // DSTRING_H
