#ifndef Alien_HPP_
#define Alien_HPP_
#include <stdlib.h>
class Alien
{
protected:
    int hp;
    int atk;
    int shield;

public:
    Alien();
    void setHP(int hp);
    void setATK(int atk);
    int getHP();
    int getATK();
    void setshield(int shield);
    int getshield();
};

#endif