/*

Declares functionality of cells

*/
#ifndef CELL_H
#define CELL_H

#include <string>

class Cell {
    public:
        // Is this cell alive?
        bool alive;
        Cell();

        // Get string representation of this cell
        std::string to_string();
};

#endif