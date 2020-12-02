#include <iostream>
#include "board.cpp"
#include <stdlib.h>
#include "direction.h"
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <task
using namespace std;

int main() {
    Board b = Board(100, 50);

    b.set_all(false);
    b.get_cell(50,25)->setAlive(true);
    b.get_cell(49,25)->setAlive(true);
    b.get_cell(50,26)->setAlive(true);
    b.get_cell(50,24)->setAlive(true);
    b.get_cell(51,24)->setAlive(true);
    b.print();

    cout << b.get_cell(4,4)->num_adj() << "\n";
    cout << b.get_cell(4,4)->next();

    cout << "Starting in 10... \n";
    this_thread::sleep_for(10s);

    while(true) {

        b.update();
        b.print();

        this_thread::sleep_for(0.2s);
    }

    return 0;
}