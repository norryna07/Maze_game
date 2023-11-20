//
// Created by Norina Alexandru on 11/20/2023.
// A class that manage all textures use in this project.
//

#ifndef OOP_TEXTUREMANAGER_HPP
#define OOP_TEXTUREMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

enum Cell_mode {
    FREE, WALL, PLAYER, MONSTER,
    SENTRY_PAWS, JUNGLE_JUMPER, ZIGZAG_ZEPHYR, WANDERING_WHISK, ROAMING_RIDDLER, BLINKING_BANSHEE
};

class TextureManager {
    static std::vector<sf::Texture> tex;
    TextureManager() = default;
public:
    static sf::Texture* getTexture(Cell_mode type);
    static void load();
};


#endif //OOP_TEXTUREMANAGER_HPP
