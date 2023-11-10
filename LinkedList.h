#ifndef LinkedList_H
#define LinkedList_H

template <typename T>
class LinkedList 
{
    public:
        T data;
        LinkedList* next;
        LinkedList();
        LinkedList(T x);
        LinkedList* Search(LinkedList *l, T x);
        void Insert(LinkedList **l, T x);
        LinkedList* PredecessorList(LinkedList *l, T x);
        void Delete_List(LinkedList **l, T x);
        void PrintList(LinkedList *l);
};
#endif
