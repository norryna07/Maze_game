//
// Created by Norina Alexandru on 12/13/2023.
// This will be a class that will have functions for the maze actions, create and solver.
// With this class will create the maze diagram before to actually create the Level and Maze object.
// Will write the maze layout on 'maze.txt' file.
//

#ifndef OOP_MAZEACTIONS_HPP
#define OOP_MAZEACTIONS_HPP

#include "TextureManager.hpp"
#include <vector>
#include <set>
#include <fstream>
#include <random>
#include <queue>


class MazeActions {

    friend std::pair<int, int> operator+(const std::pair<int, int> &a, const std::pair<int, int> &b);

    static bool inside_cell(const std::pair<int, int> &pair, int lin, int col);

    template<class T>
    static T getRandomElement(std::set<T> set1);

    template<class T>
    static std::pair<T, T> getTwoRandomElements(std::vector<T> v);

public:
    static void create(int difficulty);
    static int solve(int difficulty);
};


#endif //OOP_MAZEACTIONS_HPP
