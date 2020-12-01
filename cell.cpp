/*
Defines functionality of cells

*/
#include <string>
#include "cell.h"

using namespace std;


Cell::Cell(Board *b) {
    alive = false;
    board = b;
};

string Cell::to_string() {
    if(alive) {
        return  "1";
    } else {
        return "0";
    };
};