#include "list.h"
#include "node.h"
#include "flight.h"
#include "city.h"

template <class T>
List<T>::List(){
    head = nullptr;
    tail = nullptr;
}

template <class T>
List<T>::List(List<T>& temp){
    head = temp.head;
    tail = temp.tail;
}

template <class T>
void List<T>::pop_back(T temp){
    Node<T>* x = new Node<T>(temp);
    if(head == nullptr){
        head = x;
        tail = x;
    }else if(head == tail){
        head->next = x;
        tail = x;
        tail->prev = head;
    }else{
        x->prev = tail;
        x->next = nullptr;
        tail = x;
    }
}

template class List<int>;
template class List<Flight>;
template class List<City>;

