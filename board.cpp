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
        add_cell(Cell(this));
        cout << "added";
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
}

void Board::add_cell(Cell c) {
    int size = cells.size();

    int x = size % height;
    int y = size / width;

    c.setX(x);
    c.setY(y);

    cells.resize(size + 1);
    cells[size] = c;
}