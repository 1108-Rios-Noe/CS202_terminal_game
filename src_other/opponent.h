#ifndef OPPONENT_H
#define OPPONENT_H
//
#include "gridElement.h"
// class Game;
//class for opponent inherits gridelement to all for this to be added to the 2d array
class Opponent : public GridElement {
    int damage;

    public:
        Opponent();
        Opponent(int);
        Opponent(const Opponent&);
        void process(Player& p) override;
        char symbol() const override;

        ElementType getType() const override;

        void moveRandom(Game& g);
};

#endif