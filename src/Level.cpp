//
// Created by Norina Alexandru on 11/23/2023.
// cpp file for Level class.
//

#include "../headers/Level.hpp"
#include "../headers/Monsters/SentryPaws.hpp"
#include "../headers/Monsters/JungleJumper.hpp"
#include "../headers/Monsters/RoamingRiddler.hpp"
#include "../headers/Monsters/BlinkingBanshee.hpp"
#include "../headers/Monsters/WanderingWhisk.hpp"
#include "../headers/Monsters/ZigzagZephyr.hpp"
#include "../headers/Exceptions.hpp"

#include <iostream>
#include <fstream>

/// \brief Construction for Level class
/// \param difficulty the difficulty of the level
/// \param dimX dimension X of maze
/// \param dimY dimension Y of maze
/// \param filename where the maze is store
/// \param font
Level::Level(int difficulty, int dimX, int dimY, const std::string &filename) :
        maze(FactorDifficulty(difficulty), FactorDifficulty(difficulty), dimX, dimY, filename){
    score = 0;
    std::ifstream fin(filename);
    int n = FactorDifficulty(difficulty);
    int type;

    ///for ROAMING_RIDDLER monster
    std::vector<sf::Vector2<unsigned int>> path;

    /// y dimension in matrix represents the rows and x dimension in matrix represents the columns
    for (int y = 0; y < n; ++y)
        for (int x = 0; x < n; ++x) {
            fin >> type;
            switch ((Cell_mode) type) {
                case SENTRY_PAWS:
                    monsters.emplace_back(std::make_shared<SentryPaws>(x, y));
                    break;
                case JUNGLE_JUMPER:
                    monsters.emplace_back(std::make_shared<JungleJumper>(x, y));
                    break;
                case ZIGZAG_ZEPHYR:
                    monsters.emplace_back(std::make_shared<ZigzagZephyr>(x, y));
                    break;
                case WANDERING_WHISK:
                    monsters.emplace_back(std::make_shared<WanderingWhisk>(x, y));
                    break;
                case ROAMING_RIDDLER:
                    path.emplace_back(x, y);
                    path.emplace_back(x - 1, y);
                    path.emplace_back(x - 2, y);
                    monsters.emplace_back(std::make_shared<RoamingRiddler>(path));
                    break;
                case BLINKING_BANSHEE:
                    monsters.emplace_back(std::make_shared<BlinkingBanshee>(x, y));
                    break;
                default:
                    break;
            }
        }
    fin.close();
}

/// \brief a function that handleInput for levels
/// \param ev an event
/// \param window where the level is placed
void Level::handleInput(sf::Event e, sf::RenderWindow &window) {
    try {
        switch (e.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (player.move(e, maze)) {
                    score++;
                }
                for (const auto &monster: monsters) {
                    monster->move(maze);
                }
                break;
            default:
                break;
        }
    } catch (GameOverException &ex) {
        std::cerr << ex.what();
        throw ex;
    } catch (GameWinException &ex) {
        std::cerr << ex.what();
        score++;
        throw GameWinException(std::to_string(score));
    }
}

/// \brief draw the level
/// \param window where the level is drawn
void Level::draw(sf::RenderWindow &window) {
    maze.draw(window);
}


