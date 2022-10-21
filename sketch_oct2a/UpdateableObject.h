#pragma once
#include "LinkedList.h"

class UpdateableObject
{
    static LinkedList<UpdateableObject> objects;

    public:
        virtual void Update();
        UpdateableObject();
        static void UpdateAll();
};