//
// Created by Norina Alexandru on 12/16/2023.
// A class that manage scene from our game.
//

#ifndef OOP_SCENEMANAGER_HPP
#define OOP_SCENEMANAGER_HPP
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "Menu.hpp"
#include "TextureManager.hpp"
#include "Game.hpp"

/// \brief will helps as to know where must to came back from Story Game scene
enum Last_Scene {
    START_SCENE, WIN_SCENE, END_SCENE, GAME
};

/// \brief class will contain all scene use in the game
class SceneManager {
    SceneManager() = default;
public:
    static void StartPage(sf::RenderWindow& window);
    static void WinLevelPage(sf::RenderWindow& window, int curr_score);
    static void EndGamePage(sf::RenderWindow& window);
    static void GameStory(sf::RenderWindow& window, Last_Scene scene, int score = 0,const std::function<void()> &back = [](){});

};


#endif //OOP_SCENEMANAGER_HPP
