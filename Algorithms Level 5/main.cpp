#include <iostream>
#include "clsDblLinkedList.h"
#include "clsMyQueue.h"
using namespace std;

int main()
{
    clsMyQueue <int> Queue;
    Queue.push(10);
    Queue.push(20);
    Queue.push(30);
    Queue.push(40);
    Queue.push(50);
    cout<<"Queue : \n";
    Queue.Print();
    cout<<endl <<"-----------------------"<<endl;
    cout<<"Queue Size : "<<Queue.Size()<<endl;
    cout<<"Queue front : "<<Queue.front()<<endl;
    cout<<"Queue back : "<<Queue.back()<<endl;

    Queue.pop();
    cout<<"queue after pop() \n";
    Queue.Print();

    cout<<"\n\n Item (2) : "<<Queue.GetItem(2)<<endl;
    Queue.Reverse();
    cout<<"Queue after reverse : "<<endl;
    Queue.Print();

    Queue.UpdateItem(2,600);
    cout<<"queue after updating item (2) to 600 : "<<endl;
    Queue.Print();

    Queue.InsertAfter(2,800);
    cout<<"Queue Insertint 800 after Item(2) : "<<endl;
    Queue.Print();
    Queue.InsertAtFront(1000);
    cout<<"Queue after Insertint 1000 at front : "<<endl;
    Queue.Print();

    Queue.InsertAtBack(2000);
    cout<<"Queue after Insertint 2000 at back : "<<endl;
    Queue.Print();

    Queue.Clear();
    cout<<"Queue after clear : "<<endl;
    Queue.Print();

    cout<<Queue.IsEmpty()<<endl;


}