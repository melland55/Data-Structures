#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "dvector.h"
#include "dstring.h"
#include "tupple.h"
#include <iostream>
#include <array>
#include <utility>
#include <fstream>
#include <ctype.h>
#include <stdio.h>


using namespace std;

int runCatchTests(int argc, char* const argv[])
{
    //This line of code causes the Catch library to
    //run the tests in the project.
    return Catch::Session().run();
}

int main(int argc, char* argv[])
{
    //When no command line arguments are passed run catch test
    bool TEST = false;
    if(argc == 1){
        TEST = true;
    }
    if(TEST){
            return runCatchTests(argc, argv);
    }

    ofstream outfile;
    ifstream infile;
    infile.open(argv[1]);
    outfile.open(argv[2]);


    DVector<tupple> index;

    DString num;
    char* temp = new char[80];
    DString x;

    //parse through data adding each word with its page to vector Index
    while(infile.getline(temp, 80)){
        //if the line is page number
        if(temp[0] == '<'){
            x = temp;
            x.removeBrackets();
            num = x;
        //if the line is words to be added
        }else{
            x = temp;
            //seperates line into a vector of words
            DVector<DString> y = x.parseIndex();
            for(int i = 0; i < y.getSize(); i++){
                //creates pair tupple to store both the word and page number
                tupple z;
                y[i].removeBrackets();
                y[i].lowercase();
                z.first = y[i];
                z.second = num;
                index.pushback(z);
            }
        }
    }

    //Sorts index by words in alphabetical order and also page number for similar words
    index.sortVec();

    //Loops through index adding multiple occurences of the same word to one tupple with all page numbers
    for(int i = 0; i + 1 < index.getSize(); i++){
        if(index[i].first == index[i + 1].first){
            if(!(index[i].second == index[i + 1].second)){
                    index[i].second += ", ";
                    index[i].second += index[i + 1].second;

            }

            //removes any duplicate entries
            index.remove(i + 1);
            i--;
        }
    }

    //Loops through index adding [char] to the fisrt appearance of each first letter
    char last = 'z';
    for(int i = 0; i < index.getSize(); i++){
        if(index[i].first.getData()[0] != last){
            last = index[i].first.getData()[0];
            if(isdigit(last)){
                outfile << "[" << last << "]" << endl;
            }else{
                outfile << "[" << (char)toupper(last) << "]" << endl;
            }
        }
        outfile << index[i].first << ": " << index[i].second << endl;
    }

    return 0;
}
