//
// Created by Norina Alexandru on 10/22/2023.
// A class that manage all textures use in this project.
//

#ifndef OOP_TEXTURES_H
#define OOP_TEXTURES_H

#include <SFML/Graphics.hpp>
#include <vector>

enum Cell_mode {
    FREE, WALL, PLAYER, MONSTER,
    SENTRY_PAWS, JUNGLE_JUMPER, ZIGZAG_ZEPHYR, WANDERING_WHISK, ROAMING_RIDDLER, BLINKING_BANSHEE
};

/*class Textures {
    sf::Texture free_texture, wall_texture;
    sf::Texture player_texture, monster_texture;
public:
    Textures() {
        free_texture.loadFromFile("..\\images\\grass.jpg");
        wall_texture.loadFromFile("..\\images\\wall.png");
        player_texture.loadFromFile("..\\images\\player.png");
        monster_texture.loadFromFile("..\\images\\monster.png");
    }
    sf::Texture* get_free_texture() {return &free_texture;}
    sf::Texture* get_wall_texture() {return &wall_texture;}
    sf::Texture* get_player_texture() {return &player_texture;}
    sf::Texture* get_monster_texture() {return &monster_texture;}
};

inline Textures textures;*/

class Textures {
    static std::vector <sf::Texture> tex;
    Textures() = default;
public:
    static sf::Texture* getTexture(Cell_mode type) {
        return &(tex[(int)type]);
    }
    static void load() {
        static bool alreadyLoaded = false;
        if (!alreadyLoaded) {
            tex[0].loadFromFile("..\\images\\grass.jpg");
            tex[1].loadFromFile("..\\images\\wall.png");
            tex[2].loadFromFile("..\\images\\player.png");
            tex[3].loadFromFile("..\\images\\monster.png");
            alreadyLoaded = true;
        }
    }

};

inline std::vector<sf::Texture> tex(9);

#endif //OOP_TEXTURES_H
