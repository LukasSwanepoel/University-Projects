#ifndef DICTIONARY_CPP
#define DICTIONARY_CPP
#include <cstddef>
#include "Tuple.h"
#include "Tuple.cpp"
#include "Dictionary.h"

template <class T, class E>
Dictionary<T,E>::Dictionary()
{
    currSize=0;
    keys=NULL;
    values=NULL;
}

template <class T, class E>
Dictionary<T,E>::~Dictionary()
{
    if ((keys!=NULL)&&(values!=NULL))
    {
    delete [] values;
    delete [] keys;
    }
}

template <class T, class E>
void Dictionary<T,E>::set(T key, E value)
{
    bool exists = false;
    for (int i=0; i<currSize; i++)
    {
        if (keys[i]== key)
        {
            values[i] = value;
            exists = true;
        }
    }

    if (exists==false)
    {
        T* newKeys = new T[currSize+1];
        E* newValues = new E[currSize+1];
        for (int i=0; i<currSize; i++)
        {
            newKeys[i]= keys[i];
            newValues[i]= values[i];
        }
        newKeys[currSize] = key;
        newValues[currSize] = value;

        delete [] keys;
        delete [] values;

        keys= newKeys;
        values= newValues;
        currSize++;
    }
}

template <class T, class E>
E Dictionary<T,E>::at(T key)
{
    for (int i=0; i<currSize; i++)
    {
        if (keys[i]==key)
        {
            return values[i];
        }
    }

   return E();
}

template <class T, class E>
void Dictionary<T,E>::removeAt(T key)
{
    bool exists=false;
    int scraper=0;
    for (int i=0; i<currSize;i++)
    {
        if (keys[i]==key)
        {exists=true;}
    }

    if ((exists==true)&&(currSize-1>0))
    {   
        T* newKeys = new T[currSize-1];
        E* newValues = new E[currSize-1];
        for (int i=0; i<currSize;i++)
        {
            if (keys[i]!=key)
            {
                newKeys[scraper] = keys[i];
                newValues[scraper] =values[i];
                scraper++;
            }
        }
        delete [] keys;
        delete [] values;

        keys= newKeys;
        values= newValues;
        currSize--;
    }
    else if ((exists==true)&&(currSize-1==0))
    {
        delete [] keys;
        delete [] values;
        keys=NULL;
        values=NULL;
        currSize=0;
    }
}

template<class T, class E>
void Dictionary<T,E>::remove(E value)
{
    int instanceCount=0, scraper=0;
    for (int i=0; i<currSize; i++)
    {
        if (values[i]==value)
        {
            instanceCount++;
        }
    }

    if (currSize-instanceCount==0)
    {
        delete [] values;
        delete [] keys;
        values = NULL;
        keys = NULL;
        currSize=0;
    }
    else
    {
        T* newKeys = new T[currSize-instanceCount];
        E* newValues = new E[currSize-instanceCount];
        for (int i=0; i<currSize;i++)
        {
            if (values[i]!=value)
            {
                newKeys[scraper] = keys[i];
                newValues[scraper] =values[i];
                scraper++;
            }
        }
        delete [] keys;
        delete [] values;

        keys= newKeys;
        values= newValues;
        currSize=currSize-instanceCount;
    }
}

template<class T, class E>
bool Dictionary<T,E>::exists(T key)
{
    for (int i=0;i<currSize;i++)
    {
        if (keys[i]==key)
        {
            return true;
        }
    }
    return false;
}

template<class T, class E>
Tuple<int,T*> Dictionary<T,E>::keysWithValue(E value)
{
    int instanceCount=0, scraper=0;
    T* keyChain;

    for (int i=0; i<currSize; i++)
    {
        if (values[i]==value)
        {
            instanceCount++;
        }
    }

    if (instanceCount==0)
    {
        keyChain= new T[0];
        Tuple<int,T*> output(0,keyChain);
        return output;
    }
    else
    {
        keyChain= new T[instanceCount];

        for (int i=0; i<currSize; i++)
        {
            if (values[i]==value)
            {
                keyChain[scraper] = keys[i];
                scraper++;
            }
        }

        Tuple<int,T*> output(instanceCount, keyChain);
        return output;
    }
    
}

template<class T, class E>
void Dictionary<T,E>::swap(T firstKey, T secondKey)
{
    E dummy;

    if ((exists(firstKey)==true)&&(exists(secondKey)==true))
    {
        dummy = at(firstKey);
        set(firstKey,at(secondKey));
        set(secondKey,dummy);
    }
}

template<class T, class E>
void Dictionary<T,E>::clear()
{
    if ((keys!=NULL)&&(values!=NULL))
    {
        delete [] keys;
        delete [] values;
        keys=NULL;
        values= NULL;
    }
   currSize=0; 
}

template<class T, class E>
T* Dictionary<T,E>::getKeys()
{
    return keys;
}

template<class T, class E>
int Dictionary<T,E>::size()
{
    return currSize;
}

;
#endif