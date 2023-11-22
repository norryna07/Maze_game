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

Level::Level(int difficulty, int dimX, int dimY, const std::string& filename) :
    maze(FactorDifficulty*difficulty, FactorDifficulty*difficulty, dimX, dimY, filename),  difficulty(difficulty){
    score = 0;
    std::ifstream fin (filename);
    int n = FactorDifficulty*difficulty;
    int type;
    /// y dimension in matrix represents the rows and x dimension in matrix represents the columns
    for (int y = 0; y < n; ++y)
        for (int x = 0; x < n; ++x)
        {
            fin >> type;
            switch ((Cell_mode)type) {
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

void Level::update(sf::RenderWindow& window) {
    player.move(window, maze);
    for (const auto& monster:monsters) {
        monster->move(maze);
    }
}
