//
// Created by norin on 11/20/2023.
//

#include "../headers/TextureManager.hpp"

std::vector<sf::Texture> TextureManager::tex(9);

sf::Texture *TextureManager::getTexture(Cell_mode type) {
    return &(tex[(int) type]);
}

void TextureManager::load() {
    static bool alreadyLoaded = false;
    if (!alreadyLoaded) {
        tex[0].loadFromFile("..\\images\\grass.jpg");
        tex[1].loadFromFile("..\\images\\wall.png");
        tex[2].loadFromFile("..\\images\\player.png");
        tex[3].loadFromFile("..\\images\\monster.png");
        tex[4].loadFromFile("..\\images\\monster.png");
        tex[5].loadFromFile("..\\images\\monster.png");
        tex[6].loadFromFile("..\\images\\monster.png");
        tex[7].loadFromFile("..\\images\\monster.png");
        tex[8].loadFromFile("..\\images\\monster.png");
        alreadyLoaded = true;
    }

}
