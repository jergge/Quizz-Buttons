#include "Player.h"

//Defautl const fro allocating array sizes... xxxx
Player::Player(){}

//player IDs starting from index in const pin offset
Player::Player(int pid)
{
    Serial.println(" ");
    Serial.print("Creating Player ");
    Serial.println(pid);
    id = pid;
    led = new Led(pid * 2 + pinOffset);
    button = new MomentaryButton(pid * 2 + 1 + pinOffset);
}

void Player::Enable()
{
    enabled = true;
    Serial.print("Player ");
        Serial.print(id);
        Serial.println(" has been enabled");
}

void Player::Disable()
{
    enabled = false;
    Serial.print("Player ");
        Serial.print(id);
        Serial.println(" has been disabled");
}

bool Player::ButtonPushed()
{
    if (!enabled)
    {
        return false;
    }

    if (button->Pressed())
    {
        Serial.print("Player ");
            Serial.print(id);
            Serial.println("'s button is pressed!");
    } else
    {
        // Serial.print("Player ");
        //     Serial.print(id);
        //     Serial.println("'s button is NOT pressed!");

    }

    return button->Pressed();
}

void Player::LedDisable()
{
    led->Disable();
            Serial.print("Player ");
        Serial.print(id);
        Serial.println("'s LED is off");
}

void Player::LedEnable()
{
    led->Enable();
    Serial.print("Player ");
        Serial.print(id);
        Serial.println("'s LED is on");
}