#include "Alien.hpp"
Alien::Alien(){

}

void Alien::setHP(int hp)
{
    this->hp = hp;
}

void Alien::setATK(int atk)
{
    this->atk = atk;
}

void Alien::setshield(int shield)
{
    this->shield = shield;
}

int Alien::getHP()
{

    return this->hp;
}

int Alien::getATK()
{
    return this->atk;
}

int Alien::getshield()
{
    return this->shield;
}