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

class ZigzagZephyr: public Monster{
    static Cell_mode type;
    int x_dir, y_dir;
    bool direction;
    bool step = Vertically;
    void change_direction();
public:
    ZigzagZephyr(unsigned int x, unsigned int y, bool direction);

    void move(Maze &maze) override;
};

Cell_mode ZigzagZephyr::type = ZIGZAG_ZEPHYR;

#endif //OOP_ZIGZAGZEPHYR_HPP
