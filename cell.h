/*

Declares functionality of cells

*/
#ifndef CELL_H
#define CELL_H

#include <string>

// Foward reference :)
class Board;

class Cell {
    public:
        // Is this cell alive?
        bool alive;
        Cell(Board *);

        // Get string representation of this cell
        std::string to_string();

    private:
        // Private ref to board that this is a part of
        Board *board;
};

#endif