#include "bitfield.h"
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

int initBitfield(TBitfield *bf, size_t size)
{
    bf->data = (unsigned char*) calloc(((size + 7)/8), sizeof(char));

    if (bf->data == NULL)
    {
        return false;
    }
    
    bf->size = size;

    return true;
}

void setBit(TBitfield *bf, size_t index)
{
    if (index > bf->size-1)
    {
        return;
    }
    
    size_t byteIndex = index / 8;
    size_t inByteIndex = index % 8;

    bf->data[byteIndex] = bf->data[byteIndex] | (char) pow(2, 7-inByteIndex); 
}

void clearBit(TBitfield *bf, size_t index)
{
    if (index > bf->size-1)
    {
        return;
    }
    
    size_t byteIndex = index / 8;
    size_t inByteIndex = index % 8;

    bf->data[byteIndex] = bf->data[byteIndex] ^ (char) pow(2, 7-inByteIndex); 
}

int getBit(TBitfield *bf, size_t index)
{
    if (index > bf->size-1)
    {
        return -1;
    }
    
    
    size_t byteIndex = index / 8;
    size_t inByteIndex = index % 8;

    char byte = bf->data[byteIndex];

    byte = byte >> (7 - inByteIndex) & 0x01;
    
    return byte;
}

void toggleBit(TBitfield *bf, size_t index)
{
    if (getBit(bf, index))
    {
        clearBit(bf, index);
    }
    else
    {
        setBit(bf, index);
    }
}

void clearAllBits(TBitfield *bf)
{
    size_t byteSize = bf->size/8 + 1;

    for (size_t i = 0; i < byteSize; i++)
    {
        bf->data[i] = 0;
    }
}

void printBitfield(TBitfield *bf)
{
    unsigned char byte, bit, byteLength;
    size_t byteSize = bf->size/8 + 1;

    for (size_t i = 0; i < byteSize; i++)
    {
        byte = bf->data[i];

        if (i < byteSize - 1)
            byteLength = 8;
        else
            byteLength = bf->size % 8;
        
        for (size_t j = 0; j < byteLength; j++)
        {
            bit = byte/128;
            printf("%hd ", bit);
            byte = byte << 1;
        }
        
        printf("- ");
    }
    printf("\n");
}