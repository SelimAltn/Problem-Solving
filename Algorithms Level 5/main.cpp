#include <iostream>
#include "clsDblLinkedList.h"
#include "clsMyQueue.h"

#include "clsMyStack.h"
#include "clsDynamicArray.h"
using namespace std;

int main()
{
    /*
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

    clsMyStack <int> MyStack;

    MyStack.push(10);
    MyStack.push(20);
    MyStack.push(30);
    MyStack.push(40);
    MyStack.push(50);


    cout << "\nStack: \n";
    MyStack.Print();

    cout << "\nStack Size: " << MyStack.Size();
    cout << "\nStack Top: " << MyStack.Top();
    cout << "\nStack Bottom: " << MyStack.Bottom();

    MyStack.pop();

    cout << "\n\nStack after pop() : \n";
    MyStack.Print();

    //Extension #1
    cout << "\n\n Item(2) : " << MyStack.GetItem(2);

    //Extension #2
    MyStack.Reverse();
    cout << "\n\nStack after reverse() : \n";
    MyStack.Print();

    //Extension #3
    MyStack.UpdateItem(2, 600);
    cout << "\n\nStack after updating Item(2) to 600 : \n";
    MyStack.Print();

    //Extension #4
    MyStack.InsertAfter(2, 800);
    cout << "\n\nStack after Inserting 800 after Item(2) : \n";
    MyStack.Print();


    //Extension #5
    MyStack.InsertAtFront(1000);
    cout << "\n\nStack after Inserting 1000 at top: \n";
    MyStack.Print();

    //Extension #6
    MyStack.InsertAtBack(2000);
    cout << "\n\nStack after Inserting 2000 at bottom: \n";
    MyStack.Print();

    //Extension #7
    MyStack.Clear();
    cout << "\n\nStack after Clear(): \n";
    MyStack.Print();

*/

    clsDynamicArray<int> MyDynamicArray(5);
    cout << "\nIs Empty?  " << MyDynamicArray.IsEmpty();
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";

    MyDynamicArray.SetItem(0, 10);
    MyDynamicArray.SetItem(1, 20);
    MyDynamicArray.SetItem(2, 30);
    MyDynamicArray.SetItem(3, 40);
    MyDynamicArray.SetItem(4, 50);

    cout << "\nArray Items: \n";

    MyDynamicArray.PrintArr();



    MyDynamicArray.PrintArr();
    MyDynamicArray.InsertAtBeginning(400);
    MyDynamicArray.PrintArr();
    MyDynamicArray.InsertBefore(2,500);
    MyDynamicArray.PrintArr();
    MyDynamicArray.InsertAfter(6,600);
    MyDynamicArray.PrintArr();
    MyDynamicArray.InsertAtEnd(1000);
    MyDynamicArray.PrintArr();
  

}