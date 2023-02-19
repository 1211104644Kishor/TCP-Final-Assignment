#include "Mapsetting.hpp"

Mapsetting::Mapsetting()
{
}

void Mapsetting::setColumns(int columns)
{
    this->columns = columns;
}

void Mapsetting::setRows(int rows)
{
    this->rows = rows;
}

void Mapsetting::setCount(int count)
{
    this->count = count;
}

int Mapsetting::getColumns()
{
    return this->columns;
}

int Mapsetting::getRows()
{
    return this->rows;
}
int Mapsetting::getCount()
{
    return this->count;
}

void Mapsetting::setZ(int Z)
{
    this->Z = Z;
}
int Mapsetting::getZ() const
{
    return Z;
}
