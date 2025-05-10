#include "game.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

Game::Game() {
    board = new BoardArray<GridElement*>();
    player = new Player();
    opponent = new Opponent();
    visitedTraps = new bool*[size];
    for (int i = 0; i < size; i++) {
        visitedTraps[i] = new bool[size];
        for (int j = 0; j < size; j++) {
            visitedTraps[i][j] = false;
        }
    }
}

Game::~Game() {
    delete board;
    delete player;
    delete opponent;
    for (int i = 0; i < size; i++) {
        delete[] visitedTraps[i];
    }
    delete[] visitedTraps;
}

void Game::setBoard(BoardArray<GridElement*>* board_) {
    board = board_;
}

void Game::setPlayer(Player* player_) {
    player = player_;
}

void Game::setOpponent(Opponent* opponent_) {
    opponent = opponent_;
}

void Game::setVisitedTrap(int x, int y, bool visited) {
    visitedTraps[y][x] = visited;
}

BoardArray<GridElement*>* Game::getBoard() const {
    return board;
}

Player* Game::getPlayer() const {
    return player;
}

Opponent* Game::getOpponent() const {
    return opponent;
}

bool** Game::getVisitedTrap(int x, int y) const {
    return visitedTraps;
}

void Game::generateMap() {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int random = rand() % 3;
            if (random == 0) {
                board->setDataXY(i, j, new EmptySpace());
            } else if (random == 1) {
                board->setDataXY(i, j, new Treasure());
            } else {
                board->setDataXY(i, j, new Trap());
            }
        }
    }
}

void Game::play() {
    generateMap();
    player->setX(0);
    player->setY(0);
    opponent->moveRandom(*this);

    while (player->isAlive() && !player->hasWon()) {
        cout << *board << endl;
        cout << *player << endl;
        cout << *opponent << endl;

        char move;
        cout << "Enter your move (w/a/s/d): ";
        cin >> move;

        player->move(move, *this);
        opponent->moveRandom(*this);
    }

    if (player->isAlive()) {
        cout << "You won!" << endl;
    } else {
        cout << "You lost!" << endl;
    }
}

ostream& operator<<(ostream& os, const Game& game) {
    os << "Game State:" << endl;
    os << game.board << endl;
    os << game.player << endl;
    os << game.opponent << endl;
    return os;
}