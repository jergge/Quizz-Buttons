#include "Player.h"

//Defautl const fro allocating array sizes... xxxx
Player::Player(){}

//player IDs starting from index in const pin offset
Player::Player(int pid)
{
        // Serial.println(" ");
        // Serial.print("Creating Player ");
        // Serial.println(pid);
    id = pid;
    //Serial.print("Creating led ");
    led = new Led(pid * 2 + pinOffset);
    // Serial.print("Creating button ");
    button = new MomentaryButton(pid * 2 + 1 + pinOffset, true);
}

void Player::Enable()
{
    enabled = true;
    // Serial.print("Player ");
    //     Serial.print(id);
    //     Serial.println(" has been enabled");
    LedEnable();
}

void Player::Disable()
{
    enabled = false;
    // Serial.print("Player ");
    //     Serial.print(id);
    //     Serial.println(" has been disabled");
    LedDisable();
}

bool Player::ButtonPushed()
{
    if (!enabled)
    {
        return false;
    }

    if (button->IsPressed())
    {
        // Serial.print("Player ");
        //     Serial.print(id);
        //     Serial.println("'s button is pressed!");
    } else
    {
        // Serial.print("Player ");
        //     Serial.print(id);
        //     Serial.println("'s button is NOT pressed!");

    }
    return button->IsPressed();
}

void Player::LedDisable()
{
    led->Disable();
//             Serial.print("Player ");
//         Serial.print(id);
//         Serial.println("'s LED is off");
}

void Player::LedEnable()
{
    led->Enable();
    //led->On();
    led->Blink(500, true);
    // Serial.print("Player ");
    //     Serial.print(id);
    //     Serial.println("'s LED is on");
}

bool Player::IsEnabled()
{
    return enabled;
}