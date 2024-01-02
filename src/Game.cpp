//
// Created by Norina Alexandru on 12/19/2023.
// cpp file for Game class
//

#include "../headers/Game.hpp"
#include "../headers/SceneManager.hpp"

int Game::difficulty;
int Game::score;
int Game::number_monsters;

/// \brief Set the information on a new game.
void Game::newGame() {
    difficulty = 1;
    score = 0;
    number_monsters = 0;
}

/// \brief Resume the last game save in file
void Game::resume() {
    std::ifstream fin("..\\text_files\\save.txt");
    if (fin.is_open()) {
        fin >> difficulty;
        fin >> score;
        fin >> number_monsters;
        fin.close();
    }
}

/// \brief draw the level scene
/// \param window where the game take place
/// \param level the current level
/// \param help the help button
void Game::drawLevel(sf::RenderWindow &window, Level &level, Button &help) {
    sf::Event ev{};
    while (window.isOpen()) {
        while (window.pollEvent(ev)) {
            level.handleInput(ev, window);
            help.handleEvent(ev, window);
        }
        window.clear();
        level.draw(window);
        help.draw(window);
        window.display();
    }
}

/// \brief Create the next level based on difficulty and score
/// \param window where the game take place
void Game::nextLevel(sf::RenderWindow &window) {
    ///create the level
    MazeActions::create(difficulty);
    int minim_nr_steps = MazeActions::solve(difficulty);
    MazeActions::add_monsters(difficulty, number_monsters);
    Level l(difficulty, window.getSize().x, window.getSize().y, "..\\text_files\\maze.txt");

    sf::Font font;
    font.loadFromFile("..\\fonts\\arial.ttf");
    Button help("?", font, {window.getSize().x * 0.93f, window.getSize().y * 0.05f}, [&window, &l, &help]() {
        SceneManager::GameStory(window, GAME, 0, [&window, &l, &help]() { Game::drawLevel(window, l, help); });
    }, sf::Color::White, sf::Color(Blue_color));

    try {
        drawLevel(window, l, help);
    } catch (GameOverException &ex) {
        std::ofstream fout("..\\text_files\\save.txt");
        fout << "";
        fout.close();
        SceneManager::EndGamePage(window);
        return;
    } catch (GameWinException &ex) {
        ///get the number of steps
        int nr_steps = std::stoi(ex.what());
        ///update the score
        int level_score = 500;
        if (nr_steps < 2 * minim_nr_steps) level_score += 250 * (2 * minim_nr_steps - nr_steps) / minim_nr_steps;
        score += level_score;

        ///update the difficulty - for every 4 levels of a difficulty solve the difficulty increase
        if (score >= difficulty * 500 * 4) {difficulty ++; number_monsters = 0;}

        SceneManager::WinLevelPage(window, score);
    }


}

void Game::saveGame() {
    std::ofstream fout("..\\text_files\\save.txt");
    if (fout.is_open()) {
        fout << difficulty << "\n";
        fout << score << "\n";
        fout << number_monsters << "\n";
        fout.close();
    }
}



