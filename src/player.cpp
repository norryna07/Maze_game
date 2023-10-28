//
// Created by norin on 10/28/2023.
//

#include "player.h"


std::ostream &operator<<(std::ostream &os, const player &player) {
    os << "Player x: " << player.x << " y: " << player.y << '\n';
    return os;
}

void player::move(sf::RenderWindow &window, maze &m) {
    sf::Event e;
    int _x, _y;
    _x = this->x;
    _y = this->y;
    while(window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                switch(e.key.code) {
                    case sf::Keyboard::Left:
                        _x --;
                        break;
                    case sf::Keyboard::Right:
                        _x ++;
                        break;
                    case sf::Keyboard::Up:
                        _y --;
                        break;
                    case sf::Keyboard::Down:
                        _y ++;
                        break;
                    default:
                        break;
                }
                if (m.move(PLAYER, x, y, _x, _y)) {x = _x; y = _y;}
                std::cout << *this;
                break;
            default:
                break;
        }
    }
}
