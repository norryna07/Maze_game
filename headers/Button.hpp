//
// Created by Norina Alexandru on 12/16/2023.
// A class that represent a button in the menu page and in the game.
//

#ifndef OOP_BUTTON_HPP
#define OOP_BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <functional>

/// \brief A button that can be click.
class Button {
    sf::RectangleShape rect;
    sf::Text text;
    std::function<void()> onClick;
public:
    Button(const std::string &buttonText, const sf::Font &font, const sf::Vector2<float> &position,
           const std::function<void()>& OnClick, const sf::Color &textColor, const sf::Color &buttonColor);
    void draw(sf::RenderWindow& window);
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
};


#endif //OOP_BUTTON_HPP
