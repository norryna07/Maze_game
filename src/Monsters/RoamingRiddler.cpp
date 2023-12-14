//
// Created by Norina Alexandru on 11/19/2023.
// cpp file for RoamingRiddler class.
//

#include "../../headers/Monsters/RoamingRiddler.hpp"

Cell_mode RoamingRiddler::type = ROAMING_RIDDLER;

/// \brief Constructor for RoamingRiddler
/// \param path the fixed path of the Monster
RoamingRiddler::RoamingRiddler(const std::vector<sf::Vector2<unsigned int>> &path)
        : Monster(path[0].x, path[0].y), path(path) {
    poz = 0;
    step = 1;
}

/// \brief Move function for RoamingRiddler, move forward on the path.
/// \param maze the maze where the monster moves
void RoamingRiddler::move(Maze &maze) {
    try {
        maze.move(type, path[poz].x, path[poz].y, path[poz + step].x, path[poz + step].y);
        poz += step;
        if (poz == path.size() - 1 && step == 1) step = -1;
        else if (poz == 0 && step == -1) step = 1;
    } catch (OutMatrixException &e) {
        std::cerr << "Cell:" << path[poz + step].x << ' ' << path[poz + step].y << ", error: " << e.what() << '\n';
    } catch (BlockedCellException &e) {
        std::cerr << "Cell:" << path[poz + step].x << ' ' << path[poz + step].y << ", error: " << e.what() << '\n';
    }
}


