#include "Piece.h"

Piece::Piece(Color color) : color(color), king(false) {}

Color Piece::getColor() const {
    return color;
}

bool Piece::isKing() const {
    return king;
}

void Piece::makeKing() {
    king = true;
}
