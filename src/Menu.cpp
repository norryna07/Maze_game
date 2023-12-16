//
// Created by norin on 12/16/2023.
//

#include "../headers/Menu.hpp"

std::vector<Button> Menu::buttons;
sf::Font Menu::font;

/// \brief load the menu
/// \param window where the menu is draw
/// \param fontFile filename for font
/// \param textColor color of text from the buttons
/// \param buttonColor color of buttons
/// \param onClick_functions a vector of functions for actions of buttons
void Menu::load(sf::RenderWindow &window, const std::string& fontFile, const sf::Color &textColor,
                const sf::Color &buttonColor, std::vector<std::function<void()>> onClick_functions) {
    ///get the dimension of start_position of the menu
    sf::Vector2f start_pos = sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
    ///load the font
    font.loadFromFile(fontFile);

    buttons.emplace_back("Start New Game", font, start_pos, onClick_functions[0], textColor, buttonColor);
    buttons.emplace_back("Resume Last Game", font, sf::Vector2f {start_pos.x, start_pos.y + 50}, onClick_functions[1], textColor, buttonColor);
    buttons.emplace_back("Game Story", font, sf::Vector2f {start_pos.x, start_pos.y + 100}, onClick_functions[2], textColor, buttonColor);
    buttons.emplace_back("Exit", font, sf::Vector2f {start_pos.x, start_pos.y + 150}, onClick_functions[3], textColor, buttonColor);
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
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(200ms);
        if (ev.type == sf::Event::Closed) window.close();
        for (auto& button:buttons) {
            button.handleEvent(ev, window);
        }
    }
}


