#include "dvector.h"
#include "dstring.h"
#include <iostream>
#include <array>
#include <utility>
#include <fstream>
#include <ctype.h>
#include <stdio.h>


using namespace std;

int main(int argc, char *argv[])
{

    bool TEST = false;
    if(argc == 1){
        TEST = true;
    }
    if (TEST)
        {
            //return runCatchTests(argc, argv);
        }

    ofstream outfile;
    ifstream infile;
    infile.open(argv[1]);
    outfile.open(argv[2]);


    /*ifstream infile;
    infile.open("/home/student/Desktop/CSE2341-19S-Andrew-Melland/Sprint2/Auto-Indexer/test");
    if(!infile.is_open()){
        cout << "fail" << endl;
    }*/

    DVector<pair<DString, DString>> index;

    DString num;
    char* temp = new char[80];
    DString x;
    while(infile.getline(temp, 80)){
        if(temp[0] == '<'){
            x = temp;
            x.removeBrackets();
            num = x;
        }else{
            x = temp;
            DVector<DString> y = x.parseIndex();
            for(int i = 0; i < y.getSize(); i++){
                pair<DString, DString> z;
                y[i].removeBrackets();
                y[i].lowercase();
                z.first = y[i];
                z.second = num;
                index.pushback(z);
            }
        }
    }
    index.sortVec();

    for(int i = 0; i + 1 < index.getSize(); i++){
        if(index[i].first == index[i + 1].first){
            index[i].second += ", ";
            index[i].second += index[i + 1].second;
            index.remove(i + 1);
            i--;
        }
    }

    char last = 'z';
    for(int i = 0; i < index.getSize(); i++){
        if(index[i].first.getData()[0] != last){
            last = index[i].first.getData()[0];
            if(isdigit(last)){
                outfile << "<" << last << ">" << endl;
            }else{
                outfile << "<" << (char)toupper(last) << ">" << endl;
            }
        }
        outfile << index[i].first << ": " << index[i].second << endl;
    }

    return 0;
}
