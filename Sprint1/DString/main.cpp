#include <iostream>
#include "dstring.h"

using namespace std;

int main()
{
    char y[] = "string";
    DString x;
    x = y;
    cout << x;
}
