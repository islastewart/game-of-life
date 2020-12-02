/*
Defines functionality of cells

*/
#include <string>
#include "cell.h"
#include "board.h"

using namespace std;




Cell::Cell(Board *b) {
    alive = false;
    board = b;
};

string Cell::to_string() {
    if(alive) {
        return  "#";
    } else {
        return " ";
    };
};

void Cell::setX(int coord) {
    if(!x_set) {
        this->x = coord;
        x_set = true;
    }
}

void Cell::setY(int coord) {
    if(!y_set) {
        this->y = coord;
        y_set = true;
    }   
}

Cell *Cell::get_adj(Direction d) {
    // Get the cell in the direction, return null if does not exist
    Delta del = delta(d); // Get the Delta struct assocated with this direction
    return board->get_cell(x + del.deltaX, y + del.deltaY);
}

// Get next state of this sell. Returns false if dead, returns true if alive
bool Cell::next() {
    // Process the game of life rules one by one

    /*
    Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    Any live cell with two or three live neighbours lives on to the next generation.
    Any live cell with more than three live neighbours dies, as if by overpopulation.
    Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    */
   int num_neighbours = this->num_adj();

   if(this->alive) {
       if(num_neighbours < 2) {
           return false;
       } else if(num_neighbours == 2 || num_neighbours == 3) {
           return true;
       } else {
           return false;
       }
   } else {
       if(num_neighbours == 3) {
           return true;
       } else {
           return false;
       }
   }
}

// Set alive status of this cell
void Cell::setAlive(bool alive) {
    this->alive = alive;
}

int Cell::num_adj() {
    int count = 0;
    for(Direction d = Direction::North; d != Direction::END; ++d) {
        Cell *adj = get_adj(d);

        if(adj != nullptr) {
          if(get_adj(d)->alive) {
                count++;
            }
        }
    };

    return count;
}