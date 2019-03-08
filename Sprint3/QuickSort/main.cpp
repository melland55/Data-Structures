#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

//Declaring global functions an variables
void quicksort(char arr[][31], int beg, int end);
int getSize(char arr[]);
int n, x;


int main(int argc, char *argv[]){
    //Opens the input and output files passed in by main arguments
    ifstream infile;
    infile.open(argv[1]);
    ofstream outfile;
    outfile.open(argv[2]);

    //Get number of words(n) and number of words to sort(x)
    infile >> n >> x;

    //Declaring array with size of max size of possible word
    char arr[n][31] = {"0"};
    //Array to hold newly parced words from file
    char temp[31];
    //Puts the file pointer on the first word
    infile.getline(temp, 31);
    //Loops through every word in file and adds it to array of char* (arr)
    for(int i = 0; i < n; i++){
        infile.getline(temp, 31);
        strcpy(arr[i], temp);
    }

    //Calls the function quicksort that sorts the array from index 0 to index of n
    quicksort(arr, 0, n);
    //Outputs resulting sorted arr to output file
    for(int i = 0; i < x; i++){
        outfile << arr[i] << endl;
    }
}

void quicksort(char arr[][31], int beg, int end)
{
    if(beg < end){
        //Chooses pivot to sort arr
        char* pivot = arr[end];
        int temp = (beg - 1);
        //Loops through arr putting all values smaller than pivot to the left of it
        for (int i = beg; i <= end - 1; i++){
            //Adds value arr[i] to the left of pivot if it is either smaller or not in alphabetical order if same length
            if(getSize(arr[i]) < getSize(pivot) || (getSize(arr[i]) == getSize(pivot) && strcmp(arr[i], pivot) <= 0)){
                temp++;
                char z[31];
                //Swaps the value of arr[temp] and arr[i]
                copy(arr[temp], arr[temp] + 31, z);
                copy(arr[i], arr[i] + 31, arr[temp]);
                copy(z, z + 31, arr[i]);
            }
        }
        char z[31];
        //Inserts pivot between all values lower and higher than it
        copy(arr[temp + 1], arr[temp + 1] + 31, z);
        copy(arr[end], arr[end] + 31, arr[temp + 1]);
        copy(z, z + 31, arr[end]);
        //Recursively calls quicksort for either side of pivot
        quicksort(arr, beg, temp);
        quicksort(arr, temp + 2, end);
    }
}

//Returns number of elements in arr
int getSize(char arr[]){
    int sum = 0;
    for(int i = 0; i < 31; i++){
        if(arr[i] == '\0'){
            return sum;
        }else{
            sum++;
        }
    }
    return sum;
}

