#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "othello.h"

bool validMoveCheck(struct Game *g, int row, char column)
{
    
    int col = column - 'a';

    row--;      // WE DECREMENT ROW BECAUSE ARRAYS START FROM 0

    if (g->board[row][col] != ' ') return false;

    int filled = 0;
    char next;
    if (g->move == 'B') next = 'W';         // WE INCREMENT EACH SPACES "FILLED STATUS" TO 1 IF FILLED, EMPTY SPACES HAVE VALUE ZERO
    else next = 'B';

    for (int i = row + 1; i < 8; i++){              // CHECK THE ROW ABOVE 
        if (g->board[i][col] == ' ') break;             // CHECK SPACE IS EMPTY
        if (g->board[i][col] == next) filled++;                 // INCREMENT FILLED WHEN FILLED
        if (g->board[i][col] == g->move && filled > 0){
            g->validMoves = rowUp;
            return true;
        }
    }

    filled = 0;
    for (int i = row - 1; i >= 0; i--){                      // CHECK THE ROW BELOW
        if (g->board[i][col] == ' ') break;                 //CHECK EMPTY
        if (g->board[i][col] == next) filled++;                 // INCREMENT WHEN FILLED
        if (g->board[i][col] == g->move && filled > 0){
            g->validMoves = rowDown;
            return true;                                                // RETURN TRUE IF TESTS PASS
        }
    }

    filled = 0;
    for (int j = col + 1; j < 8; j++){
        if (g->board[row][j] == ' ') break;
        if (g->board[row][j] == next) filled++;
        if (g->board[row][j] == g->move && filled > 0){
            g->validMoves = colUp;
            return true;
        }
    }

    filled = 0;
    for (int j = col - 1; j >= 0; j--){
        if (g->board[row][j] == ' ') break;
        if (g->board[row][j] == next) filled++;
        if (g->board[row][j] == g->move && filled > 0){
            g->validMoves = colDown;
            return true;
        }
    }

    filled = 0;
    for (int i = row + 1, j = col - 1; i < 8 && j < 8; i++, j--){
        if (g->board[i][j] == ' ') break;
        if (g->board[i][j] == next) filled++;
        if (g->board[i][j] == g->move && filled > 0){
            g->validMoves = upLeft;
            return true;
        }
    }
    filled = 0;
    for (int i = row - 1, j = col - 1; i < 8 && j < 8; i--, j--){
        if (g->board[i][j] == ' ') break;
        if (g->board[i][j] == next) filled++;
        if (g->board[i][j] == g->move && filled > 0){
            g->validMoves = downLeft;
            return true;
        }
    }
        for (int i = row + 1, j = col + 1; i < 8 && j < 8; i++, j++){
        if (g->board[i][j] == ' ') break;
        if (g->board[i][j] == next) filled++;
        if (g->board[i][j] == g->move && filled > 0){
            g->validMoves = upRight;
            return true;
        }
    }
        for (int i = row - 1, j = col + 1; i >=0 && j < 8; i--, j++){
        if (g->board[i][j] == ' ') break;
        if (g->board[i][j] == next) filled++;
        if (g->board[i][j] == g->move && filled > 0){
            g->validMoves = downRight;
            return true;
        }
    }

    g->validMoves = noPossibleMoves;                            // IF NO POSSIBLE MOVES REMAIN IT WILL REACH THE END AND RETURN FALSE
    return false;
        }
    
