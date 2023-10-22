//
// Created by norin on 10/22/2023.
//

#ifndef OOP_TEXTURES_H
#define OOP_TEXTURES_H

#include <SFML/Graphics.hpp>

class Textures {
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
} textures;

#endif //OOP_TEXTURES_H
