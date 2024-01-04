//
// Created by Norina Alexandru on 10/28/2023.
// Cpp file for Player class.
//

#include "../headers/Player.hpp"
#include "../headers/Exceptions.hpp"
#include <iostream>

/// \brief Overwrite the operator << for display to the output player's position
/// \param os - ostream reference
/// \param player - a player object
/// \return ostream reference after modifications
std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << "Player x: " << player.x << " y: " << player.y << '\n';
    return os;
}

/// \brief Move the player on the screen based on key that is press on keyboard.
/// \param e - a Event that if is keypress will determine where the player moves
/// \param m - a reference to the maze where the player is moving
bool Player::move(const sf::Event &e, Maze &m) {
    ///the event is not a Key Pressed, so don't affect the player
    if (e.type != sf::Event::KeyPressed) return false;
    unsigned int lx, ly;
    lx = this->x;
    ly = this->y;
    switch (e.key.code) {
        case sf::Keyboard::Left:
            lx--;
            break;
        case sf::Keyboard::Right:
            lx++;
            break;
        case sf::Keyboard::Up:
            ly--;
            break;
        case sf::Keyboard::Down:
            ly++;
            break;
        default:
            return false;
    }
    if (m.finish(lx, ly)) throw GameWinException("WIN");
    try {
        m.move(PLAYER, x, y, lx, ly);
    } catch (BlockedCellException &ex) {
        std::cerr << x << ' ' << y << ' ' << lx << ' ' << ly << ex.what() << '\n';
        return false;
    } catch (OutMatrixException &ex) {
        std::cerr << x << ' ' << y << ' ' << lx << ' ' << ly << ex.what() << '\n';
        return false;
    }
    x = lx;
    y = ly;
    return true;
}
