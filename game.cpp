#include "game.h"
#include <iostream>

Game::Game() : currentPlayer(Color::RED) {}

void Game::play() {
    while (!gameOver()) {
        board.print();
        int fromY, fromX, toY, toX;
        bool continueCapturing = true;

        while (continueCapturing) {
            std::cout << "Player " << (currentPlayer == Color::RED ? "RED" : "BLACK") << "'s turn." << std::endl;
            std::cout << "Enter move (fromY fromX toY toX): ";
            std::cin >> fromY >> fromX >> toY >> toX;

            if (board.movePiece(fromY, fromX, toY, toX)) {
                if (board.canContinueCapturing(toY, toX)) {
                    std::cout << "You can continue capturing. Enter another move or choose to end your turn." << std::endl;
                } else {
                    continueCapturing = false;
                }
            } else {
                std::cout << "Invalid move. Try again." << std::endl;
            }
        }

        switchPlayer();
    }

    std::cout << "Game over!" << std::endl;
}

bool Game::gameOver() const {
    // Simple game over condition (could be improved)
    return false;
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == Color::RED) ? Color::BLACK : Color::RED;
}
