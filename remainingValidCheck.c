#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "othello.h"

bool remainingValidCheck(struct Game *g)             // CKECKS TO SEE IF ANY VALID MOVES REMAIN
{
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if (g->board[i][j] == ' '){
            
    if (validMoveCheck(g, i + 1,'a' + j) == true){           // CALLS THE FUNCTION WHICH CHECKS FOR REMAINING SPACES AND RETURNS A BOOL
        return true;
    }
    }
}
}
    g->validMoves = noPossibleMoves;                 // IF validMoves RETURN THE ENUM noPossibleMoves, remainingValidCheck WILL RETURN FALSEs
    return false;
}