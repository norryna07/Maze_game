//
// Created by Norina Alexandru on 12/16/2023.
// cpp file for SceneManager class
//

#include <iostream>
#include "../headers/SceneManager.hpp"
#define Purple_color 139, 83, 255
#define Blue_color 103, 203, 210

void onClick() {std::cout<<"ai apasat";};

/// \brief Will create Start Page of the game.
/// \param window where the scene is place
void SceneManager::StartPage(sf::RenderWindow &window) {
    ///add the logo texture
    sf::Texture logo_texture;
    logo_texture.loadFromFile("..\\images\\logo.png");

    ///add the logo sprite
    sf::Sprite logo_sprite;
    logo_sprite.setTexture(logo_texture);
    logo_sprite.setScale(0.5f, 0.5f);

    ///make the sprite to be center in the middle of the window
    sf::FloatRect sprite_rect = logo_sprite.getLocalBounds();
    logo_sprite.setOrigin(sprite_rect.width / 2.0f, sprite_rect.height / 2.0f);
    logo_sprite.setPosition(window.getSize().x / 2.0f, window.getSize().y / 4.0f);

    ///add the menu
    std::string fontFile = "..\\fonts\\arial.ttf";
    std::vector<std::function<void()>> fct_buttons;
    std::vector<std::string> text_buttons;
    fct_buttons.emplace_back(onClick); text_buttons.emplace_back("Start New Game");
    fct_buttons.emplace_back(onClick); text_buttons.emplace_back("Resume Last Game");
    fct_buttons.emplace_back(onClick); text_buttons.emplace_back("Game Story");
    fct_buttons.emplace_back([&window](){window.close();}); text_buttons.emplace_back("Exit");
    Menu::load(window, fontFile, sf::Color::White, sf::Color(Purple_color), 4, text_buttons, fct_buttons);

    ///create the loop for the Start Page
    while (window.isOpen()) {
        Menu::handleInput(window);
        Menu::draw(window);
        window.draw(logo_sprite);
        window.display();
    }
}
