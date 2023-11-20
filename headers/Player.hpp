//
// Created by Norina Alexandru on 10/28/2023.
// A class about the player, with a function that move the player when keys are press.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include "Maze.hpp"
#include <SFML/Graphics.hpp>


#include <iostream>

class Player {
    unsigned int x = 0, y = 0;
public:
    Player() = default;
    ~Player() = default;
    friend std::ostream &operator<<(std::ostream &os, const Player &player);
    void move(sf::RenderWindow& window, Maze& m);
};


#endif //OOP_PLAYER_H
