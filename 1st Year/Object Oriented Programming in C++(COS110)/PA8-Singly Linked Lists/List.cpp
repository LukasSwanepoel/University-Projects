#ifndef LIST_CPP
#define LIST_CPP

#include "List.h"

template<class T>
List<T>::List()
{
    head= NULL;
}

template<class T>
List<T>::~List(){}

template<class T>
int List<T>::size() const
{
    Node<T>* nodePtr = head;
    int output=0;

    while (nodePtr!=NULL)
    {
        nodePtr= nodePtr->next;
        output++;
    }

    return output;
}

template<class T>
bool List<T>::contains(T data) const
{
    Node<T>* nodePtr = head;

    while (nodePtr!=NULL)
    {
        if (*nodePtr==data)//-----------derefference correct???
        {return true;}
        nodePtr=nodePtr->next;
    }
    return false;
}

#endif /*LIST_CPP*/