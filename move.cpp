#include "move.h"

Move::Move(Piece movePiece, int moveX, int moveY, char moveOrientation, char moveFlip)
{
    piece=movePiece;
    x=moveX;
    y=moveY;
    orientation=moveOrientation;
    flip=moveFlip;
}

int Move::getX()
{
    return x;
}
int Move::getY()
{
    return y;
}
char Move::getOrientation()
{
    return orientation;
}
char Move::getFlip()
{
    return flip;
}







// TODO: Implement here the methods of Move
