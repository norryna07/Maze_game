//
// Created by norin on 11/19/2023.
//

#include "../../headers/Monsters/ZigzagZephyr.hpp"

Cell_mode ZigzagZephyr::type = ZIGZAG_ZEPHYR;

ZigzagZephyr::ZigzagZephyr(unsigned int x, unsigned int y, bool direction) : Monster(x, y), direction(direction) {
    if (direction == UP_LEFT) x_dir = -1, y_dir = -1;
    else x_dir = 1, y_dir = 1;

}

void ZigzagZephyr::move(Maze &maze) {
    if (step == Vertically)
    {
        if (maze.inside(x, y + y_dir) && maze.free_cell(x, y + y_dir))
        {
                maze.move(type, x, y, x, y + y_dir);
                y += y_dir;
                step = Orizontally;
                return;
        }
        change_direction();
        return;
    }
    else {
        if (maze.inside(x + x_dir, y) && maze.free_cell(x + x_dir, y)) {
            maze.move(type, x, y, x + x_dir, y);
            x += x_dir;
            step = Vertically;
            return;
        }
        change_direction();
        return;

    }
}

void ZigzagZephyr::change_direction() {
    if (direction == UP_LEFT) {
        direction = DOWN_RIGHT;
        x_dir = 1;
        y_dir = 1;
    }
    else {
        direction = UP_LEFT;
        x_dir = -1;
        y_dir = -1;
    }
}
