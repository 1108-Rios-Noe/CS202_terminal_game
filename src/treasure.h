#ifndef TREASURE_H
#define TREASURE_H

#include "gridElement.h"
using namespace std;

class Treasure : public GridElement{
    public:
        void process(Player& p) override;
        void display() const override;

        friend ostream& operator<<(ostream&, const Treasure&);
};

#endif