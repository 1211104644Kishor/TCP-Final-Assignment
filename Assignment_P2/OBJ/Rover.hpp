#ifndef Rover_HPP_
#define Rover_HPP_
#include <stdlib.h>
class Rover
{
protected:
    int x_;
    int y_;

public:
    Rover();
    int getX();
    int getY();
    void setx(int x_);
    void sety(int y_);
};


#endif