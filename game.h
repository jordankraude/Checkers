#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game {
public:
    Game();
    void play();
private:
    Board board;
    Color currentPlayer;
    bool gameOver() const;
    void switchPlayer();
};

#endif // GAME_H
