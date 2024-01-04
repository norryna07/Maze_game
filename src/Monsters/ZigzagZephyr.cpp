//
// Created by Norina Alexandru on 11/19/2023.
// cpp file for ZigzagZephyr class.
//

#include "../../headers/Monsters/ZigzagZephyr.hpp"
#include "../../headers/Exceptions.hpp"
#include <iostream>

Cell_mode ZigzagZephyr::type = ZIGZAG_ZEPHYR;

/// \brief Constructor for ZigzagZephyr
/// \param x initial x coordinate
/// \param y initial y coordinate
/// \param direction UP_LEFT or DOWN_RIGHT
ZigzagZephyr::ZigzagZephyr(unsigned int x, unsigned int y, bool direction) : Monster(x, y), direction(direction) {
    if (direction == UP_LEFT) x_dir = -1, y_dir = -1;
    else x_dir = 1, y_dir = 1;

}

/// \brief the move function for ZigzagZephyr monster. At every step will move a cell in zigzag direction(up_left or down_right).
/// \param maze the maze where the monster moves
void ZigzagZephyr::move(Maze &maze) {
    if (step == Vertically) {
        try {
            maze.move(type, x, y, x, y + y_dir);
            y += y_dir;
            step = Orizontally;
            return;

        } catch (OutMatrixException &e) {
            std::cerr << "Cell:" << x << ' ' << y << ", error: " << e.what() << '\n';
            change_direction();
            return;
        } catch (BlockedCellException &e) {
            std::cerr << "Cell:" << x << ' ' << y << ", error: " << e.what() << '\n';
            change_direction();
            return;
        }
    } else {
        try {
            maze.move(type, x, y, x + x_dir, y);
            x += x_dir;
            step = Vertically;
            return;
        } catch (OutMatrixException &e) {
            std::cerr << "Cell:" << x << ' ' << y << ", error: " << e.what() << '\n';
            change_direction();
            return;
        } catch (BlockedCellException &e) {
            std::cerr << "Cell:" << x << ' ' << y << ", error: " << e.what() << '\n';
            change_direction();
            return;
        }
    }

}

void ZigzagZephyr::change_direction() {
    if (direction == UP_LEFT) {
        direction = DOWN_RIGHT;
        x_dir = 1;
        y_dir = 1;
    } else {
        direction = UP_LEFT;
        x_dir = -1;
        y_dir = -1;
    }
}
