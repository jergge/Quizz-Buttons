#pragma once
#include "Node.h"
#include <HardwareSerial.h>

template <typename T> class LinkedList
{
    public:
        LinkedList();
        //Add an item to the start of the list
        void Push(T * pNewItem);
        //Add an item to the end of the list
        void Append(T * pNewItem);
        void Remove(T * pNewItem);
        Node<T> Get(int item);
        T GetData(int item);
        //Returns the number of items in the list
        int Count();
        //Not Yet Tested!
        void Clear();

    protected:
        Node<T> *pHead; // A Pointer to the first node in the list
        Node<T> *pTail; // A Pointer to the last node in the list
        Node<T> *index; // A Pointer to help iterate through the lsit
        int length = 0;
};

template <typename T>
LinkedList<T>::LinkedList()
{
    pHead = nullptr;
    pTail = nullptr;
    length = 0;
}

template <typename T>
void LinkedList<T>::Append(T* pNewItem)
{
    //Serial.println("adding something to a LinkedList");
    if (length == 0)
    {
        pHead = new Node<T>(pNewItem);
        pTail = pHead;
    } else
    {
        Node<T> * pNewNode = new Node<T>(pNewItem);
        pNewNode->pNextNode = nullptr;
        pTail->pNextNode = pNewNode;
        pTail = pNewNode;
    }
    length++;
}

template <typename T>
int LinkedList<T>::Count()
{
    return length;
}

template <typename T>
Node<T> LinkedList<T>::Get(int index)
{
    if (index > Count())
    {
        Serial.println(F("LinkedList::Get is out of bounds"));
        return Node<T>(nullptr);
    }
    Node<T> * node = pHead;

    int j = 0;

    for (int i = 0; i < index; i++)
    {
        node = node->pNextNode;
        j++;
    }

    // Serial.print("Returning node number: ");
    // Serial.println(j);

    return *node;
}

template <typename T>
T LinkedList<T>::GetData(int index)
{
    return *Get(index).DataPtr;
}

template <typename T>
void LinkedList<T>::Clear()
{
    if ( length == 0 )
    {
        return;
    }

    Node<T> * next;
    int count = Count();
    for (int i = 0; i < count; i++)
    {
        next = pHead->pNextNode;
        delete pHead;
        pHead = next;
        length --;
    }

    pHead = nullptr;
    pTail = nullptr;
}