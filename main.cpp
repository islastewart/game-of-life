#include <iostream>
#include "board.cpp"
#include <stdlib.h>
#include "direction.h"
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

using namespace std;

int main() {
    Board b = Board(10, 10);

    b.set_all(false);
    b.get_cell(5,5)->setAlive(true);
    b.get_cell(4,5)->setAlive(true);
    b.get_cell(5,6)->setAlive(true);
    b.get_cell(5,4)->setAlive(true);
    b.get_cell(6,4)->setAlive(true);
    b.print();

    cout << "Starting in 5... \n";
    this_thread::sleep_for(5s);

    while(true) {

        b.update();
        b.print();

        this_thread::sleep_for(1s);
    }

    return 0;
}