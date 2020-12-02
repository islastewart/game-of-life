/*
Borad file

This will have helper methods for the board, incl rendering

*/
#include "cell.cpp"
#include "board.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Board::Board(int w, int h) {
    width = w;
    height = h;
    // Initialise empty vector of dead cells of appropriate length
    cells = vector<Cell>();

    cout << "Board init as " << width << "x" << height << "\n";

    for(int i = 0; i < width * height; i++) {
        new_cell();
    }
};

// Generate and print the board.
void Board::print() {
    for(int index = 0; index < cells.size(); ++index) {
        Cell cell = cells[index];

        cout << cell.to_string();
        
        if(((index + 1) % width) == 0) {
            cout << "\n";
        }
    }
    cout << "\n";
}

// Add cell to board, set the cell's coords
void Board::new_cell() {
    Cell c = Cell(this);
    int size = cells.size();

    int x = size % width;
    int y = size / width;

    c.setX(x);
    c.setY(y);

    cells.resize(size + 1);
    cells[size] = c;
}

Cell *Board::get_cell(int x, int y) {
    // Boundary Check
    if(x < 0 || x >= width) {
        return nullptr;
    }

    if(y < 0 || y >= height) {
        return nullptr;
    }

    return &(cells[y * width + x]);
}

void Board::set_all(bool alive) {
    for(Cell &c : cells) {
        c.alive = alive;
    }
}

void Board::update() {
    // Create empty copy of cells array 
    vector<Cell> cellsTemp = cells;
    for(int i = 0; i < cells.size(); i++) {
        Cell original_cell = cells[i];
        bool next_state = original_cell.next();

        // Update in copy
        cellsTemp[i].alive = next_state;
    }

    // Move over
    this->cells = cellsTemp;
}