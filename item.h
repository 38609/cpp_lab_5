#include <string>

using namespace std;

#ifndef Z5S_ITEM_H
#define Z5S_ITEM_H

class Item {
public:
    string name;
    int value;

    Item(string, int);

    string getName();
};

#endif