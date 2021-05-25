#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "othello.h"

void boardPrint(FILE *f, struct Game *g, struct Players *p){ // THIS FUCNTION PRINTS THE BOARD AND UPDATES THE SCORE

    p->p1Score = p->p2Score = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (g->board[i][j] == 'B')
                p->p1Score++;               // SCORE GETS RE-COUNTED EVERY TIME
            if (g->board[i][j] == 'W')
                p->p2Score++;                   // EVERY PIECE COUNTS AS A POINT
        }
    }
    fprintf(f, "Score:\n%s: %d\n %s: %d", p->p1, p->p1Score, p->p2, p->p2Score); // PRINTS THE SCORE

    for (int i = 0; i < 8; i++){
        fprintf(f, "   ");        // THE FOLLOWING FUNCTI0NS PRINT THE BORDERS AROUND THE BAORD AS SEEN ON BRIGHTSPACE
        for (int j = 0; j < 8; j++)
            fprintf(f, " ---");             // PRINTS ROOF
            fprintf(f,"\n");

            fprintf(f,"%d  ", i + 1);

                for (int j = 0; j < 8; j++){                
                    fprintf(f,"| %c ", g->board[i][j]);                 // PRINTS CONTENTS
                }
                fprintf(f,"|\n");               // PRINTS DIVIDERS
                    }       

                    fprintf(f, "   ");
                for (int j = 0; j < 8; j++)
                    fprintf(f, " ---");                 // PRINTS FLOOR
                    fprintf(f, "\n");
                    fprintf(f, "   ");
                    for (int j = 0; j < 8; j++)
                        fprintf(f, "  %c ", 'a' + j); // PRINTS THE BORDER LETTERS AND NUMBERS OF THE BOARD
                    fprintf(f, "\n");
}
