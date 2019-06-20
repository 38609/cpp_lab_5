#include "item.h"
#include "space.h"

using namespace std;

void setNeighborNS(Space *p1, Space *p2) {
    p1->setNeighborS(p2);
    p2->setNeighborN(p1);
}

void setNeighborEW(Space *p1, Space *p2) {
    p1->setNeighborE(p2);
    p2->setNeighborW(p1);
}

int main() {
    char steps[23] = {
            'e',
            's',
            's',
            'w',
            'e',
            'n',
            'e',
            'e',
            's',
            'n',
            'n',
            's',
            'e',
            'e',
            'n',
            'e',
            'e',
            'w',
            'w',
            's',
            's',
            'e',
            'e'
    };

    char step;
    int randX;
    int countStep = 0;
    Space *rooms[18];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            rooms[i * 6 + j] = new Space(i, j);
        }
    }

    setNeighborEW(rooms[0], rooms[1]);
    setNeighborEW(rooms[3], rooms[4]);
    setNeighborEW(rooms[4], rooms[5]);
    setNeighborEW(rooms[6], rooms[7]);
    setNeighborEW(rooms[7], rooms[8]);
    setNeighborEW(rooms[8], rooms[9]);
    setNeighborEW(rooms[9], rooms[10]);
    setNeighborEW(rooms[12], rooms[13]);
    setNeighborEW(rooms[15], rooms[16]);
    setNeighborEW(rooms[16], rooms[17]);
    setNeighborNS(rooms[1], rooms[6]);
    setNeighborNS(rooms[2], rooms[8]);
    setNeighborNS(rooms[3], rooms[10]);
    setNeighborNS(rooms[5], rooms[11]);
    setNeighborNS(rooms[6], rooms[13]);
    setNeighborNS(rooms[8], rooms[14]);
    setNeighborNS(rooms[10], rooms[15]);
    setNeighborNS(rooms[11], rooms[17]);

    int counter = 0;
    cout << "\nPokoje bez przedmiotow:" << endl;
    for (int i = 0; i < 18; i++) {
        counter++;

        if (rooms[i]->getNeighborW() == nullptr && i == 6) {
            cout << 'X';
        }

        cout << '#';

        if (rooms[i]->getNeighborE() == nullptr && counter != 6) {
            cout << 'X';
        }

        if (counter == 6) {
            cout << endl;
            counter = 0;
        }
    }

    Item *item1 = new Item("A", 1);
    Item *item2 = new Item("B", 2);
    Item *item3 = new Item("C", 3);


    do {
        randX = rand() % 18;
    } while (rooms[randX]->checkItem());
    rooms[randX]->addItem(item1);

    do {
        randX = rand() % 18;
    } while (rooms[randX]->checkItem());
    rooms[randX]->addItem(item2);

    do {
        randX = rand() % 18;
    } while (rooms[randX]->checkItem());
    rooms[randX]->addItem(item3);

    cout << endl << "Znalezione pokoje:" << endl;

    Space *room = rooms[0];

    for (char i : steps) {
        step = i;
        countStep++;
        switch (step) {
            case 'e':
                room = room->getNeighborE();
                break;
            case 'n':
                room = room->getNeighborN();
                break;
            case 's':
                room = room->getNeighborS();
                break;
            case 'w':
                room = room->getNeighborW();
                break;
        }
        if (NULL != room->checkItem()) {

            cout << "Krok - " << countStep << " | Przedmiot: " << room->getItem()->getName() << endl;
        }
    }

    cout << endl << "Pokoje z przedmiotami:" << endl;

    for (int i = 0; i < 18; i++) {
        counter++;
        
        if (rooms[i]->getNeighborW() == nullptr && i == 6) {
            cout << 'X';
        }

        if (rooms[i]->checkItem()) {
            cout << rooms[i]->getItem()->getName()[0];
        } else {
            cout << '#';
        }

        if (rooms[i]->getNeighborE() == nullptr && counter != 6) {
            cout << 'X';
        }

        if (counter == 6) {
            cout << endl;
            counter = 0;
        }
    }
}
