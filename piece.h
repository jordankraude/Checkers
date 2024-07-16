#ifndef PIECE_H
#define PIECE_H

enum class Color { NONE, RED, BLACK };

class Piece {
public:
    Piece(Color color = Color::NONE);
    Color getColor() const;
    bool isKing() const;
    void makeKing();
private:
    Color color;
    bool king;
};

#endif // PIECE_H
