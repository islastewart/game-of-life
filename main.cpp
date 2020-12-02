#include <iostream>
#include "board.cpp"
#include <stdlib.h>
#include "direction.h"
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

using namespace std;

class Coord {
    public:
        int x;
        int y;

        Coord(int a, int b) {
            x = a;
            y = b;
        };
};

int main() {
    Board b = Board(100, 40);

    b.set_all(false);

    Coord c[] = {
        Coord(5,5),
        Coord(6,5),
        Coord(7,5),
        Coord(7,4),
        Coord(6,3)
    };

    for(Coord coord : c) {
        b.get_cell(coord.x, coord.y)->setAlive(true);
    }

    b.print();

    cout << b.get_cell(4,4)->num_adj() << "\n";
    cout << b.get_cell(4,4)->next();

    cout << "Starting in 10... \n";
    this_thread::sleep_for(10s);

    while(true) {
        cout << "------------------------------------\n";
        b.update();
        b.print();
    }

    return 0;
    
}