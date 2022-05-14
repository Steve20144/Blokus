#include <iostream>
#include "player.h"

// TODO: Implement here the methods of Player

Player::Player(int playerId)
{
    id = playerId;
    cout << "Give your name: " << endl;
    cin >> name;
    numPlacedPieces = 0;
    createPieces();
}

string Player::getName()
{
    return name;
}

Piece Player::getPiece(int index)
{
    return pieces[index];
}

int Player::getNumberOfAvailablePieces()
{
    return 21 - numPlacedPieces;
}
