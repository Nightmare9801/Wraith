#include <stdio.h>
#include "negamax.h"
#include "board.h"

/**
 * The function `ui` allows players to take turns making moves in a game, alternating between human and
 * computer players based on user input.
 */
void ui() {
    Board board;
    board.turn = true;
    board.boardX = 0;
    board.boardO = 0;
    board.playerType = true;
    printf("7 8 9\n");
    printf("4 5 6\n");
    printf("1 2 3\n");
    printf("Please enter the player type: ");
    char player;
    scanf("%c", &player);
    if(player == 'O'){   
        while (!hasEnded(&board)) {
            move(&board, chooseMove(board));
            printBoard(board.boardX, board.boardO);
            board.turn = !board.turn;
            if(hasEnded(&board)){
                if(isWin(&board)) {
                    printf("AI has won.");
                } else {
                    printf("It is a draw.");
                }
                break;
            }
            printf("Enter the move\n");
            short _move = 0;

            scanf("%hd", &_move);
            _move = 1 << (_move - 1);
            move(&board, _move);
            printBoard(board.boardX, board.boardO);
            board.turn = !board.turn;
            if(hasEnded(&board)){
                if(isWin(&board)) {
                    printf("You has won.");
                } else {
                    printf("It is a draw.");
                }
            }
        }
    } else if(player == 'X') {
        while (!hasEnded(&board)) {
            printf("Enter the move\n");
            short _move = 0;

            scanf("%hd", &_move);
            _move = 1 << (_move - 1);
            move(&board, _move);
            printBoard(board.boardX, board.boardO);
            board.turn = !board.turn;

            if(hasEnded(&board)){
                if(isWin(&board)) {
                    printf("You has won.");
                } else {
                    printf("It is a draw.");
                }
                break;
            }

            move(&board, chooseMove(board));
            printBoard(board.boardX, board.boardO);
            board.turn = !board.turn;

            if(hasEnded(&board)){
                if(isWin(&board)) {
                    printf("AI has won.");
                } else {
                    printf("It is a draw.");
                }
            }
        }
    } else {
        printf("Pls enter a valid player type");
    }
    
}

int main() {
    ui();
}