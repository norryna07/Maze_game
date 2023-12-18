#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "headers/Level.hpp"
#include "headers/SceneManager.hpp"
#include "headers/MazeActions.hpp"

#ifdef __linux__
#include <X11/Xlib.h>
#endif


int main() {
#ifdef __linux__
    XInitThreads();
#endif

    sf::RenderWindow window;
    // NOTE: sync with env variable APP_WINDOW from .github/workflows/cmake.yml:30
    window.create(sf::VideoMode({700, 700}), "Maze game", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(60);
    TextureManager::load();
//    Maze m(5, 5, window.getSize().x, window.getSize().y, "..\\tastatura.txt");
//    Player p;
//    std::cout << m;
//    while(window.isOpen()) {
//        p.move(window, m);
//        using namespace std::chrono_literals;
//        std::this_thread::sleep_for(200ms);
//
//        window.clear();
//        m.draw(window);
//        window.display();
//    }

    MazeActions::create(7);
    Level l1(7, window.getSize().x, window.getSize().y, "../maze.txt");
    while (window.isOpen()) {
        sf::Event ev{};
        while (window.pollEvent(ev)) {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(200ms);
            l1.handleInput(ev, window);
        }
        window.clear();
        l1.draw(window);
        window.display();
    }
    std::cout << MazeActions::solve(7) << '\n';

    //SceneManager::StartPage(window);
    //SceneManager::WinLevelPage(window, 140);
    //SceneManager::EndGamePage(window);
    //SceneManager::GameStory(window, END_SCENE);
    return 0;
}
