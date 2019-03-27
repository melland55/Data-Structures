#ifndef LIST_H
#define LIST_H
#include "node.h"

template <class T>
class List
{
public:
    List();
    List<T>(List<T>& temp);
    void pop_back(T temp);
    Node<T>* head;
    Node<T>* tail;
};

#endif // LIST_H
