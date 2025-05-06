# CS202_terminal_game
A simple game in the terminal
Made using c++
---

The game utilizies C++, stdlib, time, and iostream libraries.
## About The Game
The game creates a 5x5 grid in the terminal that displays a users position. The user can navigate the board by using WASD.
The goal of the game is to gather 3 treasures without losing your health.
The user will initially spawn in the top left and have 100 health. They will lose it over time if they run into a trap or an opponent that moves to a random location after every turn.
If the user runs into a trap, that traps location will be revealed with an X

Traps reduce the users health by 20, while the opponent reduces the health by 30.

This game will use:
- 1 tempalte function.
- At least 4 classes
- 1 abstract class
- At least 1 operator overload
- Every class has an insertion stream overload
- All objects will be dynamically allocated
- All arrays will be dynamically allocated
- Objects or variables that are not arrays should be passed by reference
- Each user move will update the game board

## To-do List
Create h files
- GridElement [DONE]
- EmptySpace [DONE]
- Treasure [DONE]
- Trap [DONE]
- boardArray [MAYBE]
- Opponent [MAYBE]
- Player [MAYBE]
- Game [MAYBE]