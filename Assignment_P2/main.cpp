// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT4L&T12L
// Names: Nik Arasyh Haziq | Wong Jun Wei | Kishor A/L Gunaseharan
// IDs: 1221303553 | 1221303566 | 1211104644
// Emails: 1221303553@student.mmu.edu.my | 1221303566@student.mmu.edu.my | 1211104644@student.mmu.edu.my
// Phones: 019- 770 6496 | 011-3929 5516 | 017-385 7197
// *********************************************************

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <limits>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include "OBJ/Zombie.cpp"
#include "OBJ/Alien.cpp"
#include "OBJ/Mapsetting.cpp"
#include "OBJ/Map.cpp"
#include "OBJ/Rover.cpp"
#include "OBJ/Save.cpp"
#include "OBJ/Obj.cpp"
using namespace std;

void printASCII(string title)
{
    string LINE = "";
    ifstream inFile;
    inFile.open("title.txt");
    if (inFile.is_open())
    {
        while (getline(inFile, LINE))
        {
            cout << LINE << endl;
        }
    }
    else
    {
        cout << "File failed to load" << endl;
        cout << "No nuke displayed" << endl;
    }
    inFile.close();
}

void ASCIIgameover(string title)
{
    string LINE = "";
    ifstream inFile;
    inFile.open("game over.txt");
    if (inFile.is_open())
    {
        while (getline(inFile, LINE))
        {
            cout << LINE << endl;
        }
    }
    else
    {
        cout << "File failed to load" << endl;
        cout << "No nuke displayed" << endl;
    }
    inFile.close();
}

void ASCIIwin(string title)
{
    string LINE = "";
    ifstream inFile;
    inFile.open("win.txt");
    if (inFile.is_open())
    {
        while (getline(inFile, LINE))
        {
            cout << LINE << endl;
        }
    }
    else
    {
        cout << "File failed to load" << endl;
        cout << "No nuke displayed" << endl;
    }
    inFile.close();
}

