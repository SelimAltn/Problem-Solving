#pragma once
#include <iostream>
#include "clsDynamicArray.h"

using namespace std;
template <class T>
class clsMyQueueArr
{
protected:
    clsDynamicArray<T> Array;

public:
    void Print()
    {
        Array.PrintArr();
    }

    void push(T value)
    {
        Array.InsertAtEnd(value);
    }
    void pop()
    {
        Array.DeleteFirstItem();
    }
    T front()
    {
        return Array.GetItem(0);
    }
    T back()
    {
        return Array.GetItem(Array.Size() - 1);
    }
    int Size()
    {
        return Array.Size();
    }
    bool IsEmpty()
    {
        return Array.IsEmpty();
    }

    T GetItem(int Index)
    {
        return Array.GetItem(Index);
    }
    void Reverse()
    {
        Array.Reverse();
    }
    bool UpdateItem(int Index, T value)
    {
        return Array.SetItem(Index,value) ? true : false;
    }
    bool InsertAfter(int Index, T value)
    {
        return Array.InsertAfter(Index,value) ? true : false ;
        
    }
    void InsertAtFront (T value){
        Array.InsertAtBeginning(value);
    }
    void InsertAtBack(T value){
        Array.InsertAtEnd(value);
    }
    void Clear (){
        Array.Clear();
    }

};