//
// Created by norin on 10/22/2023.
//

#ifndef OOP_MAZE_H
#define OOP_MAZE_H
#include <vector>
#include <string>
#include "cell.h"
#include <SFML/Graphics.hpp>


class maze {
    std::vector <std::vector <cell>> matrix;
    const int nr_lin, nr_col;
    const int dim_x, dim_y;
    const int dim_cell_x, dim_cell_y;
public:
    maze(const int nrLin, const int nrCol, const int dimX, const int dimY,const std::string& filename = "");
    ~maze() = default;
    void draw(sf::RenderWindow& window);

};


#endif //OOP_MAZE_H
