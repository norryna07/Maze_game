//
// Created by norin on 10/22/2023.
//

#include "maze.h"
#include <fstream>

maze::maze(const int nrLin, const int nrCol, const int dimX, const int dimY, const std::string& filename) : nr_lin(nrLin), nr_col(nrCol),
                                                                               dim_x(dimX), dim_y(dimY), dim_cell_x(dimX/nrCol), dim_cell_y(dimY/nrLin) {
    matrix.resize(nr_lin, std::vector<cell>(nr_col));
    if (filename.empty()) {
        for (int i = 0; i < nr_lin; ++i)
            for (int j = 0; j < nr_col; ++j)
                matrix[i][j].setDimentions(i, j, dim_cell_x, dim_cell_y);
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
                matrix[i][j].setDimentions(i, j, dim_cell_x, dim_cell_y);
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
