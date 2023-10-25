//
// Created by norin on 10/22/2023.
//

#include "maze.h"
#include <fstream>
#include <iostream>

maze::maze(const int nrLin, const int nrCol, const int dimX, const int dimY, const std::string& filename) : nr_lin(nrLin), nr_col(nrCol),
                                                                               dim(dimX, dimY), dim_cell(dimX/nrCol, dimY/nrLin) {
    matrix.resize(nr_lin, std::vector<cell>(nr_col));
    if (filename.empty()) {
        for (int i = 0; i < nr_lin; ++i)
            for (int j = 0; j < nr_col; ++j)
                matrix[i][j].setDimentions(i, j, dim_cell.x, dim_cell.y);
    }
    else {
        std::ifstream fin(filename);
        bool wall;
        for (int i = 0; i < nr_lin; ++i)
            for (int j = 0; j < nr_col; ++j)
            {
                fin >> wall;
                cell_mode mod;
                if (wall == 1) mod = WALL;
                else mod = FREE;
                matrix[i][j].setDimentions(i, j, dim_cell.x, dim_cell.y);
                matrix[i][j].setMode(mod);
            }
    }
    //set player
    matrix[0][0].setMode(PLAYER);
}

void maze::draw(sf::RenderWindow &window) {
    for (int i = 0; i < nr_lin; ++i)
        for (int j = 0; j < nr_col; ++j)
            window.draw(matrix[i][j].getRect());
}

std::ostream &operator<<(std::ostream &os, const maze &maze) {
    os << " nr_lin: " << maze.nr_lin << " nr_col: " << maze.nr_col << " dim_x: "
       << maze.dim.x << " dim_y: " << maze.dim.y << " dim_cell_x: " << maze.dim_cell.x << " dim_cell_y: "
       << maze.dim_cell.y << '\n';
    for (auto it_l = maze.matrix.begin(); it_l != maze.matrix.end(); ++it_l) {
        for (auto it_c = it_l->begin(); it_c != it_l->end(); ++it_c)
            os << it_c->getMode() << ' ';
        os << '\n';
    }
    return os;
}

