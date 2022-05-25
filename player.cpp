#include <iostream>
#include <cstdlib>
#include "player.h"

// TODO: Implement here the methods of Player and all derived classes

Player::Player(int id)
{
    this -> id = id;
    cout << "Give your name: " << endl;
    cin >> name;
    numPieces = 21;
    numPlacedPieces = 0;
    createPieces();
}

int Player::getId()
{
     return id;
}

char Player::getSymbol()
{
    if(id == 0)
    {
        return '#';
    }
    else if(id == 1)
    {
        return '0';
    }
}

string Player::getName()
{
    if(id == 0) 
    {
        return "Player 1";
    }
    if(id == 1)
    {
        return "Player 2";
    }
}

Piece* Player::getPiece(int index)
{
    pieces(index);
}


int Player::getNumberOfAvailablePieces()
{
    return 21 - numPlacedPieces;
}

