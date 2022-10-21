#pragma once
#include "Node.h"

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
        const Node<T> *head; // A Pointer to the first node in the list
        int length = 0;
};

template <typename T>
LinkedList<T>::LinkedList()
{
    head = new Node<T>();
}

template <typename T>
void LinkedList<T>::Append(T* pItem)
{
    //Serial.println("adding something to a list ");
    Node<T> *lastNode = head;
    while (lastNode->pNextNode != nullptr)
    {
        lastNode = lastNode->NextNode();
    }

    Node<T> * newNode = new Node<T>();

    lastNode->pNextNode = newNode;
    newNode->pNextNode = nullptr;
    newNode->pObject = pItem;

    //Serial.println("New item appened to the list");
    
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

    for (int i = 0; i < index; i++)
    {
        node = node->NextNode();
    }

    return *node;
}