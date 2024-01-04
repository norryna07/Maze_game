//
// Created by Norina Alexandru on 11/19/2023.
// cpp file for BlinkingBanshee class.
//

#include "../../headers/Monsters/BlinkingBanshee.hpp"
#include "../../headers/Exceptions.hpp"
#include <iostream>

Cell_mode BlinkingBanshee::type = BLINKING_BANSHEE;
int BlinkingBanshee::x_dir[12] = {0, -1, 0, 1, -2, -1, 1, 2, -1, 0, 1, 0};
int BlinkingBanshee::y_dir[12] = {-2, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 2};

/// \brief Constructor for BlinkingBanshee
/// \param x initial x coordinate
/// \param y initial y coordinate
BlinkingBanshee::BlinkingBanshee(unsigned int x, unsigned int y) : Monster(x, y) {}

/// \brief the move function for BlinkingBanshee. At every move will choice a random free cell from his proximity and will go there.
/// \param maze the maze where the monster moves
void BlinkingBanshee::move(Maze &maze) {
    int poz[12];
    int nr_poz = 0;
    for (int i = 0; i < 12; ++i) {
        try {
            maze.inside(x + x_dir[i], y + y_dir[i]);
            maze.free_cell(x + x_dir[i], y + y_dir[i]);
        } catch (OutMatrixException &e) {
            std::cerr << "Cell:" << x << ' ' << y << ", error: " << e.what() << '\n';
            continue;
        } catch (BlockedCellException &e) {
            std::cerr << "Cell:" << x << ' ' << y << ", error: " << e.what() << '\n';
            continue;
        }
        poz[nr_poz++] = i;
    }
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int pos = std::rand() % nr_poz;
    pos = poz[pos];

    maze.move(type, x, y, x + x_dir[pos], y + y_dir[pos]);
    x += x_dir[pos];
    y += y_dir[pos];

}

