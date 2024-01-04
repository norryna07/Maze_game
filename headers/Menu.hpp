//
// Created by Norina Alexandru on 12/16/2023.
// A singleton that represent the menu from the start page.
//

#ifndef OOP_MENU_HPP
#define OOP_MENU_HPP

#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>

/// \brief A class that contain a set of button with different actions
class Menu {
    std::vector<Button> buttons;
    sf::Font font;


public:
    Menu() = default;

    void load(sf::RenderWindow &window, const std::string &fontFile, const sf::Color &textColor,
              const sf::Color &buttonColor, unsigned int nr_buttons, std::vector<std::string> textButtons,
              std::vector<std::function<void()>> onClick_functions);

    void draw(sf::RenderWindow &window);

    void handleInput(sf::RenderWindow &window);


};


#endif //OOP_MENU_HPP
