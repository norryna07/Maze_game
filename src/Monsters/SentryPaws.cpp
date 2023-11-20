//
// Created by norin on 11/19/2023.
//

#include "../../headers/Monsters/SentryPaws.hpp"

Cell_mode SentryPaws::type = SENTRY_PAWS;

SentryPaws::SentryPaws(unsigned int x, unsigned int y) : Monster(x, y) {
}

/// \brief  Move function is empty because the Sentry Paws stays in a single place.
/// \param maze where the monster moves
void SentryPaws::move(Maze &maze) {

}
