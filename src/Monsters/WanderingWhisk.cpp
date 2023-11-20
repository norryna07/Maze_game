//
// Created by norin on 11/19/2023.
//

#include "../../headers/Monsters/WanderingWhisk.hpp"

int WanderingWhisk::x_dir[4] = {0, 0, -1, 1};
int WanderingWhisk::y_dir[4] = {-1, 1, 0, 0};
Cell_mode WanderingWhisk::type = WANDERING_WHISK;

WanderingWhisk::WanderingWhisk(unsigned int x, unsigned int y) : Monster(x, y) {}

void WanderingWhisk::move(Maze &maze) {
    int values[4];
    int nr_values = 0;
    for (int i = 0; i < 4; ++i)
        if (maze.inside(x + x_dir[i], y + y_dir[i]) &&
            maze.free_cell(x + x_dir[i], y + y_dir[i])) {
            values[++nr_values] = i;
        }
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int value = std::rand() % nr_values;
    value = values[value];

    maze.move(type, x, y, x + x_dir[value], y + y_dir[value]);
    x += x_dir[value];
    y += y_dir[value];
}
