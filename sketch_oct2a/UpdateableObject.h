#pragma once
#include "Arduino.h"
#include <HardwareSerial.h>
#include "LinkedList.h"

class UpdateableObject
{
    static LinkedList<UpdateableObject> objectsList;

    public:
        virtual void Update();
        UpdateableObject();
        static void CallUpdates();
        static void CallLateUpdates();
        static void TestStatic();
        static void VerifyObjects();
};