//
// Created by Norina Alexandru on 11/19/2023.
// Jungle Jumper is another type of monster. He loves leaping from one grassy patch to another vertically.

#ifndef OOP_JUNGLEJUMPER_HPP
#define OOP_JUNGLEJUMPER_HPP


#include "../Monster.hpp"

/// \brief Jungle Jumper is another type of monster. He loves leaping from one grassy patch to another vertically.
class JungleJumper: public Monster{
    static Cell_mode type;
public:
    JungleJumper(unsigned int x, unsigned int y);

    void move(Maze &maze) override;
};

Cell_mode JungleJumper::type = JUNGLE_JUMPER;

#endif //OOP_JUNGLEJUMPER_HPP
