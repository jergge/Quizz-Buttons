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
        int Count();

    protected:
        Node<T> *head; // A Pointer to the first node in the list
        Node<T> *tail; // A Pointer to the last node in the list
        Node<T> *index; // A Pointer to help itterate through the lsit
        int length = 0;
};

template <typename T>
LinkedList<T>::LinkedList()
{
    head = new Node<T>();
    tail = head;
}

template <typename T>
void LinkedList<T>::Append(T* pItem)
{
    if (length == 0)
    {
        head->pObject = pItem;
    } else
    {
        Node<T> * newNode = new Node<T>();
        newNode->pNextNode = nullptr;
        newNode->pObject = pItem;
        tail->pNextNode = newNode;
        tail = newNode;
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
        // handle overflow...
    }
    Node<T> * node = head;

    int j = 0;

    for (int i = 0; i < index; i++)
    {
        //Serial.println(j);
        node = node->NextNode();
        j++;
    }

    Serial.print("Returning node number: ");
    Serial.println(j);

    return *node;
}