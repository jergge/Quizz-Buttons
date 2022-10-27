#include "UpdateableObject.h"


LinkedList<UpdateableObject> UpdateableObject::objectsList;

UpdateableObject::UpdateableObject()
{
    // Serial.print(" | Creating UO | ");
    objectsList.Append(this);
}

void UpdateableObject::TestStatic()
{
    Serial.println(F("Test function"));
}

void UpdateableObject::CallUpdates()
{
    //objectsList.Get(1).DataPtr()->Update();

    // Serial.println("running the call updates function");
    for (int i = 0; i < objectsList.Count(); i++)
    {
        // Serial.print("Updating object # ");
        // Serial.println(i);
        objectsList.Get(i).DataPtr()->Update();
    }


}

void UpdateableObject::CallLateUpdates()
{

}

void UpdateableObject::VerifyObjects()
{
    //objectsList.Get(0).DataPtr()->Update();
    //objectsList.Get(1).DataPtr()->Update();
    // Serial.print("there are ");
    // Serial.print(objectsList.Count());
    // Serial.println(" objectsList in the list.");

    // //objectsList.Get(4);

    // Serial.println("Attempting to Update the 1st object [ .Get(0).pData->Update(); ] ");
}

void UpdateableObject::Update()
{
    
}