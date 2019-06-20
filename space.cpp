#include <iostream>
#include "space.h"

using namespace std;

Space::Space(int x, int y) {
    this->x = x;
    this->y = y;
}

Space *Space::getNeighborN() {
    return this->neighborN;
}

Space *Space::getNeighborW() {
    return this->neighborW;
}

Space *Space::getNeighborE() {
    return this->neighborE;
}

Space *Space::getNeighborS() {
    return this->neighborS;
}

void Space::setNeighborN(Space *neighbor) {
    this->neighborN = neighbor;
}

void Space::setNeighborW(Space *neighbor) {
    this->neighborW = neighbor;
}

void Space::setNeighborE(Space *neighbor) {
    this->neighborE = neighbor;
}

void Space::setNeighborS(Space *neighbor) {
    this->neighborS = neighbor;
}

void Space::addItem(Item *pItem) {
    this->item = pItem;
}

bool Space::checkItem() {
    return this->item != nullptr;
}

Item *Space::getItem() {
    return this->item;
}