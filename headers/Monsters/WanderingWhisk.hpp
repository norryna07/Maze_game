//
// Created by Norina Alexandru on 11/19/2023.
// hpp file for WanderingWhisk class. A type of monster that change the direction on every step.
//

#ifndef OOP_WANDERINGWHISK_HPP
#define OOP_WANDERINGWHISK_HPP

#include "../Monster.hpp"

/// \brief A type of monster that move freely in the maze, changing direction at every step.
class WanderingWhisk : public Monster {
    static int x_dir[4];
    static int y_dir[4];
    static Cell_mode type;
public:
    WanderingWhisk(unsigned int x, unsigned int y);

    void move(Maze &maze) override;
};


#endif //OOP_WANDERINGWHISK_HPP
