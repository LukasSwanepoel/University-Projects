#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

template<class T>
Node<T>::Node(T data): data(data),next(NULL)//This right??
{}

template<class T>
T Node<T>::getData() const
{
    return data;
}

template<class T>
bool Node<T>::operator==(T other) const
{
    return data==other;    //------------------do we compare this->data==other? Do we compare this==other directly? If so, do we derefference this?
}                          

#endif /*NODE_CPP*/