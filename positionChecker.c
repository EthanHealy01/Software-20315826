#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "othello.h"

void positionChecker(struct Game *g, int row, char column)           //  CHANGES THE FLANKED PIECE FROM BLACK TO WHITE OR VICE-V
{
    row--;                        // ARRAYS START AT 0 AND WE ASKED FOR 1-8                                      
    int col = column - 'a';
    g->board[row][col] = g->move;
    
    if (g->validMoves == noPossibleMoves){
        return;                    // IF NO POSSIBLE MOVES, RETURN
    }
    
    char currentPiece;
    if (g->move == 'B'){                     // SWAPS FLANKED PIECE
       currentPiece = 'W';       
    }                     
    else currentPiece = 'B';

    
    if (g->validMoves == rowUp){                  // INCREMENTS ROW 
        for (int i = row + 1; i < 8; i++){
            if (g->board[i][col] == currentPiece){
                g->board[i][col] = g->move;
            }
            else break;
        }
    }

    if (g->validMoves == rowDown){                    // DECREMENTS ROW v
        for (int i = row - 1; i >= 0; i--){
            if (g->board[i][col] == currentPiece){
                g->board[i][col] = g->move;
            }
            else break;
        }
    }

    if (g->validMoves == colUp){                  // INCREMENTS COL >
        for (int i = col + 1; i < 8; i++){
            if (g->board[row][i] == currentPiece){
                g->board[row][i] = g->move;
            }
            else break;
        }
    }

    if (g->validMoves == colDown){                // DECREMENTS COL <
    
        for (int i = col - 1; i >= 0; i--){
            if (g->board[row][i] == currentPiece){
                g->board[row][i] = g->move;
            }
            else break;
        }
    }

    if (g->validMoves == upLeft){                                 // INCREMENTS ROW AND DECREMENTS COLUMN    ^<
    
        for (int i = row + 1, j = col - 1; i < 8 && j >=0 ; i++, j--){
            if (g->board[i][j] == currentPiece){
                g->board[i][j] = g->move;
            }
            else break;
        }
    }

    if (g->validMoves == upRight){                            // INCREMENTS ROW AND COLUMM           ^>
    
        for (int i = row + 1, j = col + 1; i < 8 && j < 8; i++, j++){
            if (g->board[i][j] == currentPiece){
                g->board[i][j] = g->move;
            }
            else break;
        }
    }

    if (g->validMoves == downRight){                                       // DECREMENTS ROW AND INCREMENTS COLUMN       v>
    
        for (int i = row - 1, j = col + 1; i >0 && j < 8; i--, j++){
            if (g->board[i][j] == currentPiece){
                g->board[i][j] = g->move;
            }
            else break;
        }
    }
    if (g->validMoves == downLeft){                                       // DECREMENTS ROW AND COLUMN           v<
    
        for (int i = row - 1, j = col - 1; i >0 && j >0; i--, j--){
            if (g->board[i][j] == currentPiece){
                g->board[i][j] = g->move;
            }
            else break;
        }
    }
}
