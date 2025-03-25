#include "chesspieces.hpp"
#define BOARD_SIZE 8

class Board
{
private:
    Piece *squares[BOARD_SIZE][BOARD_SIZE];

public:
    // Constructor
    Board() { InitializeBoard(); }

    // Deconstructor
    ~Board()
    {
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                delete squares[i][j];
            }
        }
    }

    // Bord initialiseren vanaf startpositie
    void InitializeBoard()
    {
        // Alles op null pointer zetten
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                squares[i][j] = nullptr;
            }
        }

        // Pawn toekennen
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            squares[1][j] = new Pawn(Color::ZWART);
            squares[7][j] = new Pawn(Color::WIT);
        }

        // Overige stukken toekennen
        Color kleuren[] = {Color::ZWART, Color::WIT};
        for (int i : {0, 7})
        {
            Color kleur = kleuren[(i == 0) ? 0 : 1];

            squares[i][0] = new Rook(kleur);
            squares[i][7] = new Rook(kleur);

            squares[i][1] = new Knight(kleur);
            squares[i][6] = new Knight(kleur);

            squares[i][2] = new Bishop(kleur);
            squares[i][5] = new Bishop(kleur);

            squares[i][3] = new Queen(kleur);
            squares[i][4] = new King(kleur);
        }
    }
};