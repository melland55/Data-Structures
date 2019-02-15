#include "dvector.h"
#include "dstring.h"
#include <iostream>
#include <array>
#include <utility>


using namespace std;

int main(int argc, char *argv[])
{

    DVector<pair<DString, int>> x;
    pair<DString, int> y;
    y.first = "bb";
    y.second = 1;
    pair<DString, int> z;
    z.first = "aa";
    z.second = 12;
    x.pushback(y);
    x.pushback(z);
    x.sortVec();
    DVector<pair<DString, int>> k = x;
    for(int i = 0; i < x.getSize(); i++){
        cout << k[i].first << " " << k[i].second << endl;
    }
    return 0;
}
