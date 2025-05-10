#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "game.h"

Game::Game(){
    srand(time(NULL));

    player = new Player();
    opp = new Opponent();
    board = new DynamicArray<DynamicArray<GridElement *> *>(size);
    triggeredTraps = new bool*[size];

    for(int i = 0; i < size; i++){
        triggeredTraps[i] = new bool[size];
    }

    for(int i = 0; i < size; i++){
        DynamicArray<GridElement*> *row = new DynamicArray<GridElement *>(size);
        for(int j = 0; j < size; j++){
            row->operator[](j) = new EmptySpace();
        }
        board->operator[](i) = row;
    }

    generateMap();
}
//parameterized never used
Game::Game(DynamicArray<DynamicArray<GridElement*>*>* b, Player* p, Opponent* o, bool** tt){
    board = b;
    player = p;
    opp = o;
    triggeredTraps = tt;

    generateMap();
}
//copy never used
Game::Game(const Game& g){
    player = g.player;
    opp = g.opp;
    // board = g.board;
    board = new DynamicArray<DynamicArray<GridElement *> *>(size);
    for(int i = 0; i < size; i++){ //[j][i] same as [y][x]
        for(int j = 0; j < size; j++){
            board->operator[](j)->operator[](i) = g.board->operator[](j)->operator[](i);
        }
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            triggeredTraps[i][j] = g.triggeredTraps[i][j];
        }
    }

    generateMap();
}

Game::~Game(){
    for(int i = 0; i < size; i++){
        delete [] triggeredTraps[i];
    }

    for(int i = 0; i < size; i++){
        DynamicArray<GridElement *> *row = board->operator[](i);

        for (int j = 0; j < size; j++){
            if(row->operator[](j) != opp){
                delete row->operator[](j);
            }
        }
        delete row;
    }
    delete [] triggeredTraps;
    delete opp;
    delete player;
    delete board;
}

DynamicArray<DynamicArray<GridElement*>*>* Game::getBoard(){
    return board;
}
Player* Game::getPlayer(){
    return player;
}
Opponent* Game::getOpponent(){
    return opp;
}
int Game::getSize(){
    return size;
}
bool** Game::getTriggeredTraps(){
    return triggeredTraps;
}
bool Game::getTriggeredTrap(int x, int y){
    return triggeredTraps[x][y];
}
void Game::setBoard(DynamicArray<DynamicArray<GridElement*>*>* b){
    board = b;
}
void Game::setPlayer(Player* p){
    player = p;
}
void Game::setOpponent(Opponent* o){
    opp = o;
}
void Game::setTriggeredTraps(bool** t){
    triggeredTraps = t;
}
void Game::setTriggeredTrap(bool v, int x, int y){
    triggeredTraps[x][y] = v;
    // cout << "Trap was updated at: " << x << "," << y << endl;
}

void Game::generateMap(){
    int t = 0;
    int numTraps = 5 + rand() % 3; //random number of traps between either 5-7

    while (t < numTraps){
        int i = rand() % size, j = rand() % size;

        if(board->operator[](i)->operator[](j)->getType() == EMPTY){
            delete board->operator[](i)->operator[](j);
            board->operator[](i)->operator[](j) = new Trap(); //[i][j] same as [y][x] also this replaces old element with new
            t++;
            setTriggeredTrap(false, j, i);
        }

        // if(i || j){
        //     if(board->operator[](i)->operator[](j)->getType() == EMPTY){
        //         delete board->operator[](i)->operator[](j);
        //         board->operator[](i)->operator[](j) = new Trap(); //[i][j] same as [y][x]
        //         t++;
        //     }
        // }
    }
    int tr = 0;
    while (tr < 5){
        int i = rand() % size, j = rand() % size;

        if(board->operator[](i)->operator[](j)->getType() == EMPTY){
            delete board->operator[](i)->operator[](j);
            board->operator[](i)->operator[](j) = new Treasure();
            tr++;
        }

        // if (i || j){
        //     if (board->operator[](i)->operator[](j)->getType() == EMPTY){
        //         delete board->operator[](i)->operator[](j);
        //         board->operator[](i)->operator[](j) = new Treasure();
        //         tr++;
        //     }
        // }
    }
    while (true){ //not sure if while true allowed but break is used to stop it
        int i = rand() % size, j = rand() % size;

        if (board->operator[](i)->operator[](j)->getType() == EMPTY){
            delete board->operator[](i)->operator[](j);
            board->operator[](i)->operator[](j) = opp;
            break;
        }

        // if (i || j){
        //     if (board->operator[](i)->operator[](j)->getType() == EMPTY){
        //         delete board->operator[](i)->operator[](j);
        //         board->operator[](i)->operator[](j) = opp;
        //         break;
        //     }
        // }
    }
}

void Game::printBoard(){
    // system("clear");

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (player->getX() == j && player->getY() == i){
                cout << 'P';
            }
            else {
                if(board->operator[](i)->operator[](j)->getType() == TRAP && getTriggeredTrap(j,i)){ //[j][i]
                    cout << board->operator[](i)->operator[](j)->symbol();
                }else {
                    // cout << board->operator[](i)->operator[](j)->symbol(); //debugging purposes
                    cout << ".";
                }
            }
            cout << ' ';
        }
        cout << "\n";
    }
}

void Game::play(){
    while (player->isAlive() && !player->hasWon()){
        
        system("clear"); //probs the best spot to put it.

        cout << *player << "\n";
        printBoard();
        cout << "Move (WASD): ";
        char c;
        // system("clear");
        // cout << "This was the chosen char: " << c << endl;

        cin >> c;
        player->move(toupper(c), *this); //pass the game reference
        opp->moveRandom(*this);
    }
    if (player->hasWon()){
        cout << "You have WON!\n";
    }
    else
        cout << "Game Over!\n";
}

Game& Game::operator=(const Game& g){
    player = g.player;
    opp = g.opp;
    // board = g.board;
    for(int i = 0; i < size; i++){ //[j][i] same as [y][x]
        for(int j = 0; j < size; j++){
            board->operator[](j)->operator[](i) = g.board->operator[](j)->operator[](i);
        }
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            triggeredTraps[i][j] = g.triggeredTraps[i][j];
        }
    }

    return *this;
}