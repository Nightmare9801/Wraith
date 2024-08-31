#include "negamax.h"
#include "board.h"
#include "bitfunctions.h"

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

/**
 * The function `negamax` implements the negamax algorithm for evaluating game positions with
 * alpha-beta pruning.
 * 
 * @param board The `board` parameter represents the current state of the game board. It likely
 * contains information about the positions of game pieces, player turns, and other relevant game state
 * data.
 * @param alpha Alpha is the best value that the maximizing player can currently guarantee at the
 * current level or above. It represents the minimum score that the maximizing player is assured of.
 * @param beta In the context of the negamax algorithm, `beta` represents the upper bound of possible
 * scores that the maximizing player can achieve. It is used in conjunction with `alpha` to perform
 * alpha-beta pruning, which helps to reduce the number of nodes that need to be evaluated in the
 * search tree.
 * @param turn The `turn` parameter in the `negamax` function represents the current player's turn. It
 * is a boolean value where `true` typically represents Player 1's turn and `false` represents Player
 * 2's turn. This parameter is used to determine whose turn it is during the recursive calls
 * @param depth The `depth` parameter in the `negamax` function represents the current depth of the
 * search in the game tree. It is typically used to limit the depth of the search to avoid exploring
 * too deeply into the game tree, which can be computationally expensive. The depth parameter is
 * decremented with each
 * 
 * @return The function `double negamax(Board board, double alpha, double beta, bool turn, int depth)`
 * is returning the best value found during the negamax search algorithm. This value represents the
 * evaluation of the board state after considering all possible moves up to a certain depth in the game
 * tree.
 */
double negamax(Board board, double alpha, double beta, bool turn, int depth) {
    if(hasEnded(&board)) {
        if(isWin(&board)) {
            return -1 * (9 - depth);
        }
        return 0;
    }
    double bestValue = -9999;
    int size = 0;
    short allMoves = getMoves(board);
    short* moves = getIndiBits(getMoves(board), &size);
    if(moves != NULL) {
        for(int i = 0; i < size; i++) {
            Board clonedBoard;
            memcpy(&clonedBoard, &board, sizeof(Board));
            move(&clonedBoard, moves[i]);
            clonedBoard.turn = !clonedBoard.turn;
            double score= -negamax(clonedBoard, -beta, -alpha, !turn, depth - 1);
            if(score > bestValue) {
                bestValue = score;
                if(score = alpha) {
                    alpha = score;
                }
            }
            if( score >= beta ){
                return bestValue;
            }
        }
    }
    free(moves);
    return bestValue;
}

/**
 * The function `chooseMove` selects the best move for a given board state using the negamax algorithm.
 * 
 * @param board The `board` parameter in the `chooseMove` function represents the current state of the
 * game board. It contains information about the positions of pieces, the current player's turn, and
 * any other relevant game state data needed to make a decision on the best move to take next. The
 * function calculates and
 * 
 * @return The function `chooseMove` returns a `short` value, which represents the best move to make on
 * the given `Board` based on the negamax algorithm and evaluation of possible moves.
 */
short chooseMove(Board board) {
    double bestValue = -9999;
    int size = 0;
    short allMoves = getMoves(board);
    short* moves = getIndiBits(getMoves(board), &size);
    short bestMove = moves[0];
    if(moves != NULL) {
        for(int i = 0; i < size; i++) {
            Board clonedBoard;
            memcpy(&clonedBoard, &board, sizeof(Board));
            move(&clonedBoard, moves[i]);
            clonedBoard.turn = !clonedBoard.turn;
            double score= -negamax(clonedBoard, -9999, 9999, false, size - 1);
            if(score > bestValue) {
                bestValue = score;
                bestMove = moves[i];
            }
        }
    }
    return bestMove;
}
