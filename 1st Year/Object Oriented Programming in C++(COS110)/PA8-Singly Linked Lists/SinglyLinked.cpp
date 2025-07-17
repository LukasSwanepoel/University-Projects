#ifndef SINGLY_SinglyList_CPP
#define SINGLY_SinglyList_CPP

#include "SinglyLinked.h"
//------------------Do I need to #include Node??

template <class T>
std::ostream &operator<<(std::ostream &os, const SinglyList<T> *sl)
{
    if (sl->head == NULL)
    {
        os << "NULL";
        return os;
    }
    Node<T> *curr = sl->head;
    while (curr != NULL)
    {
        os << curr;
        curr = curr->next;
    }
    return os;
}

template<class T>
SinglyList<T>::SinglyList() : List<T>()
{
//Do I have the right idea?
}

template<class T>
SinglyList<T>::SinglyList(T* arr, int size) : List<T>()
{
    if (arr!=NULL && size>0)
    {
        for (int i=0; i<size; i++)
        {
            this->insert(arr[i],size);
        }
    }
}

template<class T>
SinglyList<T>::~SinglyList()
{
    Node<T>* nodePtr = this->head;
    while (nodePtr)
    {
        this->head = (this->head)->next;//this right??
        delete nodePtr;
        nodePtr = this->head;
    }
    this->head= NULL;
}

template<class T>
Node<T>* SinglyList<T>::insert(T data, int pos)
{
    Node<T>* nodePtr= this->head;
    Node<T>* prevNode = NULL;
    Node<T>* newNode = new Node<T>(data);
    int index=0;

    if (pos<=0)
    {
        newNode->next= this->head;
        this->head = newNode;
    }
    else if (this->head==NULL)
    {
        this->head = newNode;
    }
    else
    {
        while (nodePtr != NULL && index!=pos)
        {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
            index++;
        }
        prevNode->next = newNode;
        newNode->next = nodePtr;
    }
    return newNode;
}

template<class T>
int SinglyList<T>::remove(T data)
{
    Node<T>* nodePtr= this->head;
    Node<T>* prevNode = NULL;
    int index =0;
    if (this->head!= NULL)
    {
        while (nodePtr != NULL && nodePtr->getData() != data)
        {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
            index++;
        }
    }

    if (nodePtr==NULL){return -1;}
    if (nodePtr!=NULL)
    {
        if (nodePtr==this->head)
        {
            this->head = (this->head)->next;
            delete nodePtr;
        }
        else
        {
            prevNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
    return index;
}

template<class T>
Node<T>* SinglyList<T>::operator[](int index) const
{
    Node<T>* nodePtr= this->head;
    int total = this->size();
    int tracker=0;
    //|head|->| |->| |->| |->|NULL|
    //size: 3
    // idx     0    1    2
    //inv idx  -3   -2   -1

    if (index>=total || (total+index)<0){return NULL;}

    if (index>=0)
    {
        while (nodePtr!=NULL && tracker<index)
        {
            nodePtr=nodePtr->next;
            tracker++;
        }
    }
    else
    {
        while (nodePtr!=NULL && tracker<(total+index))
        {
            nodePtr=nodePtr->next;
            tracker++;
        }
    }
    return nodePtr;
}

template<class T>
Node<T>* SinglyList<T>::operator()(T* dataPtr) const
{
    Node<T>* nodePtr = this->head;

    if (dataPtr==NULL||nodePtr==NULL){return NULL;}

    if (this->contains(*dataPtr)==true)
    {
        while (nodePtr!=NULL)
        {
            if (*nodePtr==*dataPtr){return nodePtr;}
            nodePtr = nodePtr->next; 
        }
    }
    return NULL;
}

template<class T>
int SinglyList<T>::getIndexFromFront(T data) const
{
    Node<T>* nodePtr = this->head;
    int scraper=0;

    while (nodePtr!=NULL)
    {
        if (nodePtr->getData()==data){return scraper;}
        nodePtr=nodePtr->next;
        scraper++;
    }
    return -1;
}

template<class T>
int SinglyList<T>::getIndexFromRear(T data) const
{
    //head->| |->| |->NULL
    //idx    0    1    
    //Ridx   1    0  
    //size()=2
    //Ridx= size - idx -1
    int index = getIndexFromFront(data);
    if (index==-1){return index;}
    else
    {
        return this->size()-index-1;
    }
}

template<class T>
List<T>* SinglyList<T>::sort(bool order) const
{
    T* listArr = new T[this->size()];
    Node<T>* nodePtr = this->head;
    int scraper = 0;
    //create array
    while (nodePtr!=NULL)
    {
        listArr[scraper] = nodePtr->getData();
        scraper++;
        nodePtr=  nodePtr->next;
    }
    //sort array
    T dummy;
    for (int i=1; i<this->size(); i++)
    {
        for (int j=0; j<this->size()-1; j++)
        {
            if (order==true && listArr[j]>listArr[j+1])
            {
                dummy = listArr[j];
                listArr[j] = listArr[j+1];
                listArr[j+1] = dummy;
            }

            if (order==false && listArr[j]<listArr[j+1])
            {
                dummy = listArr[j];
                listArr[j] = listArr[j+1];
                listArr[j+1] = dummy;
            }
        }
    }

    SinglyList<T>* newList = new SinglyList<T>(listArr, this->size());//this good?? Have I been calling size() correctly?
    delete [] listArr;
    return newList;
}

template<class T>
Node<T>* SinglyList<T>::findSmallest() const
{
    Node<T>* nodePtr = this->head;
    Node<T>* smallest=this->head;

    while (nodePtr!=NULL)
    {
        if (nodePtr->getData()<smallest->getData())
        {smallest = nodePtr;}
        nodePtr = nodePtr->next;
    }
    return smallest;
}

template<class T>
Node<T>* SinglyList<T>::findBiggest() const
{
    Node<T>* nodePtr = this->head;
    Node<T>* biggest=this->head;

    while (nodePtr!=NULL)
    {
        if (nodePtr->getData()>biggest->getData())
        {biggest = nodePtr;}
        nodePtr = nodePtr->next;
    }
    return biggest;
}

template<class T>
List<T>* SinglyList<T>::clone() const
{
    Node<T>* nodePtr = this->head;
    SinglyList<T>* newList= new SinglyList<T>;

    while (nodePtr!=NULL)
    {
        newList->insert(nodePtr->getData(),this->size());
        nodePtr=nodePtr->next;
    }

    return newList;
}

#endif /*SinglyList_CPP*/
