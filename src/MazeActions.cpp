//
// Created by Norina Alexandru on 12/13/2023.
// cpp file for Maze Actions class
//

#include "../headers/MazeActions.hpp"
#include <iostream>

/// \brief Overwrite + operator between 2 pairs of int.
/// \param a first pair
/// \param b second pair
/// \return a pair that write + between vectors
std::pair<int, int> operator+(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return {a.first + b.first, a.second + b.second};
}

/// \brief This function will create a maze with an certain number of rows and columns
/// The algorithm will work like that: - using Prim algorithm for creating a maze, but twice
///                                    - consider start position at (1,1) and at finish position (n, m)
///                                    - choice a random neighbor from start and will make the wall a free position
///                                    - make the same with finish position until isn't any position that wasn't visit
///                                    - will be a wall between that 2 sections, will delete 2 walls cells to create multiple solution
///                                    - can add monster by difficulty
/// \param difficulty
void MazeActions::create(int difficulty) {
    int nr_lin = FactorDifficulty(difficulty);
    int nr_col = FactorDifficulty(difficulty);
    std::vector<std::vector<int> > matrix(nr_lin, std::vector<int>(nr_col, 0));

    ///first will we mark the walls (every odd number of line or column will be in that start mark as wall)

    for (int i = 1; i < nr_lin; i += 2)
        for (int j = 0; j < nr_col; ++j)
            matrix[i][j] = 1;

    for (int i = 0; i < nr_lin; ++i)
        for (int j = 1; j < nr_col; j += 2)
            matrix[i][j] = 1;

    ///create 2 sets of pairs (first element will be the pos of cell, second element will be the pos of parent)
    std::set<std::pair<std::pair<int, int>, std::pair<int, int>>> set_start;
    std::set<std::pair<std::pair<int, int>, std::pair<int, int>>> set_end;
    set_start.insert({{0,  0},
                      {-1, -1}});
    set_end.insert({{nr_lin - 1, nr_col - 1},
                    {-1,         -1}});

    ///neighbors will be the differance between a cell and the neighbor cells and
    ///neighbors_wall will be the differance between the cell and the walls
    std::vector<std::pair<int, int>> neighbors, neighbors_wall;
    neighbors.emplace_back(0, -2);
    neighbors_wall.emplace_back(0, -1);
    neighbors.emplace_back(0, 2);
    neighbors_wall.emplace_back(0, 1);
    neighbors.emplace_back(-2, 0);
    neighbors_wall.emplace_back(-1, 0);
    neighbors.emplace_back(2, 0);
    neighbors_wall.emplace_back(1, 0);

    for (int k = 0; k <= (difficulty + 1) * (difficulty + 1) / 2; ++k) {
        ///for the start set
        try {
            auto [cell, parent] = getRandomElement(set_start);
            ///mark cell as visit
            matrix[cell.first][cell.second] = RED;
            ///mark the wall as visit cell
            for (int i = 0; i < 4; ++i)
                if (parent + neighbors[i] == cell) {
                    matrix[(parent + neighbors_wall[i]).first][(parent + neighbors_wall[i]).second] = RED;
                    break;
                }
            ///delete this node from the list
            set_start.erase({cell, parent});
            ///delete all the pair that contain cell as child
            for (int i = 0; i < 4; ++i) {
                auto neighbor = cell + neighbors[i];
                set_start.erase({cell, neighbor});
                set_end.erase({cell, neighbor});
            }
            ///add the walls that can be remove for now on
            for (int i = 0; i < 4; ++i) {
                auto neighbor = cell + neighbors[i];
                if (inside_cell(neighbor, nr_lin, nr_col) && matrix[neighbor.first][neighbor.second] == 0)
                    set_start.insert({neighbor, cell});
            }
        } catch (...) {
            break;
        }

        ///for the end set
        try {
            ///get a random position from the set
            auto [cell, parent] = getRandomElement(set_end);
            ///mark the cell as visit
            matrix[cell.first][cell.second] = BLUE;
            ///mark the wall as visit cell
            for (int i = 0; i < 4; ++i)
                if (parent + neighbors[i] == cell) {
                    matrix[(parent + neighbors_wall[i]).first][(parent + neighbors_wall[i]).second] = BLUE;
                    break;
                }
            ///delete this pair from the set
            set_end.erase({cell, parent});
            ///delete all the pair that contain cell as child
            for (int i = 0; i < 4; ++i) {
                auto neighbor = cell + neighbors[i];
                set_start.erase({cell, neighbor});
                set_end.erase({cell, neighbor});
            }
            ///add the walls that can be remove for now on
            for (int i = 0; i < 4; ++i) {
                auto neighbor = cell + neighbors[i];
                if (inside_cell(neighbor, nr_lin, nr_col) && matrix[neighbor.first][neighbor.second] == 0)
                    set_end.insert({neighbor, cell});
            }
        } catch (...) {
            break;
        }
    }


    ///now we need to free 2 cells that are between the two colors to create more good paths
    ///search for the free cells
    std::vector<std::pair<int, int>> cells;
    for (int i = 1; i < nr_lin; i += 2)
        for (int j = 0; j < nr_col; j += 2) {
            ///verify for the neighbor rows
            if ((matrix[i - 1][j] == BLUE && matrix[i + 1][j] == RED) ||
                (matrix[i - 1][j] == RED && matrix[i + 1][j] == BLUE))
                cells.emplace_back(i, j);
        }
    for (int i = 0; i < nr_lin; i += 2)
        for (int j = 1; j < nr_col; j += 2) {
            ///verify for the neighbor columns
            if ((matrix[i][j - 1] == BLUE && matrix[i][j + 1] == RED) ||
                (matrix[i][j - 1] == RED && matrix[i][j + 1] == BLUE))
                cells.emplace_back(i, j);
        }

    ///get 2 random cells from this vector
    auto [free1, free2] = getTwoRandomElements(cells);
    matrix[free1.first][free1.second] = RED;
    matrix[free2.first][free2.second] = BLUE;

    ///remake the maze to have 0 all free cells
    for (int i = 0; i < nr_lin; ++i)
        for (int j = 0; j < nr_col; ++j)
            if (matrix[i][j] != 1) matrix[i][j] = 0;

    ///write the maze in 'maze.txt'
    std::ofstream fout("..\\maze.txt");
    for (int i = 0; i < nr_lin; ++i) {
        for (int j = 0; j < nr_col; ++j)
            fout << matrix[i][j] << ' ';
        fout << '\n';
    }
    fout.close();
}

