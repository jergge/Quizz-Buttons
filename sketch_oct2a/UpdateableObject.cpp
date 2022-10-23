#include "UpdateableObject.h"
#include <HardwareSerial.h>

LinkedList<UpdateableObject> UpdateableObject::objects;

UpdateableObject::UpdateableObject()
{
    // Serial.print(" | Creating UO | ");
    objects.Append(this);
}

void UpdateableObject::Update()
{

}

void UpdateableObject::TestStatic()
{
    Serial.println("Test function");
}

void UpdateableObject::CallUpdates()
{
    objects.Get(1).pObject->Update();
    //Serial.println("running the call updates function");
    // for (int i = 0; i < objects.Count(); i++)
    // {
    //     Serial.print("Updateing object # ");
    //     Serial.println(i);
    //     objects.Get(i).GetPointer()->Update();
    // }


}

void UpdateableObject::CallLateUpdates()
{

}

void UpdateableObject::VerifyObjects()
{
    objects.Get(0).pObject->Update();
    objects.Get(1).pObject->Update();
    // Serial.print("there are ");
    // Serial.print(objects.Count());
    // Serial.println(" objects in the list.");

    // //objects.Get(4);

    // Serial.println("Attempting to Update the 1st object [ .Get(0).pObject->Update(); ] ");
}