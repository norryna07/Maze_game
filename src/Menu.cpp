//
// Created by Norina Alexandru on 12/16/2023.
// cpp file for Menu class.
//

#include "../headers/Menu.hpp"
#include <chrono>
#include <thread>

/// \brief
/// \param window where the menu is draw
/// \param fontFile filename for font
/// \param textColor color of text from the buttons
/// \param buttonColor color of buttons
/// \param nrButtons number of buttons
/// \param textButtons a vector of text from every button
/// \param onClick_functions a vector of functions for actions of buttons
void Menu::load(sf::RenderWindow &window, const std::string& fontFile, const sf::Color &textColor,
                const sf::Color &buttonColor,unsigned int nrButtons, std::vector<std::string> textButtons, std::vector<std::function<void()>> onClick_functions) {
    ///get the dimension of start_position of the menu
    sf::Vector2f start_pos = sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
    ///load the font
    font.loadFromFile(fontFile);

    if (nrButtons > textButtons.size() || nrButtons > onClick_functions.size()){
        return;
    }

    int height = 50;
    for (unsigned int i = 0; i < nrButtons; ++i) {
        buttons.emplace_back(textButtons[i], font, sf::Vector2f {start_pos.x, start_pos.y + i * height}, onClick_functions[i], textColor, buttonColor);
    }
}



/// \brief draw the menu
/// \param window where the menu is draw
void Menu::draw(sf::RenderWindow &window) {
    for (auto& button:buttons) {
        button.draw(window);
    }
}

/// \brief execute onClick function for every button
/// \param window where the menu is
void Menu::handleInput(sf::RenderWindow &window) {
    sf::Event ev{};
    while (window.pollEvent(ev)) {
        ///sleep for a period of time
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(200ms);

        if (ev.type == sf::Event::Closed) window.close();
        else for (auto& button:buttons) {
                button.handleEvent(ev, window);
             }
    }
}


