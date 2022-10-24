#pragma once
#include "Node.h"
#include <HardwareSerial.h>

template <typename T> class LinkedList
{
    public:
        LinkedList();
        void Push(T * pItem);
        void Append(T * pItem);
        void Remove(T * pItem);
        Node<T> Get(int item);
        T GetData(int item);
        int Count();
        void Clear();

    protected:
        Node<T> *pHead; // A Pointer to the first node in the list
        Node<T> *pTail; // A Pointer to the last node in the list
        Node<T> *index; // A Pointer to help itterate through the lsit
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
void LinkedList<T>::Append(T* pItem)
{
    //Serial.println("adding something to a LinkedList");
    if (length == 0)
    {
        pHead = new Node<T>(pItem);
        pTail = pHead;
    } else
    {
        Node<T> * newNode = new Node<T>( pItem);
        newNode->pNextNode = nullptr;
        pTail->pNextNode = newNode;
        pTail = newNode;
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
        Serial.println("LinkedList::Get is out of bounds");
        return Node<T>(nullptr);
    }
    Node<T> * node = pHead;

    int j = 0;

    for (int i = 0; i < index; i++)
    {
        //Serial.println(j);
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