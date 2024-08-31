#ifndef BITFUNCTIONS_H
#define BITFUNCTIONS_H

#include <stdlib.h>

short getLSB(short bitboard);
short getWithoutLSB(short bitboard);
short* getIndiBits(short bitboard, int* size);

#endif