#include "Save.hpp"

Save ::Save()
{
}

void Save::setox(int ox)
{
    this->ox = ox;
}

void Save::setoy(int oy)
{
    this->oy = oy;
}

void Save::setoo(char oo)
{
    this->oo = oo;
}

int Save::getox()
{
    return ox;
}

int Save::getoy()
{
    return oy;
}

int Save::getoo()
{
    return oo;
}

void Save::seto(int o)
{
    this->o = o;
}

int Save::geto()
{
    return o;
}