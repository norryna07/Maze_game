//
// Created by norin on 11/19/2023.
//

#ifndef OOP_WANDERINGWHISK_HPP
#define OOP_WANDERINGWHISK_HPP
#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

#include "../Monster.hpp"
class WanderingWhisk : public Monster{
    static int x_dir[4];
    static int y_dir[4];
    static Cell_mode type;
public:
    WanderingWhisk(unsigned int x, unsigned int y);
    void move(Maze &maze) override;
};


#endif //OOP_WANDERINGWHISK_HPP
