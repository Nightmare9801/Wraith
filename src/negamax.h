#ifndef NEGAMAX_H
#define NEGAMAX_H

#include "board.h"

#include <stdbool.h>


double negamax(Board board, double alpha, double beta, bool turn, int depth);
short chooseMove(Board board);

#endif