#include "game.h"

int main(){
    while(true){
        Game* game = new Game();
        game->play();
        delete game;
        char choice;
        cout << "Do you want to play again? (y/n)";
        cin >> choice;
        if(toupper(choice) != 'Y') break;
    }

    return 0;
}