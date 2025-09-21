#pragma once
#include <iostream>

using namespace std;
template <class T>
class clsDblLinkedList
{

public:
    struct Node
    {
        Node *next;
        Node *prev;
        T value;
        Node(T val) : value(val), next(NULL), prev(NULL) {}
    };
    clsDblLinkedList() : _head(NULL), _Size(0) {} // Doğru constructor

    Node *head()
    {
        return _head;
    }
    void InsertAtBeginning(T value)
    {
        Node *newNode = new Node(value);
        _Size++;

        newNode->next = _head;

        if (_head != NULL)
        {
            _head->prev = newNode;
        }

        _head = newNode;
    }
    Node *Find(T val)
    {

        Node *current = _head;

        while (current != NULL)
        {
            if (current->value == val)
                return current;
            current = current->next;
        }
        return NULL;
    }
    void InsertAfter(Node *&node, T val)
    {
        if (node != NULL)
        {
            Node *newNode = new Node(val);
            _Size++;

            newNode->next = node->next;
            newNode->prev = node;
            if (node->next != NULL)
                node->next->prev = newNode;
            node->next = newNode;
        }
        else
            cout << "Node is Null " << endl;
    }
    void InsertAtEnd(T val)
    {
        Node *newNode = new Node(val);
        _Size++;

        if (_head == NULL)
        {
            _head = newNode;
        }
        else
        {
            Node *current = _head;

            while (current->next != NULL)
            {

                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }
    void DeleteNode(Node *&node)
    {
        if (node == NULL)
            return;
        if (node->prev != NULL)
            node->prev->next = node->next;
        else
            _head = node->next;
        if (node->next != NULL)
            node->next->prev = node->prev;
        node->next = NULL;
        node->prev = NULL;
        delete node;
        _Size--;
    }
    void DeleteFirstNode()
    {

        if (_head == NULL)
            return;
        Node *node = _head;
        _head = node->next;

        if (_head != NULL)
            _head->prev = NULL;
        delete node;
        _Size--;
    }
    void DeleteLastNode()
    {
        if (_head == NULL)
            return;
        if (_head->next == NULL)
        {
            delete _head;
            _Size--;
            _head = NULL;
            return;
        }
        Node *node = _head;
        while (node->next != NULL)
        {
            node = node->next;
        }
        node->prev->next = NULL;
        delete node;
        _Size--;
    }
    void PrintList()
    {
        Node *current = _head;
        cout << "NULL ";
        while (current != NULL)
        {
            cout << " <-- " << current->value << " --> ";
            current = current->next;
        }
        cout << "NULL " << endl;
    }
    int Size()
    {

        return _Size;
    }
    bool IsEmpty()
    {
        return _Size == 0 ? true : false;
    }
    void Clear()
    {
        while (_Size > 0)
        {
            DeleteFirstNode();
        }
    }
    void Reverse()
    {
        Node *current = _head;
        Node *temp = nullptr;
        while (current != NULL)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != NULL)
        {
            _head = temp->prev;
        }
    }
    Node *GetNode(int Index)
    {
        if (Index > _Size - 1 || Index < 0)
            return NULL;
        int counter = 0; // head = 0
        Node *current = _head;
        while (current != NULL && (current->next != NULL))
        {
            if (counter == Index)
            {
                break;
            }
            current = current->next;
            counter++;
        }
        return current;
    }
    T GetItem(int Index)
    {
        Node *ItemNode = GetNode(Index);
        if (ItemNode == NULL)
        {
            return T();
        }
        else
        {
            return ItemNode->value;
        }
    }
    bool UpdateItem(int Index, T value)
    {
        Node *ItemNode = GetNode(Index);
        if (ItemNode != NULL)
        {
            ItemNode->value = value;
            return true;
        }
        else
            return false;
    }
    bool InsertAfter(int Index, T value)
    {
        Node *ItemNode = GetNode(Index);
        if (ItemNode != NULL)
        {
            InsertAfter(ItemNode, value);
            return true;
        }
        else 
            return false;
    }

private:
    Node *_head = NULL;
    int _Size;
};