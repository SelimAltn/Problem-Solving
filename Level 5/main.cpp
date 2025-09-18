#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

int main()
{
    clsDblLinkedList<int> List;
    cout << List.IsEmpty() << endl;
    List.InsertAtBeginning(9);
    List.InsertAtBeginning(8);
    List.InsertAtBeginning(7);
    List.InsertAtBeginning(5);
    List.PrintList();
    List.UpdateItem(2,100);
    List.PrintList();
    List.InsertAfter(1,1000);
    List.PrintList();
    
    
}