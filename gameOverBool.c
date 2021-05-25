#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "othello.h"

bool gameOverBool(struct Game *g){ // IF NO PLAYER CAN PLAY, GAME ENDS

    char player = g->move;

    g->move = 'B';                  // FOR BLACKS TURN
    if (remainingValidCheck(g)){                  // CHECK IF ANY MOVES REMAIN
    
        g->move = player;            
        return false;                   // IF MOVES REMAIN THE GAME WON'T END
    }
    g->move = 'W';                  // FOR WHITES TURN
    if (remainingValidCheck(g)){                  // CHECK IF ANY MOVES REMAIN
        g->move = player;            
        return false;                   
    }
    g->move = player;            
    return true;                            // IF NO POSSIBLE MOVES, THE GAME WILL END
}
