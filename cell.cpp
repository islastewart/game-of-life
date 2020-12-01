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

void Cell::setX(int coord) {
    if(!coords_set) {
        x = coord;
        coords_set = true;
    }
}

void Cell::setY(int coord) {
    if(!coords_set) {
        y = coord;
        coords_set = true;
    }   
}

bool Cell::next() {
    // Process the game of life rules one by one

    /*
    Any live cell with two or three live neighbours survives.
    Any dead cell with three live neighbours becomes a live cell.
    All other live cells die in the next generation. Similarly, all other dead cells stay dead.
    */
   return false;


}