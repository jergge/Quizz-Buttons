#include "Player.h"

//Defautl const fro allocating array sizes... xxxx
Player::Player(){}

//player IDs starting from index in const pin offset
Player::Player(int pid)
{
    id = pid;
    led = new Led(pid * 2 + pinOffset);
    button = new MomentaryButton(pid * 2 + 1 + pinOffset, true);
}

void Player::Enable()
{
    enabled = true;
    led->Enable();
    button->Enable();
}

void Player::Disable()
{
    enabled = false;
    led->Disable();
    led->StopBlink();
    led->Off();
    button->Disable();
}


bool Player::ButtonPushed()
{
    if (!enabled)
    {
        return false;
    }

    return button->IsPressed();
}

void Player::Blink()
{
    if (enabled)
    {
        led->Blink(ledBlinkTimeMS, true);
    }
}

void Player::LedOn()
{
    led->Enable();
    led->On();
}

void Player::LedOff()
{
    led->Disable();
    led->Off();
}

bool Player::IsEnabled()
{
    return enabled;
}