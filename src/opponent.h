#ifndef OPPONENT_H
#define OPPONENT_H

#include "gridElement.h"
#include "game.h"

class Opponent : public GridElement{
    int x, y;

    public:
        Opponent();
        Opponent(int x, int y);
        Opponent(const Opponent& other);

        void process(Player&) override; //does 30 damage
        void display() const override;

        void moveRandom(Game&); //uses time.h

        friend ostream& operator<<(ostream& os, const Opponent& opp);
        
};

#endif