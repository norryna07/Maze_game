//
// Created by norin on 11/19/2023.
//

#include "../../headers/Monsters/JungleJumper.hpp"

JungleJumper::JungleJumper(unsigned int x, unsigned int y) : Monster(x, y) {
}

/// \brief The function move the Jungle Jumper 2 cells up or 2 cells down.
/// \param maze where the monster moves.
void JungleJumper::move(Maze &maze) {
    ///try to move up
    if (maze.inside(x, y - 2)) {
        maze.move(type, x, y, x, y - 2);
        y -= 2;
    }
    else if (maze.inside(x, y + 2)) {
        maze.move(type, x, y, x, y + 2);
        y += 2;
    }
}

