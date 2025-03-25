#include <iostream>
#include <vector>

enum class Color
{
    WIT,
    ZWART
};

enum class PieceType
{
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING,
    NONE
};

class Piece
{
protected:
    Color m_kleur;
    PieceType m_type;
    char m_symbol;

    Piece(Color c, PieceType t) : m_kleur{c}, m_type{t} {}

public:
    virtual ~Piece() = default;

    Color GetColor() const { return m_kleur; }
    PieceType GetType() const { return m_type; }
    char GetSymbol() const { return m_symbol; }

    virtual bool IsMoveValid(int x1, int y1, int x2, int y2);
};

class Pawn : public Piece
{
private:
    bool HasMoved;

public:
    Pawn(Color c) : Piece(c, PieceType::PAWN), HasMoved{false}
    {
        m_symbol = (c == Color::ZWART) ? 'p' : 'P';
    }

    bool IsMoveValid(int x1, int y1, int x2, int y2) override
    {
        int direction = (m_kleur == Color::WIT) ? -1 : 1;

        if (!HasMoved && y1 == y2 && (x2 == x1 + 2 * direction || x2 == x1 + direction))
        {
            HasMoved = true;
            return true;
        }

        if (y1 == y2 && x2 == x1 + direction)
        {
            return true;
        }

        return false;
    }
};

class Rook : public Piece
{
public:
    Rook(Color c) : Piece(c, PieceType::ROOK)
    {
        m_symbol = (c == Color::ZWART) ? 'r' : 'R';
    }

    bool IsMoveValid(int x1, int y1, int x2, int y2) override
    {
        return (x1 == x2 || y1 == y2);
    }
};

class Knight : public Piece
{
public:
    Knight(Color c) : Piece(c, PieceType::KNIGHT)
    {
        m_symbol = (c == Color::ZWART) ? 'n' : 'N';
    }

    bool IsMoveValid(int x1, int y1, int x2, int y2) override
    {
        return (abs(x1 - x2) == 2 && abs(y1 - y2) == 1) || (abs(x1 - x2) == 1 && abs(y1 - y2) == 2);
    }
};

class Bishop : public Piece
{
public:
    Bishop(Color c) : Piece(c, PieceType::BISHOP)
    {
        m_symbol = (c == Color::ZWART) ? 'b' : 'B';
    }

    bool IsMoveValid(int x1, int y1, int x2, int y2) override
    {
        return abs(x1 - x2) == abs(y1 - y2);
    }
};

class Queen : public Piece
{
public:
    Queen(Color c) : Piece(c, PieceType::QUEEN)
    {
        m_symbol = (c == Color::ZWART) ? 'q' : 'Q';
    }

    bool IsMoveValid(int x1, int y1, int x2, int y2) override
    {
        return (x1 == x2 || y1 == y2) || (abs(x1 - x2) == abs(y1 - y2));
    }
};

class King : public Piece
{
public:
    King(Color c) : Piece(c, PieceType::KING)
    {
        m_symbol = (c == Color::ZWART) ? 'k' : 'K';
    }

    bool IsMoveValid(int x1, int y1, int x2, int y2) override
    {
        return abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1;
    }
};
