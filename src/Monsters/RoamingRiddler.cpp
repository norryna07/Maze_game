//
// Created by norin on 11/19/2023.
//

#include "../../headers/Monsters/RoamingRiddler.hpp"

RoamingRiddler::RoamingRiddler(const std::vector<sf::Vector2<unsigned int>> &path)
        : Monster(path[0].x, path[0].y), path(path) {
    poz = 0;
    step = 1;
}

void RoamingRiddler::move(Maze &maze) {
    maze.move(type, path[poz].x, path[poz].y, path[poz + step].x, path[poz + step].y);
    poz += step;
    if (poz == path.size() - 1  && step == 1) step = -1;
    else if (poz == 0 && step == -1) step = 1;
}


