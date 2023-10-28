#include "bitfield.h"
#include <stdio.h>

int main()
{
    TBitfield bf;

    initBitfield(&bf, 14);

    setBit(&bf, 0);
    setBit(&bf, 7);
    setBit(&bf, 1);
    setBit(&bf, 6);
    setBit(&bf, 8);

    clearBit(&bf, 0);    
    clearBit(&bf, 7);

    printf("\n%d\n", getBit(&bf, 1));
    printf("\n%d\n", getBit(&bf, 6));
    printf("\n%d\n", getBit(&bf, 8));

    toggleBit(&bf, 0);

    printBitfield(&bf);

    clearAllBits(&bf);

    printBitfield(&bf);

    return 0;
}