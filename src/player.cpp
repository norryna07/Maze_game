//
// Created by norin on 10/28/2023.
//

#include "player.h"

/// \brief Overwrite the operator << for display to the output player's position
/// \param os - ostream reference
/// \param player - a player object
/// \return ostream reference after modifications
std::ostream &operator<<(std::ostream &os, const player &player) {
    os << "Player x: " << player.x << " y: " << player.y << '\n';
    return os;
}

/// \brief Move the player on the screen based on key that is press on keyboard.
/// \param window - a RenderWindow reference where the game that place
/// \param m - a reference to the maze where the player is moving
void player::move(sf::RenderWindow &window, maze &m) {
    sf::Event e;
    int lx, ly;
    lx = this->x;
    ly = this->y;
    while(window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                switch(e.key.code) {
                    case sf::Keyboard::Left:
                        lx --;
                        break;
                    case sf::Keyboard::Right:
                        lx ++;
                        break;
                    case sf::Keyboard::Up:
                        ly --;
                        break;
                    case sf::Keyboard::Down:
                        ly ++;
                        break;
                    default:
                        break;
                }
                if (m.move(PLAYER, x, y, lx, ly)) {x = lx; y = ly;}
                std::cout << *this;
                break;
            default:
                break;
        }
    }
}
