/*
Borad file

This will have helper methods for the board, incl rendering

*/

#include "cell.cpp"
#include "board.h"
#include <vector>
#include <string>
#include <iostream>

#include "include/taskflow/taskflow.hpp"

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

Cell *Board::get_cell(const int x, const int y) {
    // Wrap around if it goes negative

    int new_x;
    int new_y;

    // For some reason the moduluo function didn't work for negative numbers?
    if(x < 0) {
        new_x = width + x;
    } else if(x >= width) {
        new_x = x - width;
    } else {
        new_x = x;
    }

    if(y < 0) {
        new_y = height + y;
    } else if(y >= height) {
        new_y = y - height;
    } else {
        new_y = y;
    }

    return &(cells[new_y * width + new_x]);
}

void Board::set_all(bool alive) {
    for(Cell &c : cells) {
        c.alive = alive;
    }
}


/*
void Board::update() {
    vector<Cell> cells_temp = cells;

    for(int i = 0; i < cells.size(); i++) {
        cells_temp[i].alive = this->cells[i].next();
    }

    cells = cells_temp;
} */


void Board::update() {
    tf::Taskflow taskflow; // Create a taskflow

    vector<Cell> cellsTemp = cells; // Create empty copy of cells array 

    tf::Task tasks[height * width]; // We're gonna make one task for each cell.
    
    
    for(int i = 0; i < cells.size(); i++) {
        // Create lambdas, one for each cell.

        auto task = [&cellsTemp, this, i] { cellsTemp[i].alive = this->cells[i].next(); };
        tasks[i] = taskflow.emplace(task);
    }

    tf::Executor executor;

    executor.run(taskflow);
    executor.wait_for_all();

    // Move over
    this->cells = cellsTemp;
}