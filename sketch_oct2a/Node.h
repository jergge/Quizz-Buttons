#pragma once

template <typename T> class Node
{
    public:
        bool EndOfList();

        T * DataPtr();
        Node(T * data);
        ~Node() {}

        Node * pNextNode = nullptr;

    protected:
        T * pData; // A pointer to the data of the Node
};

template <typename T>
bool Node<T>::EndOfList()
{
    if (pNextNode == nullptr)
    {
        return true;
    }
    return false;
}

template <typename T>
T * Node<T>::DataPtr()
{
    return pData;
}

template <typename T>
Node<T>::Node(T * data)
{
    pData = data;
    pNextNode = nullptr;
}