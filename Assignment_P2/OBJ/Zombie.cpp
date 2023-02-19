#include <stdlib.h>
#include "Zombie.hpp"

using namespace std;
Zombie::Zombie()
{
    hp = (rand() % 5 + 2) * 50; // 100 - 300
    atk = (rand() % 5 + 1) * 5; // 5 - 25
    atk_range = rand() % 3 + 1; // 1 - 3
}

int Zombie::getHP()
{
    return hp;
}

int Zombie::getAtk()
{
    return atk;
}

int Zombie::getAtkRange()
{
    return atk_range;
}

void Zombie::setX(int x_)
{
    this->x_ = x_;
}

void Zombie::setY(int y_)
{
    this->y_ = y_;
}

int Zombie::getX()
{
    return x_;
}

int Zombie::getY()
{
    return y_;
}

void Zombie ::setHP(int hp)
{
    this->hp = hp;
}

void Zombie ::setATK(int atk)
{
    this->atk = atk;
}

void Zombie ::setATKRange(int atk_range)
{
    this->atk_range = atk_range;
}

void Zombie::setleft(int left)
{
    this->left = left;
}

int Zombie::getleft()
{
    return left;
}

void Zombie::setttleft(int left)
{
    this->ttleft = ttleft;
}

int Zombie::getttleft()
{
    return ttleft;
}