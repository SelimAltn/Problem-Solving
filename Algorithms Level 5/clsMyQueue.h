#pragma once
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;
template <class T>
class clsMyQueue
{
protected:
    clsDblLinkedList<T> _List;

public:
    void Print(string delim = " ")
    {
        _List.PrintList(delim);
    }
    

    void push(T value)
    {
        _List.InsertAtEnd(value);
    }
    void pop()
    {
        _List.DeleteFirstNode();
    }
    T front()
    {
        return _List.GetItem(0);
    }
    T back()
    {
        return _List.GetItem(_List.Size() - 1);
    }
    int Size()
    {
        return _List.Size();
    }
    bool IsEmpty()
    {
        return _List.IsEmpty();
    }

    T GetItem(int Index)
    {
        return _List.GetItem(Index);
    }
    void Reverse()
    {
        _List.Reverse();
    }
    bool UpdateItem(int Index, T value)
    {
        return _List.UpdateItem(Index, value) ? true : false;
    }
    bool InsertAfter(int Index, T value)
    {
        return _List.InsertAfter(Index , value) ? true : false ;
    }
    void InsertAtFront (T value){
        _List.InsertAtBeginning(value);
    }
    void InsertAtBack(T value){
        _List.InsertAtEnd(value);
    }
    void Clear (){
        _List.Clear();
    }

};