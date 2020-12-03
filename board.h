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

        // Update cudaFlow
        void cuda_update();

        // Get cell at coord, or return null if doesn't exist
        Cell *get_cell(int x, int y);

        // Set alive status of all cells
        void set_all(bool alive);
    private:
        // Add cell to board
        void new_cell();
};

#endif