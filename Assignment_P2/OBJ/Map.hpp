#ifndef Map_HPP_
#define Map_HPP_

#include<vector>
using namespace std;
class Map
{
protected:
    vector<vector<char>> map_;
    int dimX_;
    int dimY_;

public:
    Map(int dimX = 9, int dimY = 5);
    void init(int dimX, int dimY);
    void display() const;
    int getDimX();
    int getDimY();
    void setdimX(int dimX_);
    void setdimY(int dimY_);
    char getObject(int x, int y) const;
    void setObject(int x, int y, char ch);
    bool isEmpty(int x, int y);
    bool isInsideMap(int x, int y);
    int getNextObj(int x, int y, int currTask);
};

#endif