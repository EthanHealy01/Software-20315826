#ifndef OTHELLO_DOT_H
#define OTHELLO_DOT_H

enum ValidMoveDirection // ENUMERATIONS FOR TESTING DIAGONALS, COLUMNS AND ROWS
{
    noPossibleMoves,           
    rowUp,
    rowDown,
    colUp,
    colDown,
    upLeft,
    upRight,
    downLeft,
    downRight

};

struct Players // PLAYER STRUCT
{
    char p1[30];        // PLAYER ONE'S NAME
    int p1Score;        // PLAYER ONE'S SCORE

    char p2[30];        // PLAYER TWO'S NAME
    int p2Score;        // PLAYER TWO'S SCORE
};

struct Game // BOARD AND GAME DETAILS STRUCT
{
    enum ValidMoveDirection validMoves;         
    char board[8][8];       // THE BOARD AND IT'S DIMENSIONS 
    char move;          // EACH MOVE
};

void endGame(struct Game *g, struct Players *p);            // CARRIES OUT THE END OF GAME PROTOCOL 

void positionChecker(struct Game *g, int row, char column);         // IF THE MOVE IS VALID, CHANGE THE COLOUR OF THE FLANKED PIECE

bool gameOverBool(struct Game *g);                      // RUNS THE FOLLOWING FUNCTION TO SEE IF ANY PLAYER STILL HAS A VALID MOVE V V V

bool remainingValidCheck(struct Game *g);                   // SEES IF ANY VALID MOVES REMAIN

bool validMoveCheck(struct Game *g, int row, char column);              // CHECKS IF THE CHOSEN MOVE IS VALID OR NOT

void boardPrint(FILE *file, struct Game *g, struct Players *p);             // PRINTS THE BOARD AND UPDATES/PRINTS SCORE

void startGame(struct Game *g, struct Players *p, const char *p1, const char *p2);              // PRINTS THE STARTING BOARD AND STARTS PLAYERS SCORE OFF AT 2:2

#endif