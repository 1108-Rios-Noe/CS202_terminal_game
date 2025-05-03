#ifndef GRIDELEMENT_H
#define GRIDELEMENT_H

#include "player.h"
#include <iostream>
using namespace std;

//abstract class for trap, treasure, empty space
class GridElement{

    public:
        virtual void process(Player&) = 0;
        virtual void display() const = 0;
        virtual ~GridElement(){};

        friend ostream& operator<<(ostream& os, const GridElement& element){
            os << element.display();
            return os;
        }
};

#endif