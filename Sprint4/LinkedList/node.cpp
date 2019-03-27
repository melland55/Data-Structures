#include "node.h"
#include "flight.h"
#include "city.h"

template <class T>
Node<T>::Node(){
    next = nullptr;
    prev =  nullptr;
}

template <class T>
Node<T>::Node(T temp){
    next = nullptr;
    prev =  nullptr;
    data = temp;
}

template class Node<int>;
template class Node<Flight>;
template class Node<City>;
