#ifndef NODE_H
#define NODE_H


template <class T>
class Node
{
public:
    Node();
    Node(T temp);
    Node* next;
    Node* prev;
    T data;
};

#endif // NODE_H
