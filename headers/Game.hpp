//
// Created by Norina Alexandru on 12/19/2023.
// A class that manage a game.
//

#ifndef OOP_GAME_HPP
#define OOP_GAME_HPP


#include "Button.hpp"
#include "Level.hpp"

///Singleton class that manage the game.
class Game {
    static int difficulty;
    static int score;
    static int number_monsters;
    Game() = default;
    Game(Game&) = default;
    Game(Game&&) = default;
public:
    static void newGame();

    static void resume();

    static void drawLevel(sf::RenderWindow &window, Level &level, Button &help);

    static void nextLevel(sf::RenderWindow &window);

    static void saveGame();
};


#endif //OOP_GAME_HPP
