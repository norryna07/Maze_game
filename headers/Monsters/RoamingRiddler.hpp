//
// Created by Norina Alexandru on 11/19/2023.
// hpp file for RoamingRiddler class. A type of monster that follow a fixed path.
//

#ifndef OOP_ROAMINGRIDDLER_HPP
#define OOP_ROAMINGRIDDLER_HPP

#include <vector>
#include <SFML/Graphics.hpp>


#include "../Monster.hpp"

/// \brief A type of monster that follow a fixed path in the maze.
class RoamingRiddler : public Monster {
    static Cell_mode type;
    unsigned int poz;
    int step;
    std::vector<sf::Vector2<unsigned int>> path;
public:
    RoamingRiddler(const std::vector<sf::Vector2<unsigned int>> &path);

    void move(Maze &maze) override;
};


#endif //OOP_ROAMINGRIDDLER_HPP
