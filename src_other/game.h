#ifndef GAME_H
#define GAME_H
//
#include "dynamicArray.h"
#include "gridElement.h"
#include "emptySpace.h"
#include "trap.h"
#include "treasure.h"
#include "opponent.h"
#include "player.h"

//main class that calls everything else. generated the board with all the needed data
//size of 5, traps 5-7, treasures 5, etc.
class Game {
    DynamicArray<DynamicArray<GridElement*>*>* board; //pointers to rows of gridlement pointers
    Player* player;
    Opponent* opp;
    const int size = 5;
    bool** triggeredTraps;

    public:
        Game();
        Game(DynamicArray<DynamicArray<GridElement*>*>*, Player*, Opponent*, bool**);
        Game(const Game&);
        ~Game();

        DynamicArray<DynamicArray<GridElement*>*>* getBoard();
        Player* getPlayer();
        Opponent* getOpponent();
        int getSize();
        bool** getTriggeredTraps();
        bool getTriggeredTrap(int, int);

        void setBoard(DynamicArray<DynamicArray<GridElement*>*>*);
        void setPlayer(Player*);
        void setOpponent(Opponent*);
        void setTriggeredTraps(bool**);
        void setTriggeredTrap(bool, int x, int y);
        // void setSize(int);

        void generateMap();
        void play();
        void printBoard();

        Game& operator=(const Game&);
};

#endif