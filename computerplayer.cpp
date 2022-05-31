#include "player.h"
#include "algorithms.h"

ComputerPlayer::ComputerPlayer(int id) : Player(id) {

}

int ComputerPlayer::evaluateBoard(Board* board) {
        // TODO: Implement here the algorithm for evaluating the state of the board

 int total_score=0;
this -> id = id;
for(int i=0;i<14;i++){
    for(int j=0;j<14;j++){
if(squareBelongsToPlayer(i,j,'O') == true)
total_score++;
else if(squareBelongsToPlayer(i,j,'#') == true) 
total_score--;
        
    }
}
if(id == 1)
    return total_score;
else
    return total_score*(-1);
}

Move* ComputerPlayer::makeMove(Board* board) {
    // Get possible moves of all pieces
    int numPossibleMoves;
    Move** possibleMoves = getPossibleMoves(board, numPossibleMoves);

    // Get scores of the possible moves
    int* possibleMovesScores = new int[numPossibleMoves];
    for (int i = 0; i < numPossibleMoves; i++)
        possibleMovesScores[i] = evaluateMove(board, possibleMoves[i]);

    // Get the move to play
    Move* moveToPlay = new Move(getElementWithMaxScore(possibleMoves, possibleMovesScores, numPossibleMoves));

    // Delete the possible moves and the scores
    for (int i = 0; i < numPossibleMoves; i++)
        delete possibleMoves[i];
    delete[] possibleMoves;
    delete[] possibleMovesScores;

    // Return the move to play
    return moveToPlay;
}
