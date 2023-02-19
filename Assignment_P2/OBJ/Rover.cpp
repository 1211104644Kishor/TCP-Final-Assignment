#include "Rover.hpp"

Rover::Rover()
{
}

int Rover::getX()
{
    return x_;
}

int Rover::getY()
{
    return y_;
}

void Rover::setx(int x_)
{
    this->x_ = x_;
}

void Rover::sety(int y_)
{
    this->y_ = y_;
}