#pragma once
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

template <class T>
class clsDynamicArray
{
protected:
    int _Size = 0;
    T *_TempArray;

public:
    T *OrginalArray;
    clsDynamicArray(int size = 0)
    {
        if (size < 0)
            size = 0;
        this->_Size = size;
        OrginalArray = new T[_Size];
    }
    ~clsDynamicArray()
    {
        delete[] OrginalArray;
    }

    bool SetItem(int Index, T value)
    {
        if (Index >= _Size || _Size < 0)
            return false;
        OrginalArray[Index] = value;
        return true;
    }
    bool IsEmpty()
    {
        return _Size == 0 ? true : false;
    }
    int Size()
    {
        return _Size;
    }
    void PrintArr()
    {
        for (int i = 0; i < _Size; i++)
        {
            cout << OrginalArray[i] << " ";
        }
        cout << endl;
    }
    bool Resize(int newSize)
    {
        // 0 1 2 3 4 5
        if (newSize == _Size)
            return false;
        if (newSize < 0)
            newSize = 0;
        _TempArray = new T[newSize];
        int minSize = (newSize < _Size) ? newSize : _Size;
        for (int i = 0; i < minSize; i++)
        {
            _TempArray[i] = OrginalArray[i];
        }
        delete[] OrginalArray;
        OrginalArray = _TempArray;
        _Size = newSize;
        return true;
    }
    void Clear()
    {
        _Size = 0;
        _TempArray = new T[0];
        delete[] OrginalArray;
        OrginalArray = _TempArray;
    }
    T GetItem(int Index)
    {
        return OrginalArray[Index];
    }
    void Reverse()
    {
        for (int i = 0; i < _Size / 2; i++)
        {
            T temp = OrginalArray[i];
            OrginalArray[i] = OrginalArray[_Size - 1 - i];
            OrginalArray[_Size - 1 - i] = temp;
        }
    }
    bool DeleteItemAt(int Index)
    {
        if (Index < 0 || Index >= _Size)
            return false;
        _Size--;
        _TempArray = new T[_Size];
        for (int i = 0; i < Index; i++)
        {
            _TempArray[i] = OrginalArray[i];
        }
        for (int i = Index + 1; i < _Size + 1; i++)
        {
            _TempArray[i - 1] = OrginalArray[i];
        }
        delete[] OrginalArray;
        OrginalArray = _TempArray;
        return true;
    }
    void DeleteFirstItem()
    {
        this->DeleteItemAt(0);
    }
    void DeleteLastItem()
    {
        this->DeleteItemAt(_Size - 1);
    }
    int Find(T value)
    {
        for (int i = 0; i < _Size; i++)
        {
            if (OrginalArray[i] == value)
                return i;
        }
        return -1;
    }
    bool DeleteItem(T value)
    {

        int Index = this->Find(value);
        if (Index == -1)
            return false;
        this->DeleteItemAt(Index);
        return true;
    }
    bool InsertAt(int Index, T value)
    {
        if (Index < 0 || Index > _Size)
        {
            return false;
        }
        _Size++;
        _TempArray = new T[_Size];
        for (int i = 0; i < Index; i++)
        {
            _TempArray[i] = OrginalArray[i];
        }
        _TempArray[Index] = value;
        for (int i = Index + 1; i < _Size; i++)
        {
            _TempArray[i] = OrginalArray[i - 1];
        }
        delete[] OrginalArray;
        OrginalArray = _TempArray;
        return true;
    }
    void InsertAtBeginning(T value)
    {
        this->InsertAt(0, value);
    }
    bool InsertBefore(int Index, T value)
    {
        if (Index < 1)
        {
            return this->InsertAt(0, value);
        }
        else
            return this->InsertAt(Index - 1, value);
    }
    bool InsertAfter(int Index, T value)
    {
        if (Index >= _Size)
            return this->InsertAt(_Size - 1, value);
        else
            return this->InsertAt(Index + 1, value);
    }
    void InsertAtEnd(T value)
    {
        this->InsertAt(_Size, value);
    }
};
