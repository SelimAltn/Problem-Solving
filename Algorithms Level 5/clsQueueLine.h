#pragma once
#include <iostream>
#include "clsMyQueue.h"

using namespace std;

class clsQueueLine
{
private:
    string _Perfix;
    int _TotalTicket = 0, _ServedClients =0, _WatingClients=0;
    clsMyQueue<string> _QueueLine;
    short _time;

public:
    clsQueueLine(string perfix, short time)
    {
        this->_Perfix = perfix;
        this->_time = time;
    }
    void IssueTicket()
    {
        _TotalTicket++;
        _WatingClients++;
        _QueueLine.push(_Perfix + to_string(_TotalTicket));
    }
    void printInfo()
    {
        cout<<"Queue Info : "<<endl;
        cout<<"Perfix : "<<_Perfix<<endl;
        cout<<"Total Ticket : "<<_TotalTicket<<endl;
        cout<<"Served Clients : "<<_ServedClients<<endl;
        cout<<"Wating Clients : "<<_WatingClients<<endl;
    }
    void PrintTicketsLineRTL(){
        cout<<"Ticketes : ";
        _QueueLine.Print("<--");

    }
     void PrintTicketsLineLTR(){
        cout<<"Ticketes : ";
        _QueueLine.Print("-->");

    }
};
