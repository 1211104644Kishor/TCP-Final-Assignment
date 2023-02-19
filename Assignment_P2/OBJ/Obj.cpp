#include "Obj.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>

Obj::Obj()
{
}

void Obj::Alien(Map &map)
{
    char Alien = {'A'};
    x_ = (map.getDimX() + 1) / 2;
    y_ = (map.getDimY() + 1) / 2;
    Alien_ = Alien;
    map.setObject(x_, y_, Alien_);
}

int Obj ::getX()
{
    return x_;
}

int Obj ::getY()
{
    return y_;
}

void Obj::setTargetx(int Targetx)
{
    this->Targetx = Targetx;
}

void Obj::setTargety(int Targety)
{
    this->Targety = Targety;
}

int Obj ::getTargetx()
{
    return Targetx;
}

int Obj::getTargety()
{
    return Targety;
}

void Obj::up(Map &map, int &nextTask)
{
    char Alien = map.getObject(x_, y_);
    int targetX = x_;
    int targetY = y_;
    targetY += 1;
    setTargetx(targetX);
    setTargety(targetY);
    if (map.isInsideMap(targetX, targetY))
    {
        // Check next
        nextTask = map.getNextObj(targetX, targetY, nextTask);
        if (nextTask == 11) // rock
        {
        }
        else if (nextTask == 28 || nextTask == 29 || nextTask == 30 || nextTask == 31 || nextTask == 32 || nextTask == 33 || nextTask == 34 || nextTask == 35 || nextTask == 36)
        {
            targetY -= 1;
            setTargety(targetY);
        }
        // Update
        else
        {
            map.setObject(x_, y_, '.'); // Remove old
            x_ = targetX;
            y_ = targetY;
            map.setObject(targetX, targetY, Alien); // New
        }
    }

    else
    {
        cout << "Alien stop moving" << endl;
        cout << "Press enter to continue ..." << endl;
        std::cin.get();
        nextTask = 12;
    }
}

void Obj::down(Map &map, int &nextTask)
{
    char Alien = map.getObject(x_, y_);
    int targetX = x_;
    int targetY = y_;
    targetY -= 1;
    setTargetx(targetX);
    setTargety(targetY);
    if (map.isInsideMap(targetX, targetY))
    {
        // Check next
        nextTask = map.getNextObj(targetX, targetY, nextTask);
        if (nextTask == 11) // rock
        {
        }
        else if (nextTask == 28 || nextTask == 29 || nextTask == 30 || nextTask == 31 || nextTask == 32 || nextTask == 33 || nextTask == 34 || nextTask == 35 || nextTask == 36)
        {
            targetY += 1;
            setTargety(targetY);
        }
        // Update
        else
        {
            map.setObject(x_, y_, '.'); // Remove old
            x_ = targetX;
            y_ = targetY;
            map.setObject(targetX, targetY, Alien); // New
        }
    }
    else
    {
        cout << "Alien stop moving" << endl;
        cout << "Press enter to continue ..." << endl;
        std::cin.get();
        nextTask = 12;
    }
}

void Obj::left(Map &map, int &nextTask)
{
    char Alien = map.getObject(x_, y_);
    int targetX = x_;
    int targetY = y_;
    targetX -= 1;
    setTargetx(targetX);
    setTargety(targetY);
    if (map.isInsideMap(targetX, targetY))
    {
        // Check next
        nextTask = map.getNextObj(targetX, targetY, nextTask);
        if (nextTask == 11) // rock
        {
        }
        else if (nextTask == 28 || nextTask == 29 || nextTask == 30 || nextTask == 31 || nextTask == 32 || nextTask == 33 || nextTask == 34 || nextTask == 35 || nextTask == 36)
        {
            targetX += 1;
            setTargetx(targetX);
        }
        // Update
        else
        {
            map.setObject(x_, y_, '.'); // Remove old
            x_ = targetX;
            y_ = targetY;
            map.setObject(targetX, targetY, Alien); // New
        }
    }
    else
    {
        cout << "Alien stop moving" << endl;
        cout << "Press enter to continue ..." << endl;
        std::cin.get();
        nextTask = 12;
    }
}

void Obj::right(Map &map, int &nextTask)
{
    char Alien = map.getObject(x_, y_);
    int targetX = x_;
    int targetY = y_;

    targetX += 1;
    setTargetx(targetX);
    setTargety(targetY);
    if (map.isInsideMap(targetX, targetY))
    {

        { // Check next
            nextTask = map.getNextObj(targetX, targetY, nextTask);
            if (nextTask == 11) // rock
            {
            }
            else if (nextTask == 28 || nextTask == 29 || nextTask == 30 || nextTask == 31 || nextTask == 32 || nextTask == 33 || nextTask == 34 || nextTask == 35 || nextTask == 36)
            {
                targetX -= 1;
                setTargetx(targetX);
            }
            else
            {                               // Update
                map.setObject(x_, y_, '.'); // Remove old
                x_ = targetX;
                y_ = targetY;
                map.setObject(targetX, targetY, Alien); // New
            }
        }
    }
    else
    {
        cout << "Alien stop moving" << endl;
        cout << "Press enter to continue ..." << endl;
        std::cin.get();
        nextTask = 12;
    }
}

