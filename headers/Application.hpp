//
// Created by Norina Alexandru on 1/3/2024.
//Application class for running the program.
//

#ifndef OOP_APPLICATION_HPP
#define OOP_APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"
#include "SceneManager.hpp"

class Application {
    Application() = default;
public:
    static void run() {
        sf::RenderWindow window;
        window.create(sf::VideoMode({700, 700}), "Maze game", sf::Style::Default);
        window.setVerticalSyncEnabled(true);
        TextureManager::load();
        SceneManager::StartPage(window);

    }
};

#endif //OOP_APPLICATION_HPP
