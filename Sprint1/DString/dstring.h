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
    ~DString();
    DString &operator=(char*);
    friend ostream &operator<<(ostream &out, const DString &str);
    friend istream &operator>>(istream &in, const DString &str);
    friend bool operator==(const DString &str1, const DString &str2);
    friend bool operator==(const DString &str1, const char* c);
    DString &operator+(DString str);
    DString &operator+=(DString str);
    vector<DString> separate();
    void lowercase();
    void removeQuotes();
    void removeNum();
private:
    char* data;
    int length;
};


#endif // DSTRING_H
