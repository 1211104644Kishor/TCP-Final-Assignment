#ifndef Save_HPP_
#define SaVE_HPP_
#include <stdlib.h>
class Save
{
protected:
    int oy;  // y of save obj
    int ox;  // x of save obj
    char oo; // char save obj
    int o;   // num of obj

public:
    Save();
    void setox(int ox);
    void setoy(int oy);
    void setoo(char oo);
    int getox();
    int getoy();
    int getoo();
    void seto(int o);
    int geto();
};

#endif