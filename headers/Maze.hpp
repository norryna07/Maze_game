//
// Created by Norina Alexandru on 10/22/2023.
// A class that contain graphic information about a maze in game.
//

#ifndef OOP_MAZE_H
#define OOP_MAZE_H
#include <vector>
#include <string>
#include "Cell.hpp"
#include <SFML/Graphics.hpp>
#include <ostream>

class Maze {
    std::vector <std::vector <Cell>> matrix;
    const int nr_lin, nr_col;
    const sf::Vector2u dim, dim_cell;
public:
    Maze(int nrLin, int nrCol, int dimX, int dimY,const std::string& filename = "");
    ~Maze() = default;
    void draw(sf::RenderWindow& window);
    bool move(Cell_mode mod, int old_x, int old_y, int new_x, int new_y);
    inline bool inside(int x, int y);
    inline bool free_cell(int x, int y);
    friend std::ostream &operator<<(std::ostream &os, const Maze &maze);
};


#endif //OOP_MAZE_H
