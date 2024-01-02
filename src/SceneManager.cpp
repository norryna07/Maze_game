//
// Created by Norina Alexandru on 12/16/2023.
// cpp file for SceneManager class
//

#include "../headers/SceneManager.hpp"


void onClick() { std::cout << "ai apasat"; };

/// \brief Will create Start Page of the game.
/// \param window where the scene is place
void SceneManager::StartPage(sf::RenderWindow &window) {
    ///add the logo texture
    sf::Texture logo_texture;
    logo_texture.loadFromFile("..\\images\\logo.png");

    ///add the logo sprite
    sf::Sprite logo_sprite;
    logo_sprite.setTexture(logo_texture);
    logo_sprite.setScale(0.75f, 0.75f);

    ///make the sprite to be center in the middle of the window
    sf::FloatRect sprite_rect = logo_sprite.getLocalBounds();
    logo_sprite.setOrigin(sprite_rect.width / 2.0f, sprite_rect.height / 2.0f);
    logo_sprite.setPosition(window.getSize().x / 2.0f, window.getSize().y / 4.0f);

    ///add the menu
    std::string fontFile = "..\\fonts\\arial.ttf";
    std::vector<std::function<void()>> fct_buttons;
    std::vector<std::string> text_buttons;
    fct_buttons.emplace_back([&window](){Game::newGame(); Game::nextLevel(window);});
    text_buttons.emplace_back("Start New Game");
    fct_buttons.emplace_back([&window](){Game::resume(); Game::nextLevel(window);});
    text_buttons.emplace_back("Resume Last Game");
    fct_buttons.emplace_back([&window]() { SceneManager::GameStory(window, START_SCENE); });
    text_buttons.emplace_back("Game Story");
    fct_buttons.emplace_back([&window]() { window.close(); });
    text_buttons.emplace_back("Exit");
    Menu start_menu;
    start_menu.load(window, fontFile, sf::Color::White, sf::Color(Purple_color), text_buttons.size(), text_buttons,
               fct_buttons);

    ///create the loop for the Start Page
    window.clear();
    while (window.isOpen()) {
        window.clear();
        start_menu.handleInput(window);
        start_menu.draw(window);
        window.draw(logo_sprite);
        window.display();
    }
}

/// \brief a function that will create win level page, will contain a message of congrats and the high-score and actual score
/// \param window where the scene is place
/// \param curr_score the current score
void SceneManager::WinLevelPage(sf::RenderWindow &window, int curr_score) {
    ///display the congrats message
    sf::Texture mess_texture;
    mess_texture.loadFromFile("..\\images\\levelwin.png");

    ///create the sprite
    sf::Sprite mess_sprite;
    mess_sprite.setTexture(mess_texture);
    mess_sprite.setScale(0.75f, 0.75f);

    ///center the message
    sf::FloatRect mess_rect = mess_sprite.getLocalBounds();
    mess_sprite.setOrigin(mess_rect.width / 2.0f, mess_rect.height / 2.0f);
    mess_sprite.setPosition(window.getSize().x / 2.0f, window.getSize().y * 0.1f);

    ///create the font
    std::string fontfile = "..\\fonts\\arial.ttf";
    sf::Font font;
    font.loadFromFile(fontfile);

    ///add current score
    sf::Text current_score;
    current_score.setFont(font);
    current_score.setString("Current score: " + std::to_string(curr_score));
    current_score.setFillColor(sf::Color(Blue_color));
    current_score.setCharacterSize(35);
    sf::FloatRect curr_rect = current_score.getLocalBounds();
    current_score.setOrigin(curr_rect.width / 2.0f + 5, curr_rect.height / 2.0f + 5);
    current_score.setPosition(window.getSize().x / 2.0f, window.getSize().y * 0.32f);

    ///take high score from file
    std::ifstream fin("..\\text_files\\highscore.txt");
    int h_score;
    fin >> h_score;
    fin.close();
    if (h_score < curr_score) {
        h_score = curr_score;
        std::ofstream fout("..\\text_files\\highscore.txt");
        fout << h_score;
        fout.close();
    }

    ///add the high score to the scene
    sf::Text high_score;
    high_score.setFont(font);
    high_score.setString("High Score: " + std::to_string(h_score));
    high_score.setFillColor(sf::Color(Blue_color));
    high_score.setCharacterSize(35);
    sf::FloatRect high_rect = high_score.getLocalBounds();
    high_score.setOrigin(high_rect.width / 2.0f + 5, high_rect.height / 2.0f + 5);
    high_score.setPosition(window.getSize().x / 2.0f, window.getSize().y * 0.4f);

    ///add the menu
    std::vector<std::string> textButtons;
    std::vector<std::function<void()>> fctButtons;
    fctButtons.emplace_back([&window](){Game::nextLevel(window);});
    textButtons.emplace_back("Next Level");
    fctButtons.emplace_back([](){Game::saveGame();});
    textButtons.emplace_back("Save current game");
    fctButtons.emplace_back([&window, curr_score]() { SceneManager::GameStory(window, WIN_SCENE, curr_score); });
    textButtons.emplace_back("Game Story");
    fctButtons.emplace_back([&window]() { window.close(); });
    textButtons.emplace_back("Exit");

    Menu win_menu;
    win_menu.load(window, fontfile, sf::Color::White, sf::Color(Purple_color), textButtons.size(), textButtons,
               fctButtons);

    ///create the loop for the WinPage
    window.clear();
    while (window.isOpen()) {
        window.clear();
        win_menu.handleInput(window);
        win_menu.draw(window);
        window.draw(mess_sprite);
        window.draw(current_score);
        window.draw(high_score);
        window.display();
    }
}

