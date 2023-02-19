#include <iostream>
#include <iomanip>
#include "Map.hpp"
#include "Alien.hpp"
using namespace std;
Map::Map(int dimx, int dimy)
{
    init(dimx, dimy);
}

void Map::setdimX(int dimX_)
{
    this->dimX_ = dimX_;
}

void Map::setdimY(int dimY_)
{
    this->dimY_ = dimY_;
}

int Map::getNextObj(int x, int y, int currTask)
{
    Alien Alien;
    char obj = getObject(x, y);
    switch (obj)
    {
    case '^':
        return 13;
        break;

    case 'v':
        return 14;
        break;

    case '<':
        return 15;
        break;

    case '>':
        return 16;
        break;

    case 'p':
    {
        cout << "it is a pod" << endl;
        cout << "Press enter to continue ..." << endl;
        int saveTask = currTask;
        std::cin.get();
        return 8;
    }

    case 'h':
    {
        cout << "Alien found a health" << endl;
        cout << "Press enter to continue ..." << endl;
        int saveTask = currTask;
        std::cin.get();
        return 10;
    }

    case 's':
    {
        cout << "Alien found a shield" << endl;
        cout << "Press enter to continue ..." << endl;
        int saveTask = currTask;
        std::cin.get();
        return 39;
    }

    case '1':
        return 28;
        break;

    case '2':
        return 29;
        break;

    case '3':
        return 30;
        break;

    case '4':
        return 31;
        break;

    case '5':
        return 32;
        break;

    case '6':
        return 33;
        break;

    case '7':
        return 34;
        break;

    case '8':
        return 35;
        break;

    case '9':
        return 36;
        break;
    case 'r':
        return 11;
    default:
        break;
        // and so on...
    }
    return currTask;
}

bool Map::isEmpty(int x, int y)
{
    return map_[dimY_ - y][x - 1] == ' ';
}

bool Map::isInsideMap(int x, int y)
{
    return x && y && dimX_ - x + 1 && dimY_ - y + 1;
}

void Map::setObject(int x, int y, char ch)
{
    map_[dimY_ - y][x - 1] = ch;
}

char Map::getObject(int x, int y) const
{
    return map_[dimY_ - y][x - 1];
}

int Map::getDimX()
{
    return dimX_;
}

int Map::getDimY()
{
    return dimY_;
}

void Map::init(int dimX, int dimY)
{
    dimX_ = dimX;
    dimY_ = dimY;
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'r', 'r', '^', '^', '>', '>', '<', '<', 'v', 'v', 'h', 'h', 'p', 'p', 's'};
    int noOfObjects = 22;
    map_.resize(dimY_);
    for (int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_);
    }
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
}

void Map::display() const
{
    if (2 * dimX_ > 17)
    {
        for (int k = 0; k < (2 * dimX_ - 17) / 2 + 3; ++k)
        {
            cout << " ";
        }
        cout << ">Alien vs Zombie<" << endl;
    }
    else
        cout << ">Alien vs Zombie<" << endl;
    for (int i = 0; i < dimY_; ++i)
    {
        cout << "  ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        cout << setw(2) << (dimY_ - i);
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}
