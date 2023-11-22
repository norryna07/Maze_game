//
// Created by Norina Alexandru on 11/23/2023.
// Level is a class that contain information about every level: player, maze, the monsters from the maze, score, etc.
//

#ifndef OOP_LEVEL_HPP
#define OOP_LEVEL_HPP


#include "Player.hpp"
#include <vector>
#include <memory>
#include "Monster.hpp"
#define FactorDifficulty 5


class Level {
    Player player;
    Maze maze;
    std::vector <std::shared_ptr<Monster>> monsters;
    int score;
    int difficulty;
public:
    Level(int difficulty, int dimX, int dimY, const std::string& filename = "");
    void update(sf::RenderWindow& window);
};


#endif //OOP_LEVEL_HPP
