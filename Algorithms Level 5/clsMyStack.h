#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
#include "clsMyQueue.h"

template <class T>
class clsMyStack : public clsMyQueue<T>
{

public:
    void push(T value)
    {
       this->_List.InsertAtBeginning(value);
    }
  
   
    T Top()
    {
        return this->front();
    }
    T Bottom()
    {
        return this->back();
    }
  
  
   
};