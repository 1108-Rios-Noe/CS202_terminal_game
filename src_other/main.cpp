//
//5/8/2025
//v1.0.1
//this programs creates a 5x5 board game in the terminal allowing the player to move around using WASD
//user can either collect 3 treasures and win or lose all their health by hiting a trap or opponent
#include "./game.h"

int main(){
    while (true){
        Game *game = new Game();
        game->play();
        delete game;

        cout << "\nPlay again? (Y/N): ";
        char c;
        cin >> c;
        
        if (toupper(c) != 'Y') break; //stops the while(true)
            
    }
    return 0;
}