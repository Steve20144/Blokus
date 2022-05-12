#include "piece.h"

// TODO: Implement here the methods of Piece

Piece::Piece()
{
    id = -1;
    pieceSize = 5;
    player = '-';
    placed = false;
}

Piece::Piece(int pieceId, char piecePlayer, char pieceSquares[5][5])
{
    id = pieceId;
    player = piecePlayer;

    for (int i = 0; i < 5; i++)
    {
        for (int k = 0; k < 5; k++)
        {
            if (pieceSquares[i][k] == '#' || pieceSquares[i][k] == 'O')
            {
                squares[i][k].addPiece(pieceSquares[i][k]);
            }
            else
                squares[i][k].addPiece('-');
        }
    }
}

int Piece::getId()
{
    return id;
}

char Piece::getPlayer()
{
    return player;
}

void Piece::setPlaced()
{
    placed = true;
}

bool Piece::isPlaced()
{
    return placed;
}

int Piece::getSize()
{
    return pieceSize;
}

Square Piece::getSquare(int x, int y)
{
    return squares[x][y];
}

bool Piece::squareHasPiece(int x, int y)
{
    if (squares[x][y].getPlayer() != '-')
        return true;
    else
        return false;
}

void Piece::rotatePieceClockwise()
{
    for (int i = 0; i < 2; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            squares[i][4 - k].addPiece(squares[i][k].hasPiece());
        }
    }
}

void Piece::rotatePiece(char orientaion)
{
    if (orientaion == 'u')
    {
    }
}

void Piece::flipPiece()
{
    for (int i = 0; i < 2; i++)
    {
        for (int k = 5; k > 0; k++)
        {
            if (squares[k][i].hasPiece() != '-')
            {
                squares[k][4 - i].addPiece(squares[k][4 - i].hasPiece());
                squares[k][i].addPiece('-');
            }
            else
            {
                squares[k][i].addPiece(squares[k][4 - i].hasPiece());
                squares[k][4 - i].addPiece('-');
            }
        }
    }
}