void Obj::trail(Map &map, int &task)
{
    for (int x = 1; x <= map.getDimX(); x++)
    {
        for (int y = 1; y <= map.getDimY(); y++)
        {
            char obj = map.getObject(x, y);
            if (obj == 46)
            {
                char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'r', 'r', '^', '^', '>', '>', '<', '<', 'v', 'v', 'h', 'h', 'p', 'p', 's'};
                int num = rand() % 22;
                map.setObject(x, y, objects[num]);
            }
        }
    }
    cout << "Alien turn end" << endl;
    cout << "Press enter to continue ..." << endl;
    std::cin.get();
    cout << "Zombie turn" << endl;
    cout << "Press enter to continue ..." << endl;
    std::cin.get();
    task = 17;
}

void Obj::arrow(Map &map, int &task)
{
    int x, y;
    string turning;
    bool direc = true;
    while (direc)
    {
        cout << "key in x coordinate=>";
        cin >> x;
        cout << endl;
        cout << "key in y coordinate=>";
        cin >> y;
        cout << endl;
        if (map.isInsideMap(x, y) && y <= map.getDimY() && y > 0 && x <= map.getDimX() && x > 0)
        {
            char arrow = map.getObject(x, y);
            if (arrow == 60 || arrow == 118 || arrow == 94 || arrow == 62)
            {
                cout << "key in arrow direction(left,right,up ,down)=>";
                cin >> turning;
                cout << '\n';
                if (turning == "left")
                {
                    arrow = 60; //<
                    direc = false;
                }
                else if (turning == "right")
                {
                    arrow = 62; //>
                    direc = false;
                }
                else if (turning == "up")
                {
                    arrow = 94; //^
                    direc = false;
                }
                else if (turning == "down")
                {
                    arrow = 118; // v
                    direc = false;
                }
                else
                {
                    cout << "unvalid direction" << endl;
                    cout << "Press enter to continue ..." << endl;
                    std::cin.get();
                    cin.clear();
                    cin.ignore(10, '\n');
                }
            }
            else
            {
                cout << "not an arrow" << endl;
                cout << "Press enter to continue ..." << endl;
                std::cin.get();
                cin.clear();
                cin.ignore(10, '\n');
            }
            map.setObject(x, y, arrow);
        }
        else
        {
            cout << "unvalid coordinate" << endl;
            cout << "Press enter to continue ..." << endl;
            std::cin.get();
            cin.clear();
            cin.ignore(10, '\n');
        }
    }
    map.display();
    task = 0;
}

void Obj::help(Map &map, int &task)
{
    cout << "Commands" << endl;
    cout << "1. up     - Move up." << endl;
    cout << "2. down   - Move down." << endl;
    cout << "3. left   - Move left." << endl;
    cout << "4. right  - Move right." << endl;
    cout << "5. arrow  - Change the direction of an arrow." << endl;
    cout << "6. help   - Display these user commands." << endl;
    cout << "7. save   - Save the game." << endl;
    cout << "8. load   - Load a game." << endl;
    cout << "9. quit   - Quit the game." << endl;
    task = 0;
}

void Obj::save(Map &map)
{
    cout << "saving..." << endl;
}

void Obj::load(Map &map)
{
    cout << "loading..." << endl;
}

void Obj::quit(Map &map)
{
    cout << "quit the game" << endl;
}

void Obj ::rock(Map &map, int &task)
{
    int x = getTargetx();
    int y = getTargety();
    char obj = map.getObject(x, y);
    int num = rand() % 8;
    switch (num)
    {
    case 0: // ^
        obj = 94;
        cout << "Alien discover an up arrow beneath the rock" << endl;
        cout << endl;
        break;

    case 1: // <
        obj = 60;
        cout << "Alien discover an left arrow beneath the rock" << endl;
        cout << endl;
        break;

    case 2: // >
        obj = 62;
        cout << "Alien discover an right arrow beneath the rock" << endl;
        cout << endl;
        break;

    case 3: // v
        obj = 118;
        cout << "Alien discover an down arrow beneath the rock" << endl;
        cout << endl;
        break;

    case 4: // p
        obj = 112;
        cout << "Alien discover a pod  beneath the rock" << endl;
        cout << endl;
        break;

    case 5: // h
        obj = 104;
        cout << "Alien discover an health  beneath the rock" << endl;
        cout << endl;
        break;

    case 6: // s
        obj = 115;
        cout << "There is a shield beneath the rock" << endl;
        cout << endl;
        break;

    case 7: // ' '
        obj = 32;
        cout << "There is nothing beneath the rock" << endl;
        cout << endl;
        break;

    default:
        break;
    }
    map.setObject(x, y, obj);
    cout << "Press enter to continue ..." << endl;
    std::cin.get();
    task = 12;
}

void Obj::quit(Map &map, int &task)
{
    string quit;
    bool qit = true;
    while (qit)
    {
        cout << "Quit the game? y/n =>";
        cin >> quit;
        if (quit == "y")
        {
            task = 88;
            cout << "Quit the game !" << endl;
            qit = false;
            break;
        }
        else if (quit == "n")
        {
            task = 0;
            cout << "game continue" << endl;
            qit = false;
            break;
        }
        else
        {
            cout << "Please key in y/n only!" << endl;
        }
    }
}