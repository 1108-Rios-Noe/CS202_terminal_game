#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "opponent.h"
#include "gridElement.h"
#include "boardArray.h"
#include "emptyspace.h"
#include "trap.h"
#include "treasure.h"


class Game{
    BoardArray<GridElement*>* board;
    Player* player;
    Opponent* opponent;
    const int size = 5;
    bool **visitedTraps; //vistedTraps[y][x] or is it [x][y]

    public:
    Game();
    Game(int size);
    Game(const Game& other);
    ~Game();

    void setBoard(BoardArray<GridElement*>* board);
    void setPlayer(Player* player);
    void setOpponent(Opponent* opponent);
    void setVisitedTrap(int, int, bool);

    BoardArray<GridElement*>* getBoard() const;
    Player* getPlayer() const;
    Opponent* getOpponent() const;
    bool** getVisitedTrap(int, int) const;

    void generateMap();
    void play();

    friend ostream& operator<<(ostream& os, const Game& game);


};

#endif