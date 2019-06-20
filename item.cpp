#include "item.h"

using namespace std;

Item::Item(string name, int value) {
    this->name = move(name);
    this->value = value;
}

string Item::getName() {
    return this->name;
}