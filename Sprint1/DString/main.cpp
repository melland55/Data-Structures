#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include "dstring.h"


using namespace std;

void addWord(DString str, int score);
int getIndex(DString str);

//Initializ vectors used to store words that appear in test and their usage
vector<DString> words;
vector<int> scores;
vector<int> counts;
int sum = 0;

int runCatchTests(int argc, char* const argv[])
{
    //This line of code causes the Catch library to
    //run the tests in the project.
    return Catch::Session().run();
}

int main(int argc, char* argv[])
{
    bool TEST = false;
    if(argc == 1){
        TEST = true;
    }
    if (TEST)
        {
            return runCatchTests(argc, argv);
        }

    //opening all files required through command line arguments
    ofstream outFile;
    ifstream intesttweet;
    ifstream intweet;
    ifstream inid;
    intweet.open(argv[1]);
    inid.open(argv[2]);
    intesttweet.open(argv[3]);
    outFile.open(argv[4]);

    if(intweet.fail()){
        cout << "Fail" << endl;
    }
    vector<DString> csv;
    vector<DString> tweet;
    char *temp = new char[2000];
    intweet.getline(temp, 300);
    char *point = new char[100];
    inid.getline(point, 300);
    int num;
    //loops through test tweets to find correlaltions between words and their sentiment
    for(unsigned int i = 0; i <= 10000; i++){
        inid.getline(point, 300);
        DString y = point;
        csv = y.parseCSV();
        if(csv[1] == "0"){
            num = -1;
        }else{
            num = 1;
        }
        csv.clear();
        tweet.clear();
        intweet.getline(temp, 2000);
        DString x = temp;
        csv = x.parseCSV();
        tweet = csv[3].separate();
        for(unsigned int j = 0; j < tweet.size(); j++){
            addWord(tweet[j], num);
        }
    }



    intesttweet.getline(temp, 2000);
    //cycles through file to find sentiment
    while(intesttweet.getline(point, 300)){
        int score = 0;
        int index;
        csv.clear();
        tweet.clear();
        intesttweet.getline(temp, 2000);
        DString x = temp;
        csv = x.parseCSV();
        tweet = csv[3].separate();
        for(unsigned int j = 0; j < tweet.size(); j++){
            index = getIndex(tweet[j]);
            if(index != -1){
                score += scores[j];
            }
        }
        outFile << '\"' << csv[1] << '\"' << ',' << '\"';
        if(score >= 0){
            outFile << "4" << '\"' << endl;
        }else{
            outFile << "0" << '\"' << endl;
        }
    }
}

//Adds a word to the vector words, if it already exsists it adds its sentiment to scores
void addWord(DString str, int score){
    bool dec = true;
    for(unsigned int i = 0; i < words.size(); i++){
        if(words[i] == str){
            scores[i] += score;
            counts[i]++;
            dec = false;
        }
    }
    if(dec){
        words.push_back(str);
        scores.push_back(score);
        counts.push_back(1);
    }
}
//returns index of word in the vector Words
int getIndex(DString str){
    for(int i = 0; i < words.size(); i++){
        if(str == words[i]){
            return i;
        }
    }
    return -1;
}
