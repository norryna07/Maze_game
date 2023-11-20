//
// Created by Norina Alexandru on 11/19/2023.
// Sentry Paws is the first type of monster. He stays in one spot, keeping a watchful eye on the surroundings.
//

#ifndef OOP_SENTRYPAWS_HPP
#define OOP_SENTRYPAWS_HPP


#include "../Monster.hpp"

/// \brief Represents the stationary monster. He stays in one spot, keeping a watchful eye on the surroundings.
class SentryPaws: public Monster{
    static Cell_mode type;
public:
    SentryPaws(unsigned int x, unsigned int y);

    void move(Maze &maze) override;
};

Cell_mode SentryPaws::type = SENTRY_PAWS;


#endif //OOP_SENTRYPAWS_HPP
