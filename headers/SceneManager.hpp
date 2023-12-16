//
// Created by Norina Alexandru on 12/16/2023.
// A class that manage scene from our game.
//

#ifndef OOP_SCENEMANAGER_HPP
#define OOP_SCENEMANAGER_HPP
#include <SFML/Graphics.hpp>
#include "Menu.hpp"

/// \brief class will contain all scene use in the game
class SceneManager {
    SceneManager() = default;
public:
    static void StartPage(sf::RenderWindow& window);
};


#endif //OOP_SCENEMANAGER_HPP
