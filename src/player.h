//
// Created by norin on 10/28/2023.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include "maze.h"
#include <SFML/Graphics.hpp>


#include <iostream>

class player {
    int x = 0, y = 0;
public:
    player() = default;
    ~player() = default;
    friend std::ostream &operator<<(std::ostream &os, const player &player);
    void move(sf::RenderWindow& window, maze& m);
};


#endif //OOP_PLAYER_H
