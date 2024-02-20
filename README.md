# Cat's Maze Adventure

## Table of Contents

1. [Project Overview](#project-overview)
2. [Game Features](#game-features)
    1. [Story](#story)
    2. [Monsters](#monsters)
    3. [Objective](#objective)
3. [Project Structure](#project-structure)
4. [How to Run the Game](#how-to-run-the-game)
5. [License](#license)
6. [Contact Information](#contact-information)


## Project Overview

Welcome to "Cat's Maze Adventure," an enchanting maze exploration game set in the magical land of Whiskerwood. Join Whiskers, a brave cat with a curious spirit, as he navigates through challenging mazes, encounters mystical creatures, and discovers hidden secrets.

## Game Features


*   **Intriguing Story:** Embark on a magical journey with Whiskers as he explores the Labyrinth of Paws.
    
*   **Dynamic Mazes:** Navigate through ever-changing mazes with different levels of difficulty.
    
*   **Diverse Monsters:** Encounter various monsters with unique behaviors, adding challenges to your adventure.
    
*   **Interactive Gameplay:** Solve puzzles and outsmart monsters to progress through the game.

### Story

Once upon a time, Whiskers discovered a mysterious portal in the heart of Whiskerwood. Stepping through, he found himself in the Labyrinth of Paws—a magical maze filled with challenges, grassy meadows, and peculiar monsters. Your mission is to help Whiskers navigate through the maze, avoid monsters, and uncover the secrets hidden within.

### Monsters

1.  **Sentry Paws:**
    
    *   _Behavior:_ Stays in one spot, keeping a watchful eye on the surroundings.
2.  **Jungle Jumper:**
    
    *   _Behavior:_ Loves leaping from one grassy patch to another vertically.
3.  **Zigzag Zephyr:**
    
    *   _Behavior:_ Playfully moves in a zigzag pattern, creating a dance of confusion.
4.  **Wandering Whisk:**
    
    *   _Behavior:_ Roams freely in the maze, changing direction at every intersection.
5.  **Roaming Riddler:**
    
    *   _Behavior:_ Patrols a fixed path, providing a challenging obstacle for Whiskers.
6.  **Blinking Banshee:**
    
    *   _Behavior:_ Randomly teleports, making its appearance unpredictable.


### Objective

Help Whiskers navigate through the Labyrinth of Paws, avoid the various monsters, and uncover the magical artifacts hidden within the maze. Only the bravest and most cunning cats can triumph over the challenges of this enchanted labyrinth.

## Project Structure

*   **TextureManager:** Singleton class storing project textures.
    
*   **SceneManager:** Manages game scenes.
    
*   **Player:** Coordinates player movement.
    
*   **Monster (Abstract):**
    
    *   ZigzagZephyr, WanderingWhisk, SentryPaws, RoamingRiddler, JungleJumper, BlinkingBanshee.
*   **Menu:** Contains buttons with different actions.
    
*   **MazeActions:** Contains algorithms for creating and solving mazes.
    
*   **Maze:** Contains graphics information about the maze.
    
*   **Level:** Stores information about each game level.
    
*   **Game:** Singleton class managing the game.
    
*   **OutMatrixException:** Exception for accessing out-of-range maze cells.
    
*   **Cell:** Contains information about a maze cell.
    
*   **Button:** Clickable button.
    
*   **Application:** Class running the game.

## How to Run the Game:


1.  **Download the Release:**
    
    *   Visit the Releases page.
    *   Download the zip file corresponding to your operating system.
    *   For full game experience use the final release.
2.  **Extract and Run:**
    
    ```bash
    unzip norryna07_Maze_game_Debug_YourOS.zip 
    cd norryna07_Maze_game_Debug_YourOS 
    ./bin/oop
    
3.  **Navigate the Maze:**
    
    *   Use arrow keys to guide Whiskers through the maze.
4.  **Enjoy the Adventure!**

## License

This project is licensed under the [MIT License](LICENSE).

## Contact Information

For questions or feedback, reach out to the project maintainer:

*   Email: norinastefania@gmail.com
    

# OOP Template

### Tema 0

- [x] Nume proiect (poate fi schimbat ulterior)
- [x] Scurtă descriere a temei alese, ce v-ați propus să implementați

## Tema 1

#### Cerințe
- [x] definirea a minim **3-4 clase** folosind compunere
- [x] constructori de inițializare
- [x] pentru o clasă: constructor de copiere, `operator=` de copiere, destructor
<!-- - [ ] pentru o altă clasă: constructor de mutare, `operator=` de mutare, destructor -->
<!-- - [ ] pentru o altă clasă: toate cele 5 funcții membru speciale -->
- [x] `operator<<` pentru toate clasele pentru afișare (std::ostream)
- [x] cât mai multe `const` (unde este cazul)
- [x] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese
- [x] scenariu de utilizare a claselor definite:
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` exemple de date de intrare de la tastatură (dacă există)
- [x] tag de `git`: de exemplu `v0.1`
- [x] serviciu de integrare continuă (CI); exemplu: GitHub Actions

## Tema 2

#### Cerințe
- [X] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [x] moșteniri:
  - minim o clasă de bază și **3 clase derivate**
  - ierarhia trebuie să fie cu bază proprie, nu derivată dintr-o clasă predefinită
  - [x] clasă cu atribut de tip pointer la o clasă de bază cu derivate
  - [x] funcții virtuale (pure) apelate prin pointeri de bază din clasa care conține atributul de tip pointer de bază
    - minim o funcție virtuală va fi **specifică temei** (e.g. nu simple citiri/afișări)
    - constructori virtuali (clone): sunt necesari, dar nu se consideră funcții specifice temei
  - [x] apelarea constructorului din clasa de bază din constructori din derivate
  - [x] smart pointers (recomandat, opțional)
  - [ ] `dynamic_cast`/`std::dynamic_pointer_cast` pentru downcast cu sens
- [ ] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
- [x] excepții
  - [x] ierarhie proprie cu baza `std::exception` sau derivată din `std::exception`; minim 2 clase pentru erori specifice
  - [x] utilizare cu sens: de exemplu, `throw` în constructor, `try`/`catch` în `main`
- [x] funcții și atribute `static`
- [x] STL
- [x] cât mai multe `const`
- [ ] la sfârșit: commit separat cu adăugarea unei noi clase derivate fără a modifica restul codului, pe lângă cele 3 derivate deja adăugate
  - noua derivată nu poate fi una existentă care a fost ștearsă și adăugată din nou
- [x] tag de `git`: de exemplu `v0.2`

## Tema 3

#### Cerințe
- [x] 2 șabloane de proiectare (design patterns)
- [ ] o clasă șablon cu sens; minim **2 instanțieri**
  - [x] preferabil și o funcție șablon (template) cu sens; minim 2 instanțieri
<!-- - [ ] o specializare pe funcție/clasă șablon -->
- [ ] tag de `git`: de exemplu `v0.3` sau `v1.0`

## Resurse

- [SFML](https://github.com/SFML/SFML/tree/2.6.0) (Zlib)
