#pragma once
#include <iostream>
#include "clsMyQueueArr.h"

template <class T>
class clsMyStackArr : public clsMyQueueArr<T>
{

public:
    void push(T value)
    {
       this->Array.InsertAtBeginning(value);
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