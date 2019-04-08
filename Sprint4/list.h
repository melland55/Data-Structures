#ifndef LIST_H
#define LIST_H

template <class P>
struct Node
{
    Node* next;
    Node* prev;
    P data;
};

template <class T>
class List
{

public:
    List();
    ~List();
    List(const List<T>& list);
    List<T>& operator=(const List<T>& list);
    void push_back(T temp);
    Node<T>* head;
    Node<T>* tail;
};


template <class T>
List<T>::List(){
    head = nullptr;
    tail = nullptr;
}

template <class T>
List<T>::~List(){
    Node<T>* temp = head;
    while(temp != nullptr){
        head = temp->next;
        delete temp;
        temp = head;
    }
}

template <class T>
List<T>::List(const List<T>& list){
    head = nullptr;
    tail = nullptr;
    Node<T>* temp = list.head;
    while(temp != nullptr){
        this->push_back(temp->data);
        temp = temp->next;
    }
}

template <class T>
List<T>& List<T>::operator=(const List<T>& list){
    Node<T>* temp = list.head;
    Node<T>* t = head;
    while(t != nullptr){
        head = t->next;
        delete t;
        t = head;
    }
    while(temp != nullptr){
        this->push_back(temp->data);
        temp = temp->next;
    }
    return *this;
}

template <class T>
void List<T>::push_back(T temp){
    if(head == nullptr){
        head = new Node<T>();
        tail = head;
        head->data = temp;
        return;
    }

    tail->next = new Node<T>();
    tail->next->prev = tail;
    tail = tail->next;
    tail->data = temp;
}



#endif // LIST_H
