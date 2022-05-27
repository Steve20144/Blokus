#include "board.h"
#include "player.h"

// TODO: Implement here the method pieceCanBePlaced and computeScore of Board
// Do not implement any other methods of Board (as they are already implemented in file board.cpp)

bool Board::pieceCanBePlaced(Piece *piece, int x, int y)
{
    if (playerHasPlacedNoPieces('#') && x == 4 && y == 4)
        return true;
    else
        return false;
    if (playerHasPlacedNoPieces('O') && x == 9 && y == 9)
        return true;
    else
        return false;

    if (!playerHasPlacedNoPieces('#') && (squareBelongsToPlayer(x + 1, y + 1, '#') || squareBelongsToPlayer(x - 1, y - 1, '#') || squareBelongsToPlayer(x - 1, y + 1, '#') || squareBelongsToPlayer(x + 1, y + 1, '#')))
        return true;
    else
        return false;

    if (!playerHasPlacedNoPieces('O') && (squareBelongsToPlayer(x + 1, y + 1, 'O') || squareBelongsToPlayer(x - 1, y - 1, 'O') || squareBelongsToPlayer(x - 1, y + 1, 'O') || squareBelongsToPlayer(x + 1, y + 1, 'O')))
        return true;
    else
        return false;

    if (x < 13 && y < 13)
        return true;
    else
        return false;

    if ()
}

int Board::computeScore(Player *player)
{
    // a point is given when :
    // A.When the player places a piece
    // B.When the player has placed all his pieces, 15 more points are added to his score
    //  C.If the player has placed all of his pieces but the last piece he placed was the smallest one // he earns an extra of 5 points

    int pointSum = 0;

    pointSum += player->getNumberOfPlacedPieces();
    if (player->getNumberOfAvailablePieces() == 0)
        pointSum += 15;

    if (getLastPiecePlayedByPlayer(player)->getId() == 1)
        pointSum += 5;

    return pointSum;
}
