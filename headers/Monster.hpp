//
// Created by Norina Alexandru on 11/19/2023.
// This will be an abstract class for all monsters that can be find in maze.

#ifndef OOP_MONSTER_HPP
#define OOP_MONSTER_HPP
#include "Textures.hpp"
#include "Maze.hpp"

/// \brief Abstract class for monsters from maze.
class Monster {
protected:
    unsigned int x, y;
public:
    Monster(unsigned int x, unsigned int y);
    virtual ~Monster() = default;
    virtual void move(Maze &maze) = 0;
};



#endif //OOP_MONSTER_HPP
