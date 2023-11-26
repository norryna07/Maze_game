//
// Created by Norina Alexandru on 11/19/2023.
// hpp file for BlinkingBanshee class. A type of monster that teleport on random position in the maze.
// This monster has a range of 2 blocks.
//

#ifndef OOP_BLINKINGBANSHEE_HPP
#define OOP_BLINKINGBANSHEE_HPP

#include <random>
#include "../Monster.hpp"
#include <SFML/Graphics.hpp>

/// \brief A type of monster that use teleportation to reach other cells in maze. He has a range of 2 cells.
class BlinkingBanshee : public Monster {
    static Cell_mode type;
    static int x_dir[12];
    static int y_dir[12];
public:
    BlinkingBanshee(unsigned int x, unsigned int y);

    void move(Maze &maze) override;
};


#endif //OOP_BLINKINGBANSHEE_HPP
