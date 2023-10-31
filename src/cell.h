//
// Created by norin on 10/22/2023.
//

#ifndef OOP_CELL_H
#define OOP_CELL_H
#include <SFML/Graphics.hpp>
#include <ostream>

enum cell_mode {
    FREE, WALL, PLAYER, MONSTER
};


class cell {
    sf::RectangleShape rect;
    cell_mode mode;
public:
    cell(cell_mode mode = FREE, int lin = 0, int col = 0, int dimX = 100, int dimY = 100);
    ~cell() = default;
    cell(const cell &other);

    void setMode(cell_mode lmode);
    void setDimensions(int lin, int col,unsigned int dim_x,unsigned int dim_y);
    const sf::RectangleShape &getRect() const;
    cell_mode getMode() const;

    friend std::ostream &operator<<(std::ostream &os, const cell &cell);
    cell& operator=(const cell& other);
};


#endif //OOP_CELL_H
