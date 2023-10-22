#include <stdlib.h>

typedef struct
{
    unsigned char* data;
    size_t size;    
} TBitfield;

int initBitfield(TBitfield *, size_t);
void setBit(TBitfield *, size_t);
void clearBit(TBitfield *, size_t);
int getBit(TBitfield *, size_t);
void toggleBit(TBitfield *, size_t);
void clearAllBits(TBitfield *);
void printBitfield(TBitfield *);


