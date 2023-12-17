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
#include <chrono>
#include <thread>

class Menu {
    static std::vector<Button> buttons;
    static sf::Font font;

    Menu() = default;

public:
    static void load(sf::RenderWindow &window, const std::string &fontFile, const sf::Color &textColor,
              const sf::Color &buttonColor,unsigned int nr_buttons, std::vector<std::string> textButtons, std::vector<std::function<void()>> onClick_functions);

    static void draw(sf::RenderWindow &window);

    static void handleInput(sf::RenderWindow &window);


};



#endif //OOP_MENU_HPP
