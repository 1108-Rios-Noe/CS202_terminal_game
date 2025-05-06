#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "opponent.h"
#include "gridElement.h"
#include "boardArray.h"

class Game{
    boardArray<GridElement*>* board;
    Player* player;
    Opponent* opponent;
    const int size = 5;
    bool **visitedTraps; //vistedTraps[y][x] or is it [x][y]

    public:
    Game();
    Game(int size);
    Game(const Game& other);
    ~Game();

    void setBoard(boardArray<GridElement*>* board);
    void setPlayer(Player* player);
    void setOpponent(Opponent* opponent);
    void setVisitedTrap(int, int, bool);

    boardArray<GridElement*>* getBoard() const;
    Player* getPlayer() const;
    Opponent* getOpponent() const;
    bool** getVisitedTrap(int, int) const;

    void generateMap();
    void play();

    friend ostream& operator<<(ostream& os, const Game& game);


};

#endif