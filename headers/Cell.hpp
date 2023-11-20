//
// Created by Norina Alexandru on 10/22/2023.
// A class header for
//

#ifndef OOP_CELL_H
#define OOP_CELL_H
#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"
#include <ostream>



class Cell {
    sf::RectangleShape rect;
    Cell_mode mode;
public:
    Cell(Cell_mode mode = FREE, int lin = 0, int col = 0, int dimX = 100, int dimY = 100);
    ~Cell() = default;
    Cell(const Cell &other);

    void setMode(Cell_mode lmode);
    void setDimensions(int lin, int col,unsigned int dim_x,unsigned int dim_y);
    const sf::RectangleShape &getRect() const;
    Cell_mode getMode() const;

    friend std::ostream &operator<<(std::ostream &os, const Cell &Cell);
    Cell& operator=(const Cell& other);
};


#endif //OOP_CELL_H
