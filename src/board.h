#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

typedef struct {
    short boardX;
    short boardO;
    bool turn;
    bool playerType;
} Board;

short getMoves(Board board);
void move(Board *board, short move);
bool hasEnded(Board *board);
bool isWin(Board *board);
void printBoard(short playerX, short playerO);

#endif