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
        Cell() {};
        Cell(Board *);

        // Get string representation of this cell
        std::string to_string();

        // Set status of cell after the next turn
        bool next();
        void setX(int o);
        void setY(int o);

    private:
        // Private ref to board that this is a part of
        Board *board;
        int x = 0;
        int y = 0;
        bool coords_set = false;

    
};

#endif