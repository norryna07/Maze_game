//
// Created by Norina Alexandru on 11/20/2023.
// cpp file for the TextureManager class
//

#include "../headers/TextureManager.hpp"

std::vector<sf::Texture> TextureManager::tex(10);

/// \brief get texture by the type of the cell
/// \param type the type of texture
/// \return texture object of that type
sf::Texture *TextureManager::getTexture(Cell_mode type) {
    return &(tex[(int) type]);
}

/// \brief load every texture from images file if this wasn't done already
void TextureManager::load() {
    static bool alreadyLoaded = false;
    if (!alreadyLoaded) {
        tex[0].loadFromFile("..\\images\\grass.jpg");
        tex[1].loadFromFile("..\\images\\wall.png");
        tex[2].loadFromFile("..\\images\\player.png");
        tex[3].loadFromFile("..\\images\\finish.png");
        tex[4].loadFromFile("..\\images\\sentry_paws.png");
        tex[5].loadFromFile("..\\images\\jungle_jumper.png");
        tex[6].loadFromFile("..\\images\\zigzag_zephyr.png");
        tex[7].loadFromFile("..\\images\\wandering_whisk.png");
        tex[8].loadFromFile("..\\images\\roaming_riddler.png");
        tex[9].loadFromFile("..\\images\\blinking_banshee.png");
        alreadyLoaded = true;
    }

}
