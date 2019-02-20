#include "tupple.h"

tupple::tupple()
{
    first = "";
    second = "";
}

tupple::tupple(DString str1, DString str2){
    first = str1;
    second = str2;
}

bool operator>(tupple x, tupple y){
    if(x.first > y.first){
        return true;
    }else if(x.first < y.first){
        return false;
    }else{
        if(atoi(x.second.getData()) > atoi(y.second.getData())){
            return true;
        }else{
            return false;
        }
    }
}

bool operator<(tupple x, tupple y){
    if(x.first < y.first){
        return true;
    }else if(x.first > y.first){
        return false;
    }else{
        if(atoi(x.second.getData()) < atoi(y.second.getData())){
            return true;
        }else{
            return false;
        }
    }
}



