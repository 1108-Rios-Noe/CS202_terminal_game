#ifndef TRAP_H
#define TRAP_H

#include "gridElement.h"
using namespace std;

class Trap : public GridElement{
    public:
        void process(Player& p) override;
        void display() const override;

        friend ostream& operator<<(ostream&, const Trap&);
};

#endif