/*
Handles the board file.

*/
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "cell.h"

class Board {
    public:
        long width;
        long height;
        std::vector<Cell> cells;
    
        Board(int width, int height);

        // Generate and print the board.
        void print();

        // Update the board and execute the rules associated with
        // the game of life.
        void update();

    private:
        // Add cell to board
        void add_cell(Cell c);
};

#endif