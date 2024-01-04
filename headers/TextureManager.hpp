//
// Created by Norina Alexandru on 11/20/2023.
// A class that manage all textures use in this project.
//

#ifndef OOP_TEXTUREMANAGER_HPP
#define OOP_TEXTUREMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#define FactorDifficulty(difficulty) (2*(difficulty)+1)
#define RED 2
#define BLUE 3
#define Purple_color 139, 83, 255
#define Blue_color 103, 203, 210

/// \brief references to type of textures that a cell can have
enum Cell_mode {
    FREE, WALL, PLAYER, FINISH,
    SENTRY_PAWS, JUNGLE_JUMPER, ZIGZAG_ZEPHYR, WANDERING_WHISK, ROAMING_RIDDLER, BLINKING_BANSHEE
};

/// \brief A singleton class that storages all the textures used in this project.
class TextureManager {
    static std::vector<sf::Texture> tex;

    TextureManager() = default;

    TextureManager(TextureManager &) = default;

    TextureManager(TextureManager &&) = default;

public:
    static sf::Texture *getTexture(Cell_mode type);

    static void load();

    TextureManager(const TextureManager &other) = delete;

    TextureManager operator=(const TextureManager &other) = delete;
};


#endif //OOP_TEXTUREMANAGER_HPP