/// \brief Check if a cell is inside the matrix.
/// \param pair position (x,y) of the cell
/// \param lin number of rows in matrix
/// \param col number of columns in matrix
/// \return True - if the cell is inside
bool MazeActions::inside_cell(const std::pair<int, int> &pair, int lin, int col) {
    return pair.first >= 0 && pair.second >= 0 && pair.first < lin && pair.second < col;
}

/// \brief Solve the maze using BFS.
/// \param difficulty difficulty of the level
/// \return the minim number of steps need to reach the finish point in maze without monsters.
int MazeActions::solve(int difficulty) {
    int nr_lin = FactorDifficulty(difficulty);
    int nr_col = FactorDifficulty(difficulty);

    ///read from file the matrix of the maze
    std::ifstream fin ("maze.txt");
    std::vector<std::vector<int>> matrix(nr_lin, std::vector<int>(nr_col));
    for (int i = 0; i < nr_lin; ++i)
        for (int j = 0; j < nr_col; ++j) {
            fin>>matrix[i][j];
            ///mark the walls with -1
            matrix[i][j] = -matrix[i][j];
        }

    ///create an empty queue for the BFS algorithm
    std::queue<std::pair<int, int>> q;

    ///create a vector of difference between position and vectors
    std::vector<std::pair<int, int>> diff;
    diff.emplace_back(0, -1);
    diff.emplace_back(0, 1);
    diff.emplace_back(-1, 0);
    diff.emplace_back(1, 0);

    ///add the start point in the queue
    q.emplace(0, 0);
    matrix[0][0] = 1;

    while (!q.empty()) {
        ///extract first element from the queue and erase that from the queue
        std::pair<int, int> current = q.front(); q.pop();
        std::pair<int, int> neighbor;
        for (auto& d:diff) {
            neighbor = current + d;
            if (inside_cell(neighbor, nr_lin, nr_col) && matrix[neighbor.first][neighbor.second] == 0) {
                q.emplace(neighbor);
                matrix[neighbor.first][neighbor.second] = matrix[current.first][current.second] + 1;
                if (neighbor == std::pair<int, int>(nr_lin -1, nr_col - 1)) return matrix[nr_lin-1][nr_col-1] - 1;
            }
        }
    }
    return 0;
}


/// \brief A function that return a random element from the set
/// \tparam T type of elements from the set
/// \param set1 a std::set of elements
/// \return a random element from the set
template<class T>
T MazeActions::getRandomElement(std::set<T> set1) {
    if (set1.empty()) throw std::invalid_argument("empty set");

    ///Use a random seed from std::random_device
    std::random_device rd;
    std::default_random_engine rng(rd());

    ///Generate a random index within the range of set
    std::uniform_int_distribution<size_t> dist(0, set1.size() - 1);
    size_t randomIndex = dist(rng);
    ///Select the element from the set
    auto it = std::next(set1.begin(), randomIndex);
    return *it;
}

/// \brief A function that return a pair of 2 random element from vector v
/// \tparam T type of elements from the vector v
/// \param v a std::vector
/// \return a pair of 2 elements
template<class T>
std::pair<T, T> MazeActions::getTwoRandomElements(std::vector<T> v) {
    if (v.size() == 1) return {v[0], v[0]};

    ///Use a random seed form std::random_device
    std::random_device rd;
    std::default_random_engine rng(rd());

    std::vector<T> out_vector(2);

    ///generate a sample of 2 elements from the vector
    std::sample(v.begin(), v.end(), out_vector.begin(), 2, rng);

    return {out_vector[0], out_vector[1]};
}

