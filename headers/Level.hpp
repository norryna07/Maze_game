//
// Created by Norina Alexandru on 11/23/2023.
// Level is a class that contain information about every level: player, maze, the monsters from the maze, score, etc.
//

#ifndef OOP_LEVEL_HPP
#define OOP_LEVEL_HPP


#include <vector>
#include <memory>
#include <chrono>
#include <thread>
#include "Monster.hpp"
#include "Player.hpp"
#include "SceneManager.hpp"


/// \brief Level class will store information about each level from game: maze, player and a vector of monsters.
class Level {
    Player player;
    Maze maze;
    std::vector<std::shared_ptr<Monster>> monsters;
    int score;
public:
    Level(int difficulty, int dimX, int dimY, const std::string &filename = "");

    void handleInput(sf::Event ev, sf::RenderWindow &window);
    void draw(sf::RenderWindow& window);
};


#endif //OOP_LEVEL_HPP
