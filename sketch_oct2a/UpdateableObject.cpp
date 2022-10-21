#include "UpdateableObject.h"

LinkedList<UpdateableObject> UpdateableObject::objects = LinkedList<UpdateableObject>();

UpdateableObject::UpdateableObject()
{
    //Serial.print("Updatle object ");
    objects.Append(this);
}

void UpdateableObject::Update()
{

}

void UpdateableObject::UpdateAll()
{
    for (int i = 0; i < objects.Count(); i++)
    {
        objects.Get(i).GetPointer()->Update();
    }
}