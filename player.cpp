#include <iostream>
#include <cstdlib>
#include "player.h"



// TODO: Implement here the methods of Player and all derived classes

Player::Player(int id)
{
    this->id = id;
    cout << "Give your name: " << endl;
    cin >> name;
    numPieces = 21;
    // numPlacedPieces = 0;
    createPieces();
}

Player::~Player(){
for(int l=0;l<21;l++){
    for(int i=0;i<5;i++){
        for(int k=0;k<5;k++){
            if(pieces[i][k].getId == l){
                pieces[i][k].deleteSquares();
            }
        }
    }
}
}

int Player::getId()
{
    return id;
}

char Player::getSymbol()
{
    if (id == 0)
    {
        return '#';
    }
    else if (id == 1)
    {
        return '0';
    }
}

string Player::getName()
{
    if (id == 0)
    {
        return "Player 1";
    }
    if (id == 1)
    {
        return "Player 2";
    }
}

Piece *Player::getPiece(int index)
{
    for (int i = 0; i < 5; i++)
    {
        for (int k = 0; k < 5; k++)
        {
            if (pieces[i][k].getId() == index)

                return (*(pieces + i) + k);
        }
    }
}

int Player::getNumberOfAvailablePieces()
{
    int counter = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int k = 0; k < 5; k++)
        {
            if (pieces[i][k].isPlaced() == true)
                counter++;
        }
    }
    return counter;
}

HumanPlayer::HumanPlayer(int id):Player(id){
    this->id = id;
}

HumanPlayer::HumanPlayer(int id,string name):Player(id){
    this->name = name;
    this->id=id;
}

ComputerPlayer::ComputerPlayer(int id):Player(id){
    this->id = id;
}

int ComputerPlayer::getRandomPieceId(){
   return (1+rand()%21);
}

Orientation ComputerPlayer::getRandomOrientation(){
    return (rand()%4);
}

Flip ComputerPlayer::getRandomFlip(){
    return(rand()%2);
}