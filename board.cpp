#include "Board.h"
#include <iostream>

Board::Board() {
    // Initialize the board with pieces
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 == 1) {
                if (i < 3) {
                    board[i][j] = Piece(Color::BLACK);
                } else if (i > 4) {
                    board[i][j] = Piece(Color::RED);
                } else {
                    board[i][j] = Piece(Color::NONE);
                }
            } else {
                board[i][j] = Piece(Color::NONE);
            }
        }
    }
}

void Board::print() const {
    std::cout << "   0 1 2 3 4 5 6 7\n";
    std::cout << "  -----------------\n";
    for (int i = 0; i < 8; ++i) {
        std::cout << i << " | ";
        for (int j = 0; j < 8; ++j) {
            if (board[i][j].getColor() == Color::BLACK) {
                std::cout << "B ";
            } else if (board[i][j].getColor() == Color::RED) {
                std::cout << "R ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << '\n';
    }
    std::cout << "  -----------------\n";
}

bool Board::movePiece(int fromY, int fromX, int toY, int toX) {
    if (!isValidMove(fromY, fromX, toY, toX)) {
        return false;
    }

    bool isCapture = isCaptureMove(fromY, fromX, toY, toX);
    if (isCapture) {
        performCapture(fromY, fromX, toY, toX);
    } else {
        board[toY][toX] = board[fromY][fromX];
        board[fromY][fromX] = Piece(Color::NONE);
    }

    // Check for kinging
    if (toY == 0 && board[toY][toX].getColor() == Color::RED) {
        board[toY][toX].makeKing();
    } else if (toY == 7 && board[toY][toX].getColor() == Color::BLACK) {
        board[toY][toX].makeKing();
    }

    // Allow additional captures if available
    if (canContinueCapturing(toY, toX)) {
        return true; // Continue the turn if another capture is possible
    }

    return true; // End the turn if no additional captures are possible
}

bool Board::isValidMove(int fromY, int fromX, int toY, int toX) const {
    if (toY < 0 || toY >= 8 || toX < 0 || toX >= 8) {
        return false;
    }

    if (board[toY][toX].getColor() != Color::NONE) {
        return false;
    }

    if (board[fromY][fromX].getColor() == Color::NONE) {
        return false;
    }

    int dy = toY - fromY;
    int dx = toX - fromX;

    if (abs(dx) != 1 && abs(dx) != 2) {
        return false;
    }

    if (abs(dy) != 1 && abs(dy) != 2) {
        return false;
    }

    return !isCaptureMove(fromY, fromX, toY, toX);
}

bool Board::isCaptureMove(int fromY, int fromX, int toY, int toX) const {
    int dy = toY - fromY;
    int dx = toX - fromX;

    if (abs(dy) == 2 && abs(dx) == 2) {
        int midY = fromY + dy / 2;
        int midX = fromX + dx / 2;
        return board[midY][midX].getColor() != board[fromY][fromX].getColor() &&
               board[midY][midX].getColor() != Color::NONE;
    }
    
    return false;
}

void Board::performCapture(int fromY, int fromX, int toY, int toX) {
    int midY = fromY + (toY - fromY) / 2;
    int midX = fromX + (toX - fromX) / 2;
    board[toY][toX] = board[fromY][fromX];
    board[fromY][fromX] = Piece(Color::NONE);
    board[midY][midX] = Piece(Color::NONE);
}

bool Board::canContinueCapturing(int fromY, int fromX) const {
    for (int dy = -2; dy <= 2; dy += 4) {
        for (int dx = -2; dx <= 2; dx += 4) {
            int toY = fromY + dy;
            int toX = fromX + dx;
            if (toY >= 0 && toY < 8 && toX >= 0 && toX < 8) {
                if (isCaptureMove(fromY, fromX, toY, toX)) {
                    return true;
                }
            }
        }
    }
    return false;
}
