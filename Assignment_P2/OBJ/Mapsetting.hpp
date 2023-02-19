#ifndef Mapsetting_HPP_
#define Mapsetting_HPP_
#include <stdlib.h>
class Mapsetting
{
protected:
    int rows;
    int columns;
    int count;
    int Z;
  
public:
    Mapsetting();
    void setColumns(int columns);
    void setRows(int rows);
    void setCount(int count);
    int getColumns();
    int getRows();
    int getCount();
    void setZ(int Z);
    int getZ() const;
};


#endif