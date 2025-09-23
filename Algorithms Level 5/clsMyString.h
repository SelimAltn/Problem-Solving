#pragma once
#include <iostream>
#include "clsMyStack.h"

using namespace std;

class clsMyString
{
private:
    string _Value;
    clsMyStack<string> _Undo;
    clsMyStack<string> _Redo;

public:
    clsMyString()
    {
        this->_Value = "";
        _Undo.push(_Value);
    }
    string Value()
    {
        return this->_Value;
    }
    void SetValue(string newValue)
    {
        _Undo.push(_Value);

        this->_Value = newValue;
    }
    void Undo()
    {
        if (_Undo.Size() > 1)
        {
            _Redo.push(this->_Value);
            _Undo.pop();
            this->_Value = _Undo.Top();
        }
    }
    void Redo()
    {
        if (!_Redo.IsEmpty())
        {
            string redoValue = _Redo.Top();
            _Redo.pop();
            this->_Value = redoValue;
            _Undo.push(_Value);
        }
    }
};