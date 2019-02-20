#ifndef TUPPLE_H
#define TUPPLE_H
#include "dstring.h"

class tupple
{
public:
    tupple();
    tupple(DString str1, DString str2);
    friend bool operator>(tupple x, tupple y);
    friend bool operator<(tupple x, tupple y);
    DString first;
    DString second;
};

#endif // TUPPLE_H
