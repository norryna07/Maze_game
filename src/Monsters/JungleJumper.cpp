//
// Created by Norina Alexandru on 11/19/2023.
// cpp file for JungleJumper class.
//

#include "../../headers/Monsters/JungleJumper.hpp"
#include "../../headers/Exceptions.hpp"
#include <iostream>

Cell_mode JungleJumper::type = JUNGLE_JUMPER;

JungleJumper::JungleJumper(unsigned int x, unsigned int y) : Monster(x, y) {
}

/// \brief The function move the Jungle Jumper 2 cells up or 2 cells down.
/// \param maze where the monster moves.
void JungleJumper::move(Maze &maze) {
    ///try to move up
    try {
        maze.move(type, x, y, x, y - 2);
        y -= 2;
        return;
    } catch (OutMatrixException &e) {
        std::cerr << "Cell:" << x << ' ' << y << ", error: " << e.what() << '\n';
    } catch (BlockedCellException &e) {
        std::cerr << "Cell:" << x << ' ' << y << ", error: " << e.what() << '\n';
    }
    ///try to move down
    try {
        maze.move(type, x, y, x, y + 2);
        y += 2;
    } catch (OutMatrixException &e) {
        std::cerr << "Cell:" << x << ' ' << y << ", error: " << e.what() << '\n';
    } catch (BlockedCellException &e) {
        std::cerr << "Cell:" << x << ' ' << y << ", error: " << e.what() << '\n';
    }
}

