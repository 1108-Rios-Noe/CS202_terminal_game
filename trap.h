#ifndef TRAP_H
#define TRAP_H

#include "gridElement.h"
using namespace std;

class Treasure : public GridElement{
    public:
        void process(Player& p) override;
        void display() const override;
};

#endif