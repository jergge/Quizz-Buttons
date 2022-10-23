#pragma once

template <typename T> class Node
{
    public:
        bool EndOfList() {
            if (pNextNode == nullptr)
            {
                return true;
            }
            return false;
        }
        
        Node * NextNode() 
        {
            return pNextNode;
        }

        T * GetPointer();
        Node();
        ~Node() {}
        T * pObject; // A pointer to the object in the List
        Node * pNextNode;

    protected:
};

template <typename T>
T * Node<T>::GetPointer()
{
    return pObject;
}

template <typename T>
Node<T>::Node()
{
    pNextNode = nullptr;
}