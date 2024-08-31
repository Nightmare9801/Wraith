#include "bitfunctions.h"

#include <stdlib.h>

/**
 * The function `getLSB` returns the least significant bit of a given short integer.
 * 
 * @param bitboard The `bitboard` parameter in the `getLSB` function likely represents a 16-bit integer
 * that stores a bitboard, which is a data structure for storing pieces on a board.
 * 
 * @return The function `getLSB` returns the least significant bit (LSB) of the input `bitboard`. It
 * does this by performing a bitwise AND operation between the `bitboard` and its two's complement
 * (-bitboard), which effectively isolates the LSB.
 */
short getLSB(short bitboard) {
    return bitboard & (-bitboard);
}

/**
 * The function `getWithoutLSB` returns the input `bitboard` with the least significant bit unset.
 * 
 * @param bitboard The `bitboard` parameter is a variable that represents a 16-bit integer value.
 * 
 * @return The function `getWithoutLSB` returns the input `bitboard` with the least significant bit
 * (LSB) cleared. It achieves this by performing a bitwise AND operation between the input `bitboard`
 * and `bitboard - 1`. This operation effectively clears the LSB of the input `bitboard`.
 */
short getWithoutLSB(short bitboard) {
    return bitboard & (bitboard -1);
}


/**
 * The function `getIndiBits` takes a short integer, extracts its individual bits, and returns them in
 * a dynamically allocated array along with the size of the array.
 * 
 * @param i The parameter `i` in the function `getIndiBits` is a short integer that represents the
 * input value from which we want to extract individual bits.
 * @param size The `size` parameter in the `getIndiBits` function is a pointer to an integer. This
 * parameter is used to store the size or length of the dynamic array that is created within the
 * function. By passing a pointer to an integer, the function can update the value of `size`
 * 
 * @return The function `getIndiBits` returns a dynamically allocated array of `short` values
 * containing the individual bits of the input `i`. If the allocation fails, it returns `NULL`.
 */
short* getIndiBits(short i, int* size) {
    // Initialize dynamic array
    short* returner = (short*)malloc(sizeof(short) * 16); // Max bits for int16_t
    if (returner == NULL) {
        // Handle malloc failure
        *size = 0;
        return NULL; // Return NULL if allocation fails
    }

    *size = 0;

    while (i != 0 && *size < 16) { // Check to avoid overflow
        returner[*size] = getLSB(i); // Store the least significant bit
        (*size)++; // Increment the size
        i = getWithoutLSB(i); // Update i
    }

    return returner; // Return the array
}