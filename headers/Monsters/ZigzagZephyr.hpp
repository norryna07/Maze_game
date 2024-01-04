//
// Created by Norina Alexandru on 11/19/2023.
// Zigzag Zephyr is another monster that moves in zigzag patterns.
//

#ifndef OOP_ZIGZAGZEPHYR_HPP
#define OOP_ZIGZAGZEPHYR_HPP
#define UP_LEFT 0
#define DOWN_RIGHT 1
#define Vertically 0
#define Orizontally 1


#include "../Monster.hpp"

/// \brief A type of monster that move in zigzag pattern.
class ZigzagZephyr : public Monster {
    static Cell_mode type;
    int x_dir, y_dir;
    bool direction;
    bool step = Vertically;

    void change_direction();

public:
    ZigzagZephyr(unsigned int x, unsigned int y, bool direction = UP_LEFT);

    void move(Maze &maze) override;
};

#endif //OOP_ZIGZAGZEPHYR_HPP
