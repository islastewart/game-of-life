/*

Declares functionality of cells

*/
#ifndef CELL_H
#define CELL_H

#include <string>
#include "direction.h"

// Foward reference :)
class Board;

class Cell {
    public:
        // Is this cell alive?
        bool alive;
        Cell() {};
        Cell(Board *);

        // Get string representation of this cell
        std::string to_string();

        // Set status of cell after the next turn
        bool next();
        void setX(int o);
        void setY(int o);

        // Get the cell in the adjacent direction
        Cell *get_adj(Direction d);

        // Get the quantity of neighbours
        int num_adj();

        // Set alive status
        void setAlive(bool alive);

    private:
        // Private ref to board that this is a part of
        Board *board;
        int x = 0;
        int y = 0;
        bool x_set = false;
        bool y_set = false;

    
};

#endif