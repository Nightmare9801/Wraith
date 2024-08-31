#include "board.h"

#include <stdio.h>

/* The `const short endings[]` array in the provided code contains binary representations of winning
patterns in a Tic Tac Toe game. Each element in the array represents a possible winning combination
on the game board. The binary numbers in the array correspond to specific winning patterns that can
occur in the game. */
const short endings[] = {0b100100100, 0b10010010, 0b1001001, 0b111, 0b111000, 0b111000000, 0b100010001, 0b1010100};

/**
 * The function `getMoves` calculates the available moves on a board by bitwise operations.
 * 
 * @param board The `board` parameter in the `getMoves` function represents the game board, which
 * typically consists of two separate bitboards - one for player O's pieces and one for player X's
 * pieces. The function combines these two bitboards to determine the available moves for the current
 * player.
 * 
 * @return The function `getMoves` returns a short integer representing the available moves on the
 * board.
 */
short getMoves(Board board) {
    short pieces = board.boardO | board.boardX;
    short moves = ~pieces & 0b111111111;
    return moves;
}

/**
 * The function `move` updates the game board based on the player's move.
 * 
 * @param board The `board` parameter is a pointer to a `Board` struct, which likely contains
 * information about the game board state, such as the current player's turn, the type of player (X or
 * O), and the moves made by each player on the board.
 * @param move The `move` parameter in the `move` function is a short integer that represents a
 * specific move to be made on the game board. It is used to update the game board state based on the
 * player's turn.
 */
void move(Board *board, short move) {
    if(board -> turn == board -> playerType) {
        board -> boardX |= move;
    } else {
        board -> boardO |= move;
    }
}

/**
 * The function `hasEnded` checks if the game on the board has ended by evaluating the board state for
 * winning conditions.
 * 
 * @param board The `hasEnded` function you provided is a part of a tic-tac-toe game implementation. It
 * checks if the game has ended by examining the board state.
 * 
 * @return The function `hasEnded` returns a boolean value - `true` if the game has ended, and `false`
 * if the game has not ended yet.
 */
bool hasEnded(Board *board) {
    if((board -> boardX | board -> boardO) >= 511) {
        return true;
    }
    short totalBoard = board -> boardX | board -> boardO;
    int length = sizeof(endings) / sizeof(endings[0]);
    for(int i = 0; i <length; i++) {
        if(((endings[i] & board -> boardX) == endings[i]) || ((endings[i] & board -> boardO) == endings[i])) {
            return true;
        }
    }
    return false;
}

/**
 * The function `isWin` checks if a player has won the game on a given board by comparing the board
 * state with predefined winning combinations.
 * 
 * @param board The `board` parameter in the `isWin` function is a pointer to a `Board` struct. This
 * struct likely contains two variables `boardX` and `boardO`, which represent the positions of X and O
 * players on the game board, respectively. The function checks if any of the
 * 
 * @return The function `isWin` returns a boolean value - `true` if there is a winning combination on
 * the board for either player X or player O, and `false` if there is no winning combination.
 */
bool isWin(Board *board) {
    short totalBoard = board -> boardX | board -> boardO;
    int length = sizeof(endings) / sizeof(endings[0]);

    for(int i = 0; i <length; i++) {
        if(((endings[i] & board -> boardX) == endings[i]) || ((endings[i] & board -> boardO) == endings[i])) {
            return true;
        }
    }

    return false;
}

/**
 * The function `printBoard` prints a Tic Tac Toe board with player X and player O positions based on
 * the provided bitmasks.
 * 
 * @param playerX Player X's moves represented as a bitboard where each bit corresponds to a position
 * on the Tic Tac Toe board. If a bit is set to 1 at a particular position, it means that Player X has
 * marked that position on the board.
 * @param playerO PlayerO is a variable that represents the positions where player O has placed their
 * marks on the Tic Tac Toe board. Each bit in the variable corresponds to a position on the board,
 * with a set bit indicating that player O has marked that position.
 */
void printBoard(short playerX, short playerO) {

    printf("Tic Tac Toe Board:\n");
    
    // Iterate through rows
    for (int row = 2; row >= 0; row--) {
        for (int col = 0; col < 3; col++) {
            int position = row * 3 + col; // Calculate the position index
            
            // Check player X
            if (playerX & (1 << position)) {
                printf(" X ");
            }
            // Check player O
            else if (playerO & (1 << position)) {
                printf(" O ");
            } else {
                printf("   "); // Empty space
            }

            if (col < 2) {
                printf("|"); // Column separator
            }
        }
        printf("\n");

        // Print row separator
        if (row > 0) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}