bool lettersOrSpaces(const std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isalpha(str[i]) && !std::isspace(str[i]))
        {
            return false;
        }
    }
    return true;
}
float getDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((x1 - x2), 2.0) + pow((y1 - y2), 2.0));
}
void maingame()
{
    Mapsetting Mapsetting;
    int gameboard_rows;
    int gameboard_columns;
    int zombie_count;
    string change_settings;
    int change_settings_num;
    fstream myFile;
    string filename;
    string command;
    Obj curiosity;
    Save obj[1000];
    Alien Alien;
    Rover Rover;
    Zombie Array[9];
    Zombie Zombie;
    int Count;
    int i;
    float distance;
    int ATK;
    int HP;
    int task; // 0 = stop, 1 = up, 2 = down, 3 = left, 4 = right...
    int hpleft;
    int attack;
    int damage;
    int zombieturn;
    int Alienturn;
    int az; // array zombie/zombieturn -1
    for (int l = 0; l < 9; l++)
    {
        Array[l].setleft(0);
    }
    int Death;
    bool all = true;
    int o = 0; // save num of obj
    int z = 0; // save zombie array
    string choose;
    Mapsetting.setZ(0);
    gameboard_rows = 5;
    Mapsetting.setRows(5);
    gameboard_columns = 9;
    Mapsetting.setColumns(9);
    zombie_count = 1;
    Alien.setshield(0);

    while (all)
    {
        cout << "do you want to load game or start a new game(load/start)=>";
        cin >> choose;
        if (choose == "load")
        {
            Mapsetting.setZ(1);
            all = false;
        }
        else if (choose == "start")
        {
            Mapsetting.setZ(0);
            all = false;
        }
        else
        {
            cout << "unvalid command" << endl;
        }
    }

    if (Mapsetting.getZ() == 0)
    {
        cout << "Default Game Settings" << endl;
        cout << "-----------------------" << endl;
        cout << "Board Rows    : " << gameboard_rows << endl;
        cout << "Board Columns : " << gameboard_columns << endl;
        cout << "Zombie Count  : " << zombie_count << endl;
        cout << " " << endl;
        cout << "Do you wish to change the game settings (y/n)? => ";
        cin >> change_settings;

        while (change_settings != "y" && change_settings != "n")
        {
            cout << " " << endl;
            cout << "Please enter y/n only!" << endl;
            cout << "                                                                       " << endl;
            cout << "Do you wish to change the game settings (y/n)? => ";
            cin >> change_settings;
        }
        const char *y = "y";
        const char *n = "n";
        if (change_settings == y)
        {
            change_settings_num = 1;
        }
        else
        {
            change_settings_num = 0;
        }

        cout << " " << endl;

        if (change_settings_num == 1)
        {
            cout << "Board Settings" << endl;
            cout << "----------------" << endl;
            cout << "Enter rows => ";
            while (true)
            {
                cin >> gameboard_rows;

                if (!cin)
                {
                    cout << "No alphabets or speacial characters, please enter any odd numbers only" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter rows => ";
                    continue;
                }

                else if (gameboard_rows % 2 == 0)
                {
                    cout << "Number must be odd number, please try again" << endl;
                    cin.clear();
                    cout << "Enter rows => ";
                    continue;
                }
                else if (gameboard_rows < 0)
                {
                    cout << "Number must be positif" << endl;
                    cin.clear();
                    cout << "Enter rows => ";
                    continue;
                }
                else
                    break;
            }

            cout << "Enter columns => ";
            while (true)
            {

                cin >> gameboard_columns;

                if (!cin)
                {
                    cout << "No alphabets or special characters, please enter any odd numbers only." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter columns => ";
                    continue;
                }

                if (gameboard_columns % 2 == 0)
                {
                    cout << "Number must be odd number, please try again." << endl;
                    cin.clear();
                    cout << "Enter columns => ";
                    continue;
                }

                else if (gameboard_columns < 0)
                {
                    cout << "Number must be positif" << endl;
                    cin.clear();
                    cout << "Enter columns => ";
                    continue;
                }

                else if (gameboard_rows == 1 && gameboard_columns == 1)
                {
                    cout << "Both row and column could not be 1" << endl;
                    cin.clear();
                    cout << "Enter columns => ";
                    continue;
                }
                else
                    break;
            }
        }

        if (change_settings_num == 1)
        {
            cout << " " << endl;
            cout << "Zombie Settings" << endl;
            cout << "----------------" << endl;
            cout << "Enter number of zombies => ";
            while (true)
            {
                cin >> zombie_count;

                if (!cin)
                {
                    cout << "No alphabets or special characters is allowed" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter number of zombies => ";
                    continue;
                }

                else if (zombie_count > 9)
                {
                    cout << "Numbers more than 9 are not accepted, please try again." << endl;
                    cin.clear();
                    cout << "Enter number of zombies => ";
                    continue;
                }
                else if (zombie_count < 1)
                {
                    cout << "Numbers less than 1 are not accepted, please try again." << endl;
                    cin.clear();
                    cout << "Enter number of zombies => ";
                    continue;
                }
                else if (zombie_count > (gameboard_columns * gameboard_rows) / 2)
                {
                    cout << "Suggest to decrease the number of zombie for a better game" << endl;
                    cin.clear();
                    cout << "Enter number of zombies => ";
                    continue;
                }
                else
                    break;
            }

            cout << "Settings Updated." << endl;
        }

        if (change_settings_num == 0)
        {
            cout << "game continues" << endl;
        }
        Mapsetting.setColumns(gameboard_columns);
        Mapsetting.setRows(gameboard_rows);
        Mapsetting.setCount(zombie_count);
        cout << "board rows: " << gameboard_rows << endl;
        cout << "board columns: " << gameboard_columns << endl;
        cout << "zombie count: " << zombie_count << endl;
        int Columns = Mapsetting.getColumns();
        int Rows = Mapsetting.getRows();
        Count = Mapsetting.getCount();
        distance;
        Map map = Map(Columns, Rows);
        char Zombies[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for (i = 0; i < Count; i++)
        {
            int x_ = rand() % Columns + 1;
            int y_ = rand() % Rows + 1;
            char zz = map.getObject(x_, y_); // check it already has zombies or not
            if (((x_ == (Columns + 1) / 2) && (y_ == (Rows + 1) / 2)))
            {
                i -= 1; // run again randomly
            }
            else if (zz == '1' || zz == '2' || zz == '3' || zz == '4' || zz == '5' || zz == '6' || zz == '7' || zz == '8' || zz == '9')
            {
                i -= 1;
            }
            else
            {
                Array[i].setX(x_);
                Array[i].setY(y_);
                map.setObject(x_, y_, Zombies[i]);
            }
        }
        ATK = 0;
        HP = 100;
        task = 0; // 0 = stop, 1 = up, 2 = down, 3 = left, 4 = right
        hpleft;
        attack = 0;
        damage = 0;
        Death = 0;
        Alien.setHP(HP);
        Alien.setATK(ATK);
        curiosity.Alien(map);
    }
    else if (Mapsetting.getZ() == 1)
    {

        bool txt = true;
        cout << "load game" << endl;
        while (txt)
        {
            cout << "key in the file name want to load (.txt)=>";
            cin >> filename;
            myFile.open(filename, ios ::in); // read
            int n = 0;
            bool game;
            if (myFile.is_open())
            {
                txt = false;
                string line;
                int num;
                char ob; // element of obj
                int W;   // counting while save obj
                int a;
                int b;
                int wz; // counting while save zombie

                while (getline(myFile, line) && n < 30)
                {
                    Map map = Map(Mapsetting.getColumns(), Mapsetting.getRows());
                    ++n;
                    if (n == 3)
                    {
                        num = stoi(line);
                        Mapsetting.setColumns(num);
                    }
                    else if (n == 5)
                    {
                        num = stoi(line);
                        Mapsetting.setRows(num);
                        map.setdimX(Mapsetting.getColumns());
                        map.setdimY(Mapsetting.getRows());
                    }
                    else if (n == 8)
                    {
                        num = stoi(line);
                        curiosity.setx(num);
                    }
                    else if (n == 10)
                    {
                        num = stoi(line);
                        curiosity.sety(num);
                    }
                    else if (n == 12)
                    {
                        num = stoi(line);
                        Alien.setATK(num);
                    }
                    else if (n == 14)
                    {
                        num = stoi(line);
                        Alien.setHP(num);
                    }
                    else if (n == 15)
                    {
                        num = stoi(line);
                        Alien.setshield(num);
                    }
                    else if (n == 18)
                    {
                        num = stoi(line);
                        Mapsetting.setCount(num);
                        i = Mapsetting.getCount();
                    }
                    else if (n == 20)
                    {
                        num = stoi(line);
                        Array->setttleft(num);
                    }
                    else if (line == "zombie")
                    {
                        n = 30;
                        wz = 1;
                    }
                }
                while (getline(myFile, line) && n >= 30 && n < 223)
                {
                    ++n;

                    if (line == "obj")
                    {
                        n = 223;
                        W = 1;
                    }
                    else
                    {
                        if (wz == 1)
                        {
                            ++wz;
                            num = stoi(line);
                            Array[z].setX(num);
                        }
                        else if (wz == 2)
                        {
                            ++wz;
                            num = stoi(line);
                            Array[z].setY(num);
                        }
                        else if (wz == 3)
                        {
                            ++wz;
                            num = stoi(line);
                            Array[z].setATK(num);
                        }
                        else if (wz == 4)
                        {
                            ++wz;
                            num = stoi(line);
                            Array[z].setHP(num);
                        }
                        else if (wz == 5)
                        {
                            ++wz;
                            num = stoi(line);
                            Array[z].setATKRange(num);
                        }
                        else if (wz == 6)
                        {
                            num = stoi(line);
                            Array[z].setleft(num);
                            wz = 1;
                            ++z;
                        }
                    }
                }
                {
                    Map map = Map(Mapsetting.getColumns(), Mapsetting.getRows());
                    while (getline(myFile, line) && n >= 223)
                    {
                        ++n;
                        if (n > 223)
                        {
                            ob = line[0];

                            if (W == 1)
                            {
                                ++W;
                                a = stoi(line);
                                obj[o].setox(a);
                            }
                            else if (W == 2)
                            {
                                ++W;
                                b = stoi(line);
                                obj[o].setoy(b);
                            }
                            else if (W == 3)
                            {
                                obj[o].setoo(ob);
                                W = 1;
                                ++o;
                            }
                        }
                    }
                    obj[0].seto(o);
                }
            }
        }
        myFile.close();
        cout << "game continue" << endl;
        cout << "Press enter to continue ..." << endl;
        std::cin.get();
    }
    Map map = Map(Mapsetting.getColumns(), Mapsetting.getRows());
    map.setdimX(Mapsetting.getColumns());
    map.setdimY(Mapsetting.getRows());
    if (Mapsetting.getZ() == 1) // if load the geme
    {
        for (int r = 0; r < obj[0].geto(); r++)
        {
            map.setObject(obj[r].getox(), obj[r].getoy(), obj[r].getoo());
        }
        Mapsetting.setZ(0);
    }
    else
    {
        char Zombies[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; // restart game
        for (int s = 0; s < i; s++)
        {
            map.setObject(Array[s].getX(), Array[s].getY(), Zombies[s]);
        }
        curiosity.Alien(map);
    }
    map.display();
    cout << "=>";
    cout << "Alien:"
         << " "
         << "HP ="
         << " " << Alien.getHP() << " "
         << "ATK ="
         << " " << Alien.getATK() << " "
         << "Shield ="
         << " " << Alien.getshield() << endl;
    for (int s = 0; s < i; s++)
    {
        cout << "Zombie"
             << " " << s + 1 << ":"
             << " "
             << "HP ="
             << " "
             << Array[s].getHP() << " "
             << "ATK ="
             << " " << Array[s].getAtk() << " "
             << "range="
             << " " << Array[s].getAtkRange() << endl;
    }

    bool game = true;
    cout << "For all command, key in 'help'" << endl;
    while (game)
    {

        cout << "command=>";
        cin >> command;
        if (command == "up")
        {
            task = 1;
        }
        else if (command == "down")
        {
            task = 2;
        }
        else if (command == "left")
        {
            task = 3;
        }
        else if (command == "right")
        {
            task = 4;
        }
        else if (command == "arrow")
        {
            task = 5;
        }
        else if (command == "help")
        {
            task = 6;
        }
        else if (command == "save")
        {
            task = 7;
        }
        else if (command == "load")
        {
            task = 37;
        }
        else if (command == "quit")
        {
            task = 9;
        }
        else
        {
            cout << "unvalid command, please key in again" << endl;
            cin.clear();
        }

        while (task > 0)
        {
            int atk = Alien.getATK();
            int hp = Alien.getHP();
            int saveTask;
            map.display();
            if (attack == 1)
            {
                cout << "Zombie give Alien a damage of"
                     << " " << damage << endl;
                cout << "Press enter to continue ..." << endl;
                std::cin.get();
                if (Alien.getHP() <= 0)
                {
                    task = 0;
                    Death = 1;
                }
                attack = 0;
            }
            else if (attack == 2)
            {
                cout << "Zombie try to attack Alien but fail because Alien is too far away" << endl;
                cout << "Press enter to continue ..." << endl;
                std::cin.get();
                attack = 0;
            }
            else if (attack == 3)
            {
                cout << "Zombie try to attack Alien but the shield block the attack!" << endl;
                cout << "Press enter to continue ..." << endl;
                std::cin.get();
                cout << "The shield is broken" << endl;
                cout << "Press enter to continue ..." << endl;
                std::cin.get();
                attack = 0;
                Alien.setshield(0);
            }

            if (task < 17)
            {
                cout << "=>";
            }
            cout << "Alien:"
                 << " "
                 << "HP ="
                 << " " << Alien.getHP() << " "
                 << "ATK ="
                 << " " << Alien.getATK() << " "
                 << "Shield ="
                 << " " << Alien.getshield() << endl;

            for (int s = 0; s < i; s++)
            {
                if ((task == 17 || task == 18) && s == 0)
                {
                    cout << "=>";
                }
                else if (task == 19 && s == 1)
                {
                    cout << "=>";
                }
                else if (task == 20 && s == 2)
                {
                    cout << "=>";
                }
                else if (task == 21 && s == 3)
                {
                    cout << "=>";
                }
                else if (task == 22 && s == 4)
                {
                    cout << "=>";
                }
                else if (task == 23 && s == 5)
                {
                    cout << "=>";
                }
                else if (task == 24 && s == 6)
                {
                    cout << "=>";
                }
                else if (task == 25 && s == 7)
                {
                    cout << "=>";
                }
                else if (task == 26 && s == 8)
                {
                    cout << "=>";
                }
                cout << "Zombie"
                     << " " << s + 1 << ":"
                     << " "
                     << "HP ="
                     << " "
                     << Array[s].getHP() << " "
                     << "ATK ="
                     << " " << Array[s].getAtk() << " "
                     << "range="
                     << " " << Array[s].getAtkRange() << endl;
            }

            cout << "Press enter to continue ..." << endl;
            std::cin.get();

            if (Death == 1)
            {
                string title = "game over.txt";
                cout << "Alien death" << endl;
                ASCIIgameover(title);
                game = false;
                task = 0;
                break;
            }

            switch (task)
            {
            case 1:
                saveTask = task;
                cout << "command = up" << endl;
                curiosity.up(map, task);
                break;

            case 2:
                saveTask = task;
                cout << "command = down" << endl;
                curiosity.down(map, task);
                break;

            case 3:
                saveTask = task;
                cout << "command = left" << endl;
                curiosity.left(map, task);
                break;

            case 4:
                saveTask = task;
                cout << "command = right" << endl;
                curiosity.right(map, task);
                break;

            case 5:
                curiosity.arrow(map, task);
                break;

            case 6:
                curiosity.help(map, task);
                break;

            case 7:
            {

                for (int x = 1; x <= map.getDimX(); x++)
                {
                    for (int y = 1; y <= map.getDimY(); y++)
                    {
                        char obj = map.getObject(x, y);
                        if (obj == 'A')
                        {
                            curiosity.setTargetx(x);
                            curiosity.setTargety(y);
                        }
                    }
                }
                cout << "key in the file name to save (.txt)=>";
                while (true)
                {
                    cin >> filename;
                    if (filename == "game over.txt" || filename == "title.txt" || filename == "win.txt")
                    {
                        cout << "unvalid filename" << endl;
                        cin.clear();
                        cout << "key in the file name to save (.txt)=>";
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                myFile.open(filename, ios ::out); // write
                if (myFile.is_open())
                {
                    myFile << "MAp setting\n";
                    myFile << "Num of Colums\n";
                    myFile << Mapsetting.getColumns() << '\n';
                    myFile << "Num of Rows\n";
                    myFile << Mapsetting.getRows() << '\n';
                    myFile << "Alien stat\n";
                    myFile << "X_\n";
                    myFile << curiosity.getTargetx() << '\n';
                    myFile << "Y_\n";
                    myFile << curiosity.getTargety() << '\n';
                    myFile << "ATK\n";
                    myFile << Alien.getATK() << '\n';
                    myFile << "HP\n";
                    myFile << Alien.getHP() << '\n';
                    myFile << Alien.getshield() << '\n';
                    myFile << "Zombie stat\n";
                    myFile << "Num of zombie\n";
                    myFile << i << '\n';
                    myFile << "Zombie left\n";
                    myFile << Count << '\n';
                    myFile << "zombie\n";
                    myFile << " " << '\n';
                    for (int sv = 0; sv < i; sv++)
                    {
                        myFile << Array[sv].getX() << '\n';
                        myFile << Array[sv].getY() << '\n';
                        myFile << Array[sv].getAtk() << '\n';
                        myFile << Array[sv].getHP() << '\n';
                        myFile << Array[sv].getAtkRange() << '\n';
                        myFile << Array[sv].getleft() << '\n';
                    }
                    myFile << "obj" << '\n';
                    myFile << " " << '\n';
                    for (int x = 1; x <= map.getDimX(); x++)
                    {
                        for (int y = 1; y <= map.getDimY(); y++)
                        {
                            myFile << x << '\n';
                            myFile << y << '\n';
                            myFile << map.getObject(x, y) << '\n';
                        }
                    }
                    myFile.close();
                }
                task = 0;
            }
            break;

            case 8:
            {
                task = saveTask;
                int dis = 0;
                float minDis;
                for (int p = 0; p < zombie_count; p++)
                {
                    if (Array[p].getleft() == 0)
                    {
                        minDis = getDistance(curiosity.getX(), curiosity.getY(), Array[p].getX(), Array[p].getY());
                        p = zombie_count + 1;
                    }
                    else
                    {
                        // continue
                    }
                }
                for (int q = 0; q < zombie_count; q++)
                {
                    if (Array[q].getleft() == 1)
                    {
                    }
                    else if (q == 9)
                    {
                    }
                    else
                    {
                        float currDix = getDistance(curiosity.getX(), curiosity.getY(), Array[q].getX(), Array[q].getY());
                        if (currDix < minDis)
                        {
                            dis = q;
                            minDis = currDix;
                        }
                        else
                        {
                        }
                    }
                }
                hpleft = Array[dis].getHP() - 10;
                cout << "Pod give 10 damage to Zombie"
                     << " " << dis + 1 << endl;
                cout << "Press enter to continue ..." << endl;
                if (hpleft <= 0)
                {
                    cout << " Zombie"
                         << " " << dis + 1 << " "
                         << "defeated" << endl;
                    Array[dis].setHP(0);
                    Array[dis].setleft(1);
                    Count = Mapsetting.getCount() - 1;
                    Mapsetting.setCount(Count);
                }
                else
                {
                    Array[dis].setHP(hpleft);
                }
                std::cin.get();
            }
            break;

            case 9:
                curiosity.quit(map, task);
                if (task == 88)
                {
                    game = false;
                    task = 0;
                }
                else
                {
                    task = 0;
                }
                break;

            case 10:
            {
                task = saveTask;
                if (hp == 100)
                {
                    cout << "Alien's HP is already full" << endl;
                    cout << "Press enter to continue ..." << endl;
                    ;
                    std::cin.get();
                    break;
                }
                else if (hp >= 90 && hp < 100)
                {
                    cout << "Alien recovers 10HP, HP is full now!" << endl;
                    cout << "Press enter to continue ..." << endl;
                    std::cin.get();
                    Alien.setHP(100);
                    break;
                }
                else
                {
                    cout << "Alien recovers 10 HP" << endl;
                    cout << "Press enter to continue ..." << endl;
                    std::cin.get();
                    Alien.setHP(hp + 10);
                    break;
                }
            }
            break;

            case 11:
                cout << "it is a rock" << endl;
                curiosity.rock(map, task);
                break;

            case 12:
                cout << "reset trail with new object" << endl;
                cout << "reset Alien ATK to 0" << endl;
                Alien.setATK(0);
                cout << "Press enter to continue ..." << endl;
                std::cin.get();
                curiosity.trail(map, task);
                break;

            case 13:
            {
                task = 1;
                saveTask = task;
                Alien.setATK(atk + 20);
                cout << "command = up" << endl;
                cout << "Alien ATK increase 20" << endl;
                cout << "Press enter to continue ..." << endl;
                std::cin.get();
                curiosity.up(map, task);
            }
            break;

            case 14:
            {
                task = 2;
                saveTask = task;
                Alien.setATK(atk + 20);
                cout << "command = down" << endl;
                cout << "Alien ATK increase 20" << endl;
                cout << "Press enter to continue ..." << endl;
                std::cin.get();
                curiosity.down(map, task);
            }
            break;
            case 15:
            {
                task = 3;
                saveTask = task;
                Alien.setATK(atk + 20);
                cout << "command = left" << endl;
                cout << "Alien ATK increase 20" << endl;
                cout << "Press enter to continue ..." << endl;
                std::cin.get();
                curiosity.left(map, task);
            }
            break;
            case 16:
            {
                task = 4;
                saveTask = task;
                Alien.setATK(atk + 20);
                cout << "command = right" << endl;
                cout << "Alien ATK increase 20" << endl;
                cout << "Press enter to continue ..." << endl;
                std::cin.get();
                curiosity.right(map, task);
            }
            break;
            case 17:
            {
                Alien.setATK(0);
                task = 18;
            }
            case 18:
            {
                if (Array[0].getleft() == 0)
                {
                    cout << "Zombie1 turn" << endl;
                    cout << "Press enter to continue ..." << endl;
                    std::cin.get();
                    saveTask = task;
                    zombieturn = 1;
                }

                else if (Mapsetting.getCount() == 0)
                {

                    string title = "win.txt";
                    cout << "Win the game!" << endl;
                    ASCIIwin(title);
                    game = false;
                    task = 0;
                    break;
                }
                else
                {
                    saveTask = task;
                }
            }
            break;

            case 19:
            {
                if (Array[1].getleft() == 0)
                {
                    cout << "Zombie2 turn" << endl;
                    cout << "Press enter to continue ..." << endl;
                    std::cin.get();
                    saveTask = task;
                    zombieturn = 2;
                }
                else if (Mapsetting.getCount() == 0)
                {
                    string title = "win.txt";
                    cout << "Win the game!" << endl;
                    ASCIIwin(title);
                    game = false;
                    task = 0;
                    break;
                }
                else
                {
                    saveTask = task;
                }
            }
            break;

            case 20:
            {
                if (Array[2].getleft() == 0)
                {
                    cout << "Zombie3 turn" << endl;
                    cout << "Press enter to continue ..." << endl;
                    std::cin.get();
                    saveTask = task;
                    zombieturn = 3;
                }
                else if (Mapsetting.getCount() == 0)
                {
                    string title = "win.txt";
                    cout << "Win the game!" << endl;
                    ASCIIwin(title);
                    game = false;
                    task = 0;
                    break;
                }
                else
                {
                    saveTask = task;
                }
            }
            break;

            case 21:
            {
                if (Array[3].getleft() == 0)
                {
                    cout << "Zombie4 turn" << endl;
                    cout << "Press enter to continue ..." << endl;
                    std::cin.get();
                    saveTask = task;
                    zombieturn = 4;
                }
                else if (Mapsetting.getCount() == 0)
                {
                    string title = "win.txt";
                    cout << "Win the game!" << endl;
                    ASCIIwin(title);
                    game = false;
                    task = 0;
                    break;
                }
                else
                {
                    saveTask = task;
                }
            }
            break;

            case 22:
            {
                if (Array[4].getleft() == 0)
                {
                    cout << "Zombie5 turn" << endl;
                    cout << "Press enter to continue ..." << endl;
                    std::cin.get();
                    saveTask = task;
                    zombieturn = 5;
                }
                else if (Mapsetting.getCount() == 0)
                {
                    string title = "win.txt";
                    cout << "Win the game!" << endl;
                    ASCIIwin(title);
                    game = false;
                    task = 0;
                    break;
                }
                else
                {
                    saveTask = task;
                }
            }
            break;

            case 23:
            {
                if (Array[5].getleft() == 0)
                {
                    cout << "Zombie6 turn" << endl;
                    cout << "Press enter to continue ..." << endl;
                    std::cin.get();
                    saveTask = task;
                    zombieturn = 6;
                }
                else if (Mapsetting.getCount() == 0)
                {
                    string title = "win.txt";
                    cout << "Win the game!" << endl;
                    ASCIIwin(title);
                    game = false;
                    task = 0;
                    break;
                }
                else
                {
                    saveTask = task;
                }
            }
            break;

            case 24:
            {
                if (Array[6].getleft() == 0)
                {
                    cout << "Zombie7 turn" << endl;
                    cout << "Press enter to continue ..." << endl;
                    std::cin.get();
                    saveTask = task;
                    zombieturn = 7;
                }
                else if (Mapsetting.getCount() == 0)
                {
                    string title = "win.txt";
                    cout << "Win the game!" << endl;
                    ASCIIwin(title);
                    game = false;
                    task = 0;
                    break;
                }
                else
                {
                    saveTask = task;
                }
            }
            break;

            case 25:
            {
                if (Array[7].getleft() == 0)
                {
                    cout << "Zombie8 turn" << endl;
                    cout << "Press enter to continue ..." << endl;
                    std::cin.get();
                    saveTask = task;
                    zombieturn = 8;
                }
                else if (Mapsetting.getCount() == 0)
                {
                    string title = "win.txt";
                    cout << "Win the game!" << endl;
                    ASCIIwin(title);
                    game = false;
                    task = 0;
                    break;
                }
                else
                {
                    saveTask = task;
                }
            }
            break;

            case 26:
            {
                if (Array[8].getleft() == 0)
                {
                    cout << "Zombie9 turn" << endl;
                    cout << "Press enter to continue ..." << endl;
                    std::cin.get();
                    saveTask = task;
                    zombieturn = 9;
                }
                else if (Mapsetting.getCount() == 0)
                {
                    string title = "win.txt";
                    cout << "Win the game!" << endl;
                    ASCIIwin(title);
                    game = false;
                    task = 0;
                    break;
                }
                else
                {
                    saveTask = task;
                }
            }
            break;

            case 27:
            {
                cout << "round end" << endl;
                task = 0;
            }
            break;

            case 28:
            {
                Alienturn = 1;
                task = 38;
            }
            break;

            case 29:
            {
                Alienturn = 2;
                task = 38;
            }
            break;

            case 30:
            {
                Alienturn = 3;
                task = 38;
            }
            break;

            case 31:
            {
                Alienturn = 4;
                task = 38;
            }
            break;

            case 32:
            {
                Alienturn = 5;
                task = 38;
            }
            break;

            case 33:
            {
                Alienturn = 6;
                task = 38;
            }
            break;

            case 34:
            {
                Alienturn = 7;
                task = 38;
            }
            break;

            case 35:
            {
                Alienturn = 8;
                task = 38;
            }
            break;

            case 36:
            {
                Alienturn = 9;
                task = 38;
            }
            break;

            case 37:
            {
                string load;
                cout << "Is you already save the game?(y/n)=>";
                cin >> load;
                if (load == "y")
                {
                    game = false;
                    task = 0;
                    Mapsetting.setZ(1);
                }
                else if (load == "n")
                {
                    cout << "please save your game first" << endl;
                    task = 7;
                }
                else
                {
                    task = 0;
                }
            }
            break;

            case 38:
            {
                cout << "Alien meets a Zombie!" << endl;
                az = Alienturn - 1;
                hpleft = Array[az].getHP() - Alien.getATK();
                cout << "Alien give zombie" << az + 1 << " "
                     << "a damage of "
                     << " " << Alien.getATK() << endl;
                cout << "Press enter to continue... " << endl;
                std::cin.get();
                if (hpleft <= 0)
                {
                    cout << " Zombie" << az + 1 << "defeated" << endl;
                    Array[az].setHP(0);
                    Count = Mapsetting.getCount() - 1;
                    Mapsetting.setCount(Count);
                    Array[az].setleft(1);
                    task = saveTask;
                    map.setObject(curiosity.getTargetx(), curiosity.getTargety(), '.');
                    map.setObject(Array[az].getX(), Array[az].getY(), 'A');
                    curiosity.setx(Array[az].getX());
                    curiosity.sety(Array[az].getY());
                }
                else
                {
                    Array[az].setHP(hpleft);
                    task = 12;
                }
            }
            break;

            case 39:
            {
                task = saveTask;
                if (Alien.getshield() == 0)
                {
                    cout << "Alien equips a shield" << endl;
                    cout << "Press enter to continue... " << endl;
                    std::cin.get();
                    Alien.setshield(1);
                }
                else
                {
                    cout << "Alien could not equip more than one shield" << endl;
                    cout << "Press enter to continue... " << endl;
                    std::cin.get();
                }
            }
            break;
            }

            int xz;
            int yz;
            char Zom;
            if (task >= 18 && task < 27)
            {
                az = zombieturn - 1;
                xz = Array[az].getX();
                yz = Array[az].getY();
                Zom = map.getObject(xz, yz);
                if (i > zombieturn)
                {
                    task += 1;
                }
                else
                {
                    task = 27;
                }
            }
            if (task >= 18 && task <= 27)
            {
                int targetX = xz;
                int targetY = yz;
                int num = rand() % 4;
                switch (num)
                {
                case 0: // ^
                    targetY += 1;
                    cout << "Zombie want to move up" << endl;
                    cout << "Press enter to continue... " << endl;
                    std::cin.get();
                    break;

                case 1: // <
                    targetX -= 1;
                    cout << "Zombie want to move left" << endl;
                    cout << "Press enter to continue... " << endl;
                    std::cin.get();
                    break;

                case 2: // >
                    targetX += 1;
                    cout << "Zombie want to move right" << endl;
                    cout << "Press enter to continue... " << endl;
                    std::cin.get();
                    break;

                case 3: // v
                    targetY -= 1;
                    cout << "Zombie want to move down" << endl;
                    cout << "Press enter to continue... " << endl;
                    std::cin.get();
                    break;

                default:
                    break;
                }

                if (map.isInsideMap(targetX, targetY))
                {
                    char elm = map.getObject(targetX, targetY);
                    if (elm == 'A')
                    {
                        cout << "Zombie meets Alien and stop moving" << endl;
                        cout << "Press enter to continue... " << endl;
                        std::cin.get();
                    }
                    else if (elm == '1' || elm == '2' || elm == '3' || elm == '4' || elm == '5' || elm == '6' || elm == '7' || elm == '8' || elm == '9')
                    {
                        cout << "Zombie meets other zombie" << endl;
                        cout << "Press enter to continue... " << endl;
                        std::cin.get();
                        int boost = rand() % 2;
                        switch (boost)
                        {
                        case 0:
                        {
                            cout << "Zombie"
                                 << " " << zombieturn << " "
                                 << "gets a boost of 10 HP from other Zombie" << endl;
                            cout << "Press enter to continue... " << endl;
                            std::cin.get();
                            int HPboost = Array[az].getHP() + 10;
                            Array[az].setHP(HPboost);
                        }
                        break;
                        case 1:
                        {
                            cout << "Zombie"
                                 << " " << zombieturn << " "
                                 << "gets a boost of 5 ATK from other Zombie" << endl;
                            cout << "Press enter to continue... " << endl;
                            std::cin.get();
                            int ATKboost = Array[az].getAtk() + 5;
                            Array[az].setATK(ATKboost);
                        }
                        break;
                        }
                    }
                    else
                    {
                        map.setObject(xz, yz, ' '); // Remove old
                        xz = targetX;
                        yz = targetY;
                        map.setObject(xz, yz, Zom); // New
                    }
                }
                else
                {
                    cout << "zombie hit the wall angryly" << endl;
                    cout << "Press enter to continue... " << endl;
                    std::cin.get();
                }
                az = zombieturn - 1;
                Array[az].setX(xz);
                Array[az].setY(yz);
                distance = getDistance(curiosity.getX(), curiosity.getY(), Array[az].getX(), Array[az].getY());
                if (distance <= Array[az].getAtkRange())
                {
                    if (Alien.getshield() == 1)
                    {
                        attack = 3;
                    }
                    else
                    {
                        damage = Array[az].getAtk();
                        hpleft = Alien.getHP() - damage;
                        if (hpleft > 0)
                        {
                            Alien.setHP(hpleft);
                        }
                        else
                        {
                            Alien.setHP(0);
                        }
                        attack = 1;
                    }
                }
                else
                {
                    attack = 2;
                }
            }
        }
    }
}

void restart()
{
    string restart;
    bool game;
    bool rst = true;
    while (rst)
    {
        cout << "do you want to restart/load the game? y/n=>";
        cin >> restart;
        if (restart == "y")
        {
            cout << endl;
            cout << "you choose restart / load  the game " << endl;
            cout << " Press enter to continue... " << endl;
            std::cin.get();
            game = true;
            maingame();
        }
        else if (restart == "n")
        {
            cout << "see you again!" << endl;
            rst = false;
        }
        else
        {
            cout << "Please enter y/n only!" << endl;
            cout << "failed to restart the game" << endl;
        }
    }
}
int main()
{
    Mapsetting setting;
    setting.setZ(0);
    string title = "title.txt";
    cout << "Assignment (Part 2)" << endl;
    printASCII(title);
    cout << "Let's Get Started!" << endl;
    cout << "Press enter to continue ..." << endl;
    std::cin.get();
    // srand(1); // use this for fixed map during testing
    srand(time(NULL)); // try this for random map
    maingame();

    restart();
}