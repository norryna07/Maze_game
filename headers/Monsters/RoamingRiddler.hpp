//
// Created by norin on 11/19/2023.
//

#ifndef OOP_ROAMINGRIDDLER_HPP
#define OOP_ROAMINGRIDDLER_HPP
#include <vector>
#include <SFML/Graphics.hpp>


#include "../Monster.hpp"

class RoamingRiddler : public Monster{
    static Cell_mode type;
    int poz;
    int step;
    std::vector <sf::Vector2<unsigned int>> path;
public:
    RoamingRiddler(const std::vector<sf::Vector2<unsigned int>> &path);

    void move(Maze &maze) override;
};


#endif //OOP_ROAMINGRIDDLER_HPP
