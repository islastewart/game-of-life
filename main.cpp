#include <iostream>
#include "board.cpp"
#include <stdlib.h>
using namespace std;

int main() {
    Board b = Board(20, 15);
    b.print();

    b.cells[2].alive = true;
    b.print();
}