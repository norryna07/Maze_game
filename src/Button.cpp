//
// Created by Norina Alexandru on 12/16/2023.
// cpp file for the button class.
//

#include "../headers/Button.hpp"
#include "../headers/Exceptions.hpp"

/// \brief Constructor for button.
/// \param buttonText text from the button
/// \param font font for the text
/// \param position of the button in window
/// \param OnClick a function that will be execute on click
/// \param textColor color of the text
/// \param buttonColor color of the button
Button::Button(const std::string &buttonText, const sf::Font &font, const sf::Vector2<float> &position,
               const std::function<void()> &OnClick, const sf::Color &textColor, const sf::Color &buttonColor) :
        onClick(OnClick) {
    ///set the text
    text.setFont(font);
    text.setString(buttonText);
    text.setCharacterSize(20);
    text.setFillColor(textColor);

    ///center text within the button
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    //text.setPosition(position.x + textRect.width / 2.0f + 20, position.y + textRect.height / 2.0f + 10);
    text.setPosition(position);

    ///Set up button rectangle based on text size
    rect.setSize(sf::Vector2f (textRect.width + 40, textRect.height + 20));
    rect.setFillColor(buttonColor);
    rect.setOrigin(rect.getSize() / 2.0f);
    rect.setPosition(position);

    ///add border
    rect.setOutlineThickness(2);
    rect.setOutlineColor(textColor);
}

/// \brief Draw the button
/// \param window where the button is draw
void Button::draw(sf::RenderWindow &window) {
    window.draw(rect);
    window.draw(text);

}

/// \brief execute onClick function is the mouse is press on button
/// \param event an event
/// \param window where the button is
void Button::handleEvent(const sf::Event &event, sf::RenderWindow &window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if (rect.getGlobalBounds().contains(mouse_pos)) {
            onClick();
        }
    }
}
