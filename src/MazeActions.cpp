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

    ///will create 2 vectors, one that will be used from start point and one that will be use from the finish point
    std::set<std::pair<int, int> > list_start;
    std::set<std::pair<int, int> > list_finish;
    list_start.clear();
    list_finish.clear();
    list_start.emplace(0, 0);
    list_finish.emplace(nr_lin - 1, nr_col - 1);

    ///because using the full cell being a wall the neighbor will be at 2 position distance
    std::vector<std::pair<int, int> > neighbors;
    neighbors.emplace_back(-2, 0);
    neighbors.emplace_back(2, 0);
    neighbors.emplace_back(0, 2);
    neighbors.emplace_back(0, -2);

    ///add every steps we delete a cell from every list and add their non-visit neighbor
    ///we will have (difficulty+1)^2 free cell to add to the maze but will be split in 2
    for (int k = 0; k <= (difficulty + 1) * (difficulty + 1) / 2; ++k) {

        ///extract a random cell from start list
        std::pair<int, int> current, neighbor_position;
        current = getRandomElement(list_start);
        if (current.first == -1) break;
        ///delete the cell from the start list
        list_start.erase(current);
        ///set the cell being visit by the start position
        matrix[current.first][current.second] = RED;
        ///delete the cell if it is in the finish list
        if (list_finish.find(current) != list_finish.end()) list_finish.erase(current);
        ///add the neighbors
        for (auto &neighbor: neighbors) {
            neighbor_position = current + neighbor;
            if (inside_cell(neighbor_position, nr_lin, nr_col))
                if (matrix[neighbor_position.first][neighbor_position.second] == 0) list_start.emplace(neighbor_position);
        }

        ///make the same for the finish list
        current = getRandomElement(list_finish);
        ///if the number of free cell is odd then the last step will be just for the start list
        if (current.first == -1) break;
        ///delete the cell from the finish list
        list_finish.erase(current);
        ///mark the cell
        matrix[current.first][current.second] = BLUE;
        ///delete the cell if is in the start list
        if (list_start.find(current) != list_start.end()) list_start.erase(current);
        ///add the neighbor
        for (auto &neighbor: neighbors) {
            neighbor_position = current + neighbor;
            if (inside_cell(neighbor_position, nr_lin, nr_col))
                if (matrix[neighbor_position.first][neighbor_position.second] == 0) list_finish.emplace(neighbor_position);
        }
    }

    ///now will remove the walls between 2 cells that have the same color
    for (int i = 1; i < nr_lin; i += 2)
        for (int j = 0; j < nr_col; j += 2) {
            ///verify for the neighbor rows
            if (matrix[i - 1][j] == matrix[i + 1][j]) matrix[i][j] = matrix[i - 1][j];
        }
    for (int i = 0; i < nr_lin; i += 2)
        for (int j = 1; j < nr_col; j += 2) {
            ///verify for the neighbor columns
            if (matrix[i][j-1] == matrix[i][j+1]) matrix[i][j] = matrix[i][j-1];
        }

    ///now we need to free 2 cells that are between the two colors to create more good paths
    ///search for the free cells
    std::vector<std::pair<int, int>> cells;
    for (int i = 1; i < nr_lin; i += 2)
        for (int j = 0; j < nr_col; j += 2) {
            ///verify for the neighbor rows
            if ((matrix[i - 1][j] == BLUE &&  matrix[i + 1][j] == RED) ||
                (matrix[i - 1][j] == RED &&  matrix[i + 1][j] == BLUE)) cells.emplace_back(i, j);
        }
    for (int i = 0; i < nr_lin; i += 2)
        for (int j = 1; j < nr_col; j += 2) {
            ///verify for the neighbor columns
            if ((matrix[i][j-1] == BLUE && matrix[i][j+1] == RED) ||
                (matrix[i][j-1] == RED && matrix[i][j+1] == BLUE)) cells.emplace_back(i, j);
        }

    ///get 2 random cells from this vector
    auto [free1, free2] = getTwoRandomElements(cells);
    matrix[free1.first][free1.second] = RED;
    matrix[free2.first][free2.second] = BLUE;

    ///remake the maze to have 0 all free cells
    for (int i = 0; i < nr_lin; ++i)
        for (int j = 0; j < nr_col; ++j)
            if (matrix[i][j] != 1) matrix[i][j] = 0;

    ///now we have to add monster is the difficulty level is high

    ///write the maze in 'maze.txt'
    std::ofstream fout("..\\maze.txt");
    for (int i = 0; i < nr_lin; ++i) {
        for (int j = 0; j < nr_col; ++j)
            fout << matrix[i][j] << ' ';
        fout << '\n';
    }
}
/// \brief Check if a cell is inside the matrix.
/// \param pair position (x,y) of the cell
/// \param lin number of rows in matrix
/// \param col number of columns in matrix
/// \return True - if the cell is inside
bool MazeActions::inside_cell(std::pair<int, int> &pair, int lin, int col) {
    return pair.first >= 0 && pair.second >= 0 && pair.first < lin && pair.second < col;
}


/// \brief A function that return a random element from the set
/// \tparam T type of elements from the set
/// \param set1 a std::set of elements
/// \return a random element from the set
template <class T> T MazeActions::getRandomElement(std::set<T> set1) {
    if (set1.empty()) return {-1, -1};

    ///Use a random seed from std::random_device
    std::random_device rd;
    std::default_random_engine  rng(rd());

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
template <class T> std::pair<T, T> MazeActions::getTwoRandomElements(std::vector<T> v) {
    if (v.size() == 1) return {v[0], v[0]};

    ///Use a random seed form std::random_device
    std::random_device rd;
    std::default_random_engine rng(rd());

    std::vector<T> out_vector(2);

    ///generate a sample of 2 elements from the vector
    std::sample(v.begin(), v.end(), out_vector.begin(), 2, rng);

    return {out_vector[0], out_vector[1]};
}

