#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"

class Board {
public:
    Board();
    void print() const;
    bool movePiece(int fromY, int fromX, int toY, int toX);
    bool canContinueCapturing(int fromY, int fromX) const;  // Ensure this is public
private:
    Piece board[8][8];
    bool isValidMove(int fromY, int fromX, int toY, int toX) const;
    bool isCaptureMove(int fromY, int fromX, int toY, int toX) const;
    void performCapture(int fromY, int fromX, int toY, int toX);
};

#endif // BOARD_H
