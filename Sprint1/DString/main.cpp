#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include "dstring.h"

using namespace std;

void addWord(DString str, int score);

vector<DString> words;
vector<int> scores;
vector<int> counts;
int sum = 0;

int main()
{
    ifstream intweet;
    ifstream inid;
    intweet.open("/home/student/Desktop/CSE2341-19S-Andrew-Melland/Sprint1/DString/dev-train-data.csv");
    inid.open("/home/student/Desktop/CSE2341-19S-Andrew-Melland/Sprint1/DString/dev-train-target.csv");
    if(intweet.fail()){
        cout << "Fail" << endl;
    }
    vector<DString> csv;
    vector<DString> tweet;
    char *temp = new char[300];
    intweet.getline(temp, 300);
    for(int i = 0; i <= 10; i++){
        csv.clear();
        tweet.clear();
        intweet.getline(temp, 300);
        DString x = temp;
        csv = x.parseCSV();
        tweet = csv[3].separate();
        for(unsigned int j = 0; j < tweet.size(); j++){
            tweet[j].removeNum();
            addWord(tweet[j], -1);
        }
    }
}

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
        cout << words[sum] <<endl;
        sum++;
        scores.push_back(score);
        counts.push_back(1);
    }
}
