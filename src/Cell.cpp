//
// Created by Norina Alexandru on 10/22/2023.
// The cpp file for Cell class.
//

#include "../headers/Cell.hpp"


/// \brief Constructor for cell class.
/// \param mode - type of cell: FREE, WALL, PLAYER, FINISH, etc.
/// \param lin - row of cell
/// \param col - column of cell
/// \param dimX - dimension on X axis
/// \param dimY - dimension on Y axis
Cell::Cell(Cell_mode mode, const int lin, const int col, const int dimX, const int dimY) : mode(mode) {
    this->rect.setSize({static_cast<float>(dimX), static_cast<float>(dimY)}); ///set the size for RectangleShape
    this->rect.setPosition({static_cast<float>(col * dimX), static_cast<float>(lin * dimY)}); ///set the position
    this->rect.setTexture(TextureManager::getTexture(mode));
}

/// \brief A setter for the type of Cell.
/// \param lmode - type of cell that will be set: FREE, WALL, PLAYER, FINISH, etc.
void Cell::setMode(Cell_mode lmode) {
    if (this->mode == WALL) return;
    this->mode = lmode;
    this->rect.setTexture(TextureManager::getTexture(this->mode), true);
}

/// \brief Getter for RectangleShape
/// \return a constant reference to RectangleShape object
const sf::RectangleShape &Cell::getRect() const {
    return rect;
}

/// \brief Overwrite the operator << for display on output information about a cell.
/// \param os ostream reference
/// \param cell the Cell to be displayed
/// \return ostream reference after modifications
std::ostream &operator<<(std::ostream &os, const Cell &cell) {
    int dim_x = static_cast<int>(cell.rect.getSize().x);
    int dim_y = static_cast<int>(cell.rect.getSize().y);
    int lin = static_cast<int>(cell.rect.getPosition().y) / dim_y;
    int col = static_cast<int>(cell.rect.getPosition().x) / dim_x;
    os << "lin: " << lin << " col: " << col << " dim_x: " << dim_x << " dim_y: " << dim_y;
    os << " mode: ";
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
        case FINISH:
            os << "FINISH";
            break;
        default:
            os << "MONSTER";
            break;
    }
    return os;
}

/// \brief Setter for all cell's dimensions.
/// \param lin - Cell's row
/// \param col - cell's column
/// \param dim_x - dimension on X axis
/// \param dim_y - dimension on Y axis
void Cell::setDimensions(int lin, int col, unsigned int dim_x, unsigned int dim_y) {
    this->rect.setSize({static_cast<float>(dim_x), static_cast<float>(dim_y)});
    this->rect.setPosition({static_cast<float>(col * dim_x), static_cast<float>(lin * dim_y)});
}

/// \brief Copy constructor for cell class.
/// \param other - constant reference for an other class object
Cell::Cell(const Cell &other) {
    this->mode = other.mode;
    this->rect.setSize(other.rect.getSize());
    this->rect.setTexture(other.rect.getTexture());
    this->rect.setPosition(other.rect.getPosition());
}

/// \brief Overwrite the operator= for cell class
/// \param other - constant reference fon an other class object
/// \return a reference to a cell object
Cell &Cell::operator=(const Cell &other) {
    if (this != &other) {
        this->mode = other.mode;
        this->rect.setSize(other.rect.getSize());
        this->rect.setTexture(other.rect.getTexture());
        this->rect.setPosition(other.rect.getPosition());
    }
    return *this;
}

/// \brief Getter for the type of cell
/// \return the type of cell
Cell_mode Cell::getMode() const {
    return mode;
}

