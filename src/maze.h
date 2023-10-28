//
// Created by norin on 10/22/2023.
//

#ifndef OOP_MAZE_H
#define OOP_MAZE_H
#include <vector>
#include <string>
#include "cell.h"
#include <SFML/Graphics.hpp>
#include <ostream>

class maze {
    std::vector <std::vector <cell>> matrix;
    const int nr_lin, nr_col;
    const sf::Vector2u dim, dim_cell;
public:
    maze(int nrLin, int nrCol, int dimX, int dimY,const std::string& filename = "");
    ~maze() = default;
    void draw(sf::RenderWindow& window);
    bool move(cell_mode mod, int old_x, int old_y, int new_x, int new_y);
    inline bool inside(int x, int y);
    friend std::ostream &operator<<(std::ostream &os, const maze &maze);
};


#endif //OOP_MAZE_H
