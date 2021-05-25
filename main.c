#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "othello.h"
#include "endGame.c"
#include "positionChecker.c"
#include "gameOverBool.c"
#include "remainingValidCheck.c"
#include "validMoveCheck.c"
#include "boardPrint.c"
#include "startGame.c"

int main()
{
    struct Game g; // INITIALIZE STRUCT
    struct Players p; // SAME
    char answer[30];  // INITIALIZE ANSWER TO POSITIOINS

    printf("Enter blacks name: ");
    fgets(p.p1, 30, stdin);

    printf("Enter whites name: ");
    fgets(p.p2, 30, stdin);

    startGame(&g, &p, p.p1, p.p2);

    while (true) // INFINITE LOOP
    {
        bool possibleMove = true;
        int x;
        char y;
        
        
        boardPrint(stdout, &g, &p); // PRINTS THE BOARD
        if (gameOverBool(&g))
            break;          // IF GAME IS OVER, BREAK AND CONTINUE THROUGH MAIN
        
        while (true)            // INFINITE LOOP
        {
            printf("Valid moves lie between a-h & 1-8, if there are no valid moves, type pass (Black starts) : ");
            fgets(answer, 30, stdin);
            
            
            if (strlen(answer) == 1){           // IF THERES A VALID MOVE AVAILABLE AND THE PLAYER TRIES TO PASS
                if (answer[0] == 'p' && !remainingValidCheck(&g)){       // CHECK TO MAKE SURE NO MOVES REMAIN BEFORE PASSING
                    possibleMove = false;                   
                    break;
                }
                printf("Invalid move\n"); 
                continue;
            }

            
                if (answer[1] < '1' || answer[1] > '1' + 8){
                    printf("Invalid move\n"); 
                    continue;
                }
                if (answer[0] < 'a' || answer[0] > 'a' + 8){
                    printf("Invalid move\n"); 
                    continue;
                }

            if (!validMoveCheck(&g, answer[1] - '0', answer[0])){        // IF ANSWER WAS BETWEEN THE SPECIFIED CO-ORDS, IT CHECKS THAT THE SPACE IS FLANKING / EMPTY BEFORE PLACING
                printf("Invalid move\n"); 
                continue;
            }


            x = answer[1] - '0';
            y = answer[0]; // SPLITS ROW AND COL FROM YOUR ANSWER
            break;
        }

        if (possibleMove){
             positionChecker(&g, x, y); // CHECK
        }
        if (g.move == 'B'){
            g.move = 'W';
        }
        else
            g.move = 'B'; // CHANGES TURN POSSESION
    }

    if (p.p1Score > p.p2Score){
        printf("%s wins", p.p1);
    }
    else if (p.p1Score < p.p2Score){
        printf("%s wins", p.p2);
    }
    else{
        printf("Tie game");
    }

    endGame(&g, &p);
    return 0;
}
