//
// Created by Norina Alexandru on 10/22/2023.
// Cpp file for Maze class.
//

#include "../headers/Maze.hpp"


/// \brief Constructor for maze class. Create a maze with nrLin rows, nrCol columns and with the shape found in filename, putting always the player on (0,0) position.
/// \param nrLin - number of rows
/// \param nrCol - number of columns
/// \param dimX - dimension on X axis
/// \param dimY - dimension on Y axis
/// \param filename - a path to a file where is a matrix that contain just 0 and 1 values: \n   0 - a free cell, 1 - a wall cell
Maze::Maze(const int nrLin, const int nrCol, const int dimX, const int dimY, const std::string &filename) : nr_lin(
        nrLin), nr_col(nrCol),dim(dimX,dimY),dim_cell(dimX /nrCol,dimY /nrLin) {
    matrix.resize(nr_lin, std::vector<Cell>(nr_col)); ///resize the matrix
    if (filename.empty()) { ///if the filename is empty will create a maze where all cells are free.
        for (int i = 0; i < nr_lin; ++i)
            for (int j = 0; j < nr_col; ++j)
                matrix[i][j].setDimensions(i, j, dim_cell.x, dim_cell.y);
    } else {
        std::ifstream fin(filename);
        int type;
        for (int i = 0; i < nr_lin; ++i)
            for (int j = 0; j < nr_col; ++j) {
                fin >> type;
                Cell_mode mod = (Cell_mode) type;
                matrix[i][j].setDimensions(i, j, dim_cell.x, dim_cell.y);
                matrix[i][j].setMode(mod);
            }

        fin.close();
    }
    //set player
    matrix[0][0].setMode(PLAYER);
    //set finish
    matrix[nr_lin-1][nr_col-1].setMode(FINISH);
}

/// \brief display on an SFML windows the maze.
/// \param window - a reference to a RenderWindow object
void Maze::draw(sf::RenderWindow &window) {
    for (int i = 0; i < nr_lin; ++i)
        for (int j = 0; j < nr_col; ++j)
            window.draw(matrix[i][j].getRect());
}

/// \brief Overwrite the operator << for display to the output information about the maze, and a description of the maze's matrix: 0 will represent free cells, 1 wall cells and 2 the player cell.
/// \param os - ostream reference
/// \param maze - the maze object
/// \return ostream reference after modifications
std::ostream &operator<<(std::ostream &os, const Maze &maze) {
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

/// \brief A bool function that verify if a cell is inside the maze's matrix.
/// \param x - coordinate on X axis
/// \param y - coordinate on Y axis
bool Maze::inside(int x, int y) {
    if (x < 0) throw OutMatrixException("negative x coordinate");
    if (y < 0) throw OutMatrixException("negative y coordinate");
    if (x >= nr_col) throw OutMatrixException("x coordinate bigger than matrix maximum");
    if (y >= nr_lin) throw OutMatrixException("y coordinate bigger that matrix maximum");
    return true;
}


/// \brief Move a character on the maze
/// \param mod - type of character that is moving: PLAYER, MONSTER
/// \param old_x - the old X coordinate
/// \param old_y - the old Y coordinate
/// \param new_x - the new X coordinate
/// \param new_y - the new Y coordinate
/// \return true is the character was able to move, a character can move in a WALL cell, or outside the matrix
bool Maze::move(Cell_mode mod, int old_x, int old_y, int new_x, int new_y) {
    inside(old_x, old_x);
    inside(new_x, new_y);

    ///verify special case: First adding a monster on table
    if (old_x == new_x && old_y == new_y && matrix[old_y][old_x].getMode() == FREE) {
        matrix[new_y][new_x].setMode(mod);
        return true;
    }
    if (matrix[old_y][old_x].getMode() != mod) throw BlockedCellException("invalid start cell");
    if (matrix[new_y][new_x].getMode() == WALL) throw BlockedCellException("block end cell");
    if (matrix[new_y][new_x].getMode() != FREE) {
        if ((matrix[new_y][new_x].getMode() == PLAYER && mod > FINISH) ||
            (matrix[new_y][new_x].getMode() > FINISH && mod == PLAYER)) {
            throw GameOverException("Player meet a monster");
        }
    }
    matrix[new_y][new_x].setMode(mod);
    if (old_x != new_x || old_y != new_y) matrix[old_y][old_x].setMode(FREE);
    return true;
}

/// \brief verify if a cell is free to pass.
/// \param x the x coordinate of the cell
/// \param y the y coordinate of the cell
/// \return true - if the cell is free, false - otherwise
bool Maze::free_cell(int x, int y) {
    if (matrix[y][x].getMode() == WALL) throw BlockedCellException("Wall here");
    if (matrix[y][x].getMode() > FINISH) throw BlockedCellException("Other monster here");
    return true;
}

bool Maze::finish(int x, int y) {
    return x == nr_col - 1 && y == nr_lin - 1;
}

