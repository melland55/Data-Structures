#include "dvector.h"
#include "dstring.h"
#include "tupple.h"
#include <algorithm>
#include <iterator>
#include <array>
#include <utility>

using namespace std;

template <class T>
DVector<T>::DVector(){
    data = new T[1];
    capacity = 1;
    size = 0;
}

//Constructor that creates dvector of size and capacity len
template <class T>
DVector<T>::DVector(unsigned int len){
    size = len;
    capacity = len;
    data = new T[len + 1];
}

//Delete constructor
template <class T>
DVector<T>::~DVector(){
    delete []data;
}

//returns element at index [x] of vector
template <class T>
T& DVector<T>::operator[](unsigned int x) const{
    if(x >= size){
        return data[0];
        //throw exception("Out of bounds");
    }else{
        return data[x];
    }
}

//Inserts elemetn val at index loc in vector
template <class T>
void DVector<T>::insert(int loc, T val){
    size++;
    T temp[size];
    for(int i = 0; i < loc; i++){
        temp[i] = data[i];
    }
    temp[loc] = val;
    for(int i = loc + 1; i < size; i++){
        temp[i] = data[i - 1];
    }
    delete []data;
    data = new T[size];
    for(int i = 0; i < size; i++){
        data[i] = temp[i];
    }
    capacity = size;
}

//removes element at index of  loc
template <class T>
void DVector<T>::remove(unsigned int loc){
    size--;
    T temp[size];
    for(int i = 0; i < loc; i++){
        temp[i] = data[i];
    }
    for(int i = loc; i < size; i++){
        temp[i] = data[i + 1];
    }
    delete []data;
    data = new T[size];
    for(int i = 0; i < size; i++){
        data[i] = temp[i];
    }
    capacity = size;
}

//adds new element to back of vector
template <class T>
void DVector<T>::pushback(T val){
    if(size == capacity){
        resize();
    }
    data[size] = val;
    size++;
}

//removes last element of vector
template <class T>
void DVector<T>::popback(){
    size--;
    capacity = size;
    T temp[size];
    for(int i = 0; i < size; i++){
        temp[i] = data[i];
    }
    delete []data;
    data = new T[size];
    for(int i = 0; i < size; i++){
        data[i] = temp[i];
    }
}


//Resizes the capacity of the vector by double its previous capacity
template <class T>
void DVector<T>::resize(){
    T temp[size];
    for(int i = 0; i < size; i++){
        temp[i] = data[i];
    }
    delete []data;
    data = new T[capacity * 2];
    for(int i = 0; i < size; i++){
        data[i] = temp[i];
    }
    capacity *= 2;
}

//Sorts through the vector
template <class T>
void DVector<T>::sortVec(){
    sort(data, data + size);
}

//returns data
template <class T>
T* DVector<T>::getData() const{
    return data;
}

//returns size of vector
template <class T>
int DVector<T>::getSize() const{
    return size;
}



template class DVector<int>;
template class DVector<char>;
template class DVector<DString>;
template class DVector<tupple>;
