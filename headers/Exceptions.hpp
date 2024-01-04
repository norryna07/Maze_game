//
// Created by Norina Alexandru on 11/24/2023.
// A file for define exceptions that will be used in that project
//

#ifndef OOP_EXCEPTIONS_HPP
#define OOP_EXCEPTIONS_HPP

#include <exception>
#include <stdexcept>

/// \brief Exception for trying to access a maze cell that is out of range.
class OutMatrixException : public std::logic_error {
public:
    explicit OutMatrixException(const std::string &arg) : logic_error(arg) {}
};

/// \brief Exception for trying to move a character in a cell that is block (a wall cell)
class BlockedCellException : public std::logic_error {
public:
    explicit BlockedCellException(const std::string &arg) : logic_error(arg) {}
};

/// \brief Exception class for losing the game. You can lose the game if the player try to move in a cell where is a monster, or a monster move on player.
class GameOverException : public std::runtime_error {
public:
    explicit GameOverException(const std::string &arg) : runtime_error(arg) {}
};

class GameWinException : public std::runtime_error {
public:
    explicit GameWinException(const std::string &arg) : runtime_error(arg) {}
};

class InterruptFlag : public std::runtime_error {
public:
    explicit InterruptFlag(const std::string &arg) : runtime_error(arg) {}
};

#endif //OOP_EXCEPTIONS_HPP
