#include "LinkedList.h"
#include <iostream>


using namespace std;

template <typename T>
LinkedList<T>::LinkedList()
{
    this->data = nullptr;
    this->next = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(T x)
{
    this->data = x;
    this->next = nullptr;
}

template <typename T>
LinkedList<T>* LinkedList<T>::Search(LinkedList<T> *l, T x)
{
    if (l == nullptr)
        return nullptr;
    if (l->data == x)
        return l;
    else
        return(Search(l->next, x));
}

template <typename T>
void LinkedList<T>::Insert(LinkedList<T> **l, T x)
{
    LinkedList<T>* current = new LinkedList(x);
    current->next = *l
    *l = current;
}

template <typename T>
LinkedList<T>* LinkedList<T>::PredecessorList(LinkedList<T> *l, T x)
{
    if (l == nullptr || l->next == nullptr)
    {
        cout << "Error: predecessor sough on a null list.\n";
        return nullptr;
    }

    if (l->next->item == x)
        return l;
    else
        return(PredecessorList(l->next, x));
}

template <typename T>
void LinkedList<T>::Delete_List(LinkedList<T> **l, T x)
{
    LinkedList<T>* current = Search(*l, x);
    if (current != nullptr)
    {
        LinkedList<T>* prev = PredecessorList(*l,x);
        if (prev == nullptr)
            *l = current->next;
        else
            prev->next = current->next;
        delete current;
    }
}

template <typename T>
void LinkedList<T>::PrintList(LinkedList<T> *l)
{
    if (l = nullptr)
    {
        cout << endl;
        return;
    }
    cout << l->data << " -> ";
    PrintList(l->next);
}