#ifndef EMPTYSPACE_H
#define EMPTYSPACE_H

#include "gridElement.h"
using namespace std;

class EmptySpace : public GridElement{
    public:
        void process(Player& p) override;
        void display() const override;

        friend ostream& operator<<(ostream&, const EmptySpace&);
};

#endif