#ifndef Zombie_HPP_
#define Zombie_HPP_
#include <stdlib.h>
class Zombie
{
protected:
    int x_;
    int y_;
    int hp;
    int atk;
    int atk_range;
    int left;
    int ttleft;

public:
    Zombie();
    int getHP();
    int getAtk();
    int getAtkRange();
    void setX(int x_);
    void setY(int y_);
    int getX();
    int getY();
    void setHP(int hp);
    void setATK(int atk);
    void setATKRange(int atk_range);
    void setleft(int left);
    int getleft();
    void setttleft(int ttleft);
    int getttleft();
};


#endif