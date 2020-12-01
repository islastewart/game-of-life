/*

Holds the direction enumerated type and Delta move type

*/

#ifndef DIRECTION_H
#define DIRECTION_H


enum class Direction {
    North,
    South,
    East,
    West,
    North_East,
    North_West,
    South_East,
    South_West,
    END,
} dir;

Direction& operator ++ (Direction& e)
{
    if (e == Direction::END) {
        throw std::out_of_range("for E& operator ++ (E&)");
    }
    e = Direction(static_cast<std::underlying_type<Direction>::type>(e) + 1);
    return e;
}

struct Delta{
    int deltaX;
    int deltaY;
    Delta(int x, int y) {deltaX = x; deltaY = y;}
};

// Return a deltaX, deltaY struct based on the direction given
static Delta delta(Direction d) {
    switch (d) {
        case (Direction::North):
            return Delta(0, -1);
        case (Direction::South):
            return Delta(0, 1);
        case (Direction::East):
            return Delta(1, 0);
        case (Direction::West):
            return Delta(-1, 0);
        case (Direction::North_East):
            return Delta(1, -1);
        case (Direction::North_West):
            return Delta(-1, -1);
        case (Direction::South_East):
            return Delta(1, 1);
        case (Direction::South_West):
            return Delta(-1, 1);
        default:
            throw "Direction not defined";
    }
}

#endif