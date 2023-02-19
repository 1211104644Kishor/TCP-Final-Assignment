#ifndef Obj_HPP_
#define Obj_HPP_
#include "Rover.hpp"
#include "Map.hpp"
#include <stdlib.h>
class Obj : public Rover
{
protected:
    int Targetx, Targety;
    char Alien_;

public:
    Obj();
    int getX();
    int getY();
    void setTargetx(int Targetx);
    void setTargety(int Targety);
    int getTargetx();
    int getTargety();
    void Alien(Map &map);
    void help(Map &map, int &task);
    void arrow(Map &map, int &task);
    void save(Map &map);
    void load(Map &map);
    void quit(Map &map);
    void up(Map &map, int &task);
    void down(Map &map, int &task);
    void right(Map &map, int &task);
    void left(Map &map, int &task);
    void rock(Map &map, int &task);
    void trail(Map &map, int &task);
    void quit(Map &map, int &task);
};


#endif