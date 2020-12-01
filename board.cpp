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
    Cell empty = Cell();
    cout << empty.to_string();

    cells = vector<Cell>((width * height), empty);

    cout << "Board init as " << width << "x" << height << "\n";
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