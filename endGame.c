#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "othello.h"

void endGame(struct Game *g, struct Players *p)                  //PRINTS FINAL RESULTS
{
    FILE *f = fopen("othello.txt", "a");
    time_t now;       // GETS THE TIME
    time(&now);
    const char *thisTime = ctime(&now);             // INITIALIZE TIME STRING
                                     
    if (p->p1Score > p->p2Score){                   // CHECKS TO SEE WHO HAS MORE PONTS
    
        fprintf(f, "Time:%s,  %s won\n", thisTime, p->p1);
    }
    else if (p->p1Score < p->p2Score){                     // IF P1 SCORES LESS THAN P2
        fprintf(f, "Time:%s, %s won\n", thisTime, p->p2);            // P2 WINS
    }
    else
    {
        fprintf(f, "Time:%s, tie game\n", thisTime);           // IF TIE, PRINT TIME AND TIE
    }

    boardPrint(f, g, p);             // PRINTS FINAL BOARD
    fclose(f);           // CLOSE FILES
}
