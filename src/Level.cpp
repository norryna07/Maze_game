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
#include <fstream>

/// \brief Construction for Level class
/// \param difficulty the difficulty of the level
/// \param dimX dimension X of maze
/// \param dimY dimension Y of maze
/// \param filename where the maze is store
Level::Level(int difficulty, int dimX, int dimY, const std::string &filename) :
        maze(FactorDifficulty(difficulty), FactorDifficulty(difficulty), dimX, dimY, filename){
    score = 0;
    std::ifstream fin(filename);
    int n = FactorDifficulty(difficulty);
    int type;
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
                    //monsters.emplace_back(std::make_shared<RoamingRiddler>())
                    break;
                case BLINKING_BANSHEE:
                    monsters.emplace_back(std::make_shared<BlinkingBanshee>(x, y));
                    break;
                default:
                    break;
            }
        }
}

/// \brief Will update the maze if the player moves and if the monsters moves.
/// \param window Where the maze is displayed.
void Level::update(sf::RenderWindow &window) {
    sf::Event e;
    while (window.pollEvent(e)) {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(200ms);
        try {
            switch (e.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (player.move(e, maze)) {
                        score++;
                    }
                    break;
                default:
                    break;
            }
            for (const auto &monster: monsters) {
                monster->move(maze);
            }
        } catch (GameOverException &ex) {
            std::cerr << ex.what();
            window.close();
            return;
        } catch (GameWinException &ex) {
            std::cerr << ex.what();
            score++;
            std::cerr << " Number of steps: " << score << '\n';
            window.close();
            return;
        }
        window.clear();
        maze.draw(window);
        window.display();
    }
}