/// \brief scene that will be shown when a level is lost(a monster catch the player)
/// \param window where the game took place
void SceneManager::EndGamePage(sf::RenderWindow &window) {
    ///add the message
    sf::Texture mess_texture;
    mess_texture.loadFromFile("..\\images\\endgame.png");

    ///create the message sprite
    sf::Sprite mess_sprite;
    mess_sprite.setTexture(mess_texture);
    mess_sprite.setScale(0.75f, 0.75f);

    ///center the message
    sf::FloatRect mess_rect = mess_sprite.getLocalBounds();
    mess_sprite.setOrigin(mess_rect.width / 2.0f, mess_rect.height / 2.0f);
    mess_sprite.setPosition(window.getSize().x / 2.0f, window.getSize().y / 4.0f);

    ///add the menu
    std::vector<std::string> textButtons;
    std::vector<std::function<void()>> fctButtons;
    fctButtons.emplace_back([&window](){Game::newGame(); Game::nextLevel(window);});
    textButtons.emplace_back("Start New Game");
    fctButtons.emplace_back([&window](){SceneManager::GameStory(window, END_SCENE);});
    textButtons.emplace_back("Game Story");
    fctButtons.emplace_back([&window]() { window.close(); });
    textButtons.emplace_back("Exit");

    Menu end_menu;
    end_menu.load(window, "..\\fonts\\arial.ttf", sf::Color::White, sf::Color(Purple_color), textButtons.size(),
               textButtons, fctButtons);

    ///create the loop for the End Game page
    window.clear();
    while (window.isOpen()) {
        window.clear();
        end_menu.handleInput(window);
        end_menu.draw(window);
        window.draw(mess_sprite);
        window.display();
    }
}

/// \brief a page with Game Story and information about every monster
/// \param window where the game take place
void SceneManager::GameStory(sf::RenderWindow &window, Last_Scene scene, int score,const std::function<void()> &back) {
    ///will display information about every monster, image and behavior

    ///get the font
    sf::Font font;
    font.loadFromFile("..\\fonts\\arial.ttf");

    ///add the title of this page
    sf::Text title;
    title.setString("Monsters");
    title.setFont(font);
    title.setCharacterSize(35);
    title.setFillColor(sf::Color(Blue_color));

    ///center the title
    sf::FloatRect title_rect = title.getLocalBounds();
    title.setOrigin(title_rect.width / 2.0f, title_rect.height / 2.0f);
    title.setPosition(window.getSize().x / 2.0f, window.getSize().y * 0.03f);

    std::vector<std::string> monstersName;
    std::vector<std::string> monstersBehavior;

    monstersName.emplace_back("Sentry Paws");
    monstersBehavior.emplace_back("Stays in one spot, keeping a\n watchful eye on the surroundings.");
    monstersName.emplace_back("Jungle Jumper");
    monstersBehavior.emplace_back("Loves leaping from one grassy\n patch to another vertically.");
    monstersName.emplace_back("Zigzag Zephyr");
    monstersBehavior.emplace_back("Playfully moves in a zigzag pattern,\n creating a dance of confusion.");
    monstersName.emplace_back("Wandering Whisk");
    monstersBehavior.emplace_back("Roams freely in the maze, changing\n direction at every intersection.");
    monstersName.emplace_back("Roaming Riddler");
    monstersBehavior.emplace_back("Patrols a fixed path, providing\n a challenging obstacle for Whiskers.");
    monstersName.emplace_back("Blinking Banshee");
    monstersBehavior.emplace_back("Randomly teleports, making its\n appearance unpredictable.");

    std::vector<sf::Text> names(6);
    std::vector<sf::Text> behaviors(6);
    std::vector<sf::RectangleShape> images(6);

    float diff = (window.getSize().y - title.getPosition().y) / 6.0f;
    for (int i = 0; i < 5; ++i) {
        ///set the names
        names[i].setFont(font);
        names[i].setString(monstersName[i]);
        names[i].setFillColor(sf::Color(Purple_color));
        names[i].setCharacterSize(25);
        names[i].setPosition(10, i * diff + title.getPosition().y * 2);

        ///set the behavior
        behaviors[i].setFont(font);
        behaviors[i].setString(monstersBehavior[i]);
        behaviors[i].setFillColor(sf::Color::White);
        behaviors[i].setCharacterSize(20);
        behaviors[i].setPosition(15, names[i].getPosition().y + 35);

        ///add the images
        images[i].setTexture(TextureManager::getTexture((Cell_mode)(i + FINISH + 1)));
        images[i].setSize({diff - 35, diff - 35});
        images[i].setPosition(3.0f * window.getSize().x / 4.0f - (diff - 35) / 2.0f, names[i].getPosition().y + 35);

    }

    ///create the exit function
    std::function<void()> fct;
    switch (scene) {
        case START_SCENE:
            fct = [&window]() { SceneManager::StartPage(window); };
            break;
        case WIN_SCENE:
            fct = [&window, score]() { SceneManager::WinLevelPage(window, score); };
            break;
        case END_SCENE:
            fct = [&window]() { SceneManager::EndGamePage(window); };
            break;
        case GAME:
            fct = back;
            break;
    }

    ///create the exit button
    Button exit("Back", font, {window.getSize().x / 2.0f, 6 * diff - 30}, fct, sf::Color::White,
                sf::Color(Purple_color));


    ///loop for the story scene
    window.clear();
    while (window.isOpen()) {
        window.clear();
        sf::Event ev{};
        while (window.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) window.close();
            else exit.handleEvent(ev, window);
        }
        window.draw(title);
        for (auto &name: names) window.draw(name);
        for (auto &behavior: behaviors) window.draw(behavior);
        for (auto &image: images) window.draw(image);
        exit.draw(window);
        window.display();
    }
}
