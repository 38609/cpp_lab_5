#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "item.h"

#ifndef Z5_SPACE_H
#define Z5_SPACE_H

using namespace std;

class Space {
public:
    Space(int, int);

    Space *getNeighborN();

    Space *getNeighborE();

    Space *getNeighborS();

    Space *getNeighborW();

    void setNeighborN(Space *);

    void setNeighborE(Space *);

    void setNeighborS(Space *);

    void setNeighborW(Space *);

    bool checkItem();

    void addItem(Item *);

    Item *getItem();

private:
    string description;
    int x;
    int y;
    Space *neighborN = nullptr;
    Space *neighborE = nullptr;
    Space *neighborS = nullptr;
    Space *neighborW = nullptr;
    Item *item = nullptr;
};

#endif