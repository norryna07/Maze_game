#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "headers/Maze.hpp"
#include "headers/Player.hpp"

#ifdef __linux__
#include <X11/Xlib.h>
#endif


int main() {
    #ifdef __linux__
    XInitThreads();
    #endif

    sf::RenderWindow window;
    // NOTE: sync with env variable APP_WINDOW from .github/workflows/cmake.yml:30
    window.create(sf::VideoMode({500, 500}), "Maze game", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(60);
    TextureManager::load();
    Maze m(5, 5, window.getSize().x, window.getSize().y, "..\\tastatura.txt");
    Player p;
    std::cout << m;

    while(window.isOpen()) {
        p.move(window, m);
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(200ms);

        window.clear();
        m.draw(window);
        window.display();
    }

    return 0;
}
