//
// Created by norin on 10/22/2023.
//

#include "cell.h"
#include "textures.h"

cell::cell(cell_mode mode, const int lin,const int col,const int dimX,const int dimY) : mode(mode) {
    this->rect.setSize({static_cast<float>(dimX), static_cast<float>(dimY)});
    this->rect.setPosition({static_cast<float>(col*dimX), static_cast<float>(lin*dimY)});
    switch (mode) {
        case FREE:
            this->rect.setTexture(textures.get_free_texture());
            break;
        case WALL:
            this->rect.setTexture(textures.get_wall_texture());
            break;
        default:
            this->rect.setTexture(textures.get_player_texture());
    }
}

void cell::setMode(cell_mode _mode) {
    if (mode == WALL) return;
    this->mode = _mode;
    switch (_mode) {
        case FREE:
            this->rect.setTexture(textures.get_free_texture(), true);
            break;
        case WALL:
            this->rect.setTexture(textures.get_wall_texture(), true);
            break;
        case PLAYER:
            this->rect.setTexture(textures.get_player_texture(), true);
            break;
        case MONSTER:
            this->rect.setTexture(textures.get_monster_texture(), true);
            break;
    }
}


const sf::RectangleShape &cell::getRect() const {
    return rect;
}

std::ostream &operator<<(std::ostream &os, const cell &cell) {
    int dim_x = static_cast<int>(cell.rect.getSize().x);
    int dim_y = static_cast<int>(cell.rect.getSize().y);
    int lin = static_cast<int>(cell.rect.getPosition().y) / dim_y;
    int col = static_cast<int>(cell.rect.getPosition().x) / dim_x;
    os << "lin: " << lin << " col: " << col << " dim_x: " << dim_x << " dim_y: " << dim_y;
    os  << " mode: ";
    switch (cell.mode) {
        case FREE:
            os << "FREE";
            break;
        case WALL:
            os << "WALL";
            break;
        case PLAYER:
            os << "PLAYER";
            break;
        case MONSTER:
            os << "MONSTER";
            break;
    }
    return os;
}

void cell::setDimentions(int lin, int col,unsigned int dim_x,unsigned int dim_y) {
    this->rect.setSize({static_cast<float>(dim_x), static_cast<float>(dim_y)});
    this->rect.setPosition({static_cast<float>(col*dim_x), static_cast<float>(lin*dim_y)});
}

cell::cell(const cell &other) {
    this->mode = other.mode;
    this->rect.setSize(other.rect.getSize());
    this->rect.setTexture(other.rect.getTexture());
    this->rect.setPosition(other.rect.getPosition());
}

cell &cell::operator=(const cell &other) {
    if (this != &other) {
        this->mode = other.mode;
        this->rect.setSize(other.rect.getSize());
        this->rect.setTexture(other.rect.getTexture());
        this->rect.setPosition(other.rect.getPosition());
    }
    return *this;
}

cell_mode cell::getMode() const {
    return mode;
}

