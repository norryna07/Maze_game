//
// Created by norin on 11/19/2023.
//

#ifndef OOP_BLINKINGBANSHEE_HPP
#define OOP_BLINKINGBANSHEE_HPP
#include <random>
#include "../Monster.hpp"
#include <SFML/Graphics.hpp>


class BlinkingBanshee: public Monster {
    static Cell_mode type;
public:
    BlinkingBanshee(unsigned int x, unsigned int y);

    void move(Maze &maze) override;
};


#endif //OOP_BLINKINGBANSHEE_HPP
