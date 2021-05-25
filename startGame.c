#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "othello.h"

void startGame(struct Game *g, struct Players *p, const char *p1, const char *p2) // SETS UP THE BOARD
{

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            g->board[i][j] = ' '; // PRINTS AN EMPTY BOARD
        }
    }
    p->p1Score = 2; // 2 DISKS EACH, 2 SCORE EACH.
    p->p2Score = 2;
    g->board[4][3] = 'W';
    g->board[4][4] = 'B'; // PUTS IN THE 4 PIECES AT THE START
    g->board[3][3] = 'B';
    g->board[3][4] = 'W';
    g->move = 'B'; // BLACK STARTS
}