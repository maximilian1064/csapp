/*
 * This one took me 4 hours
 * made me think myself an idiot :x
 */

#include <stdio.h>
#include <stdlib.h>

// Don't forget we have logical operators like & | ^
// Alternative implementation: (x + (x>>31) & 0xF) >> 4;
int div16(int x)
{
    return (x + ((-(x>>31))<<4) + (x>>31))>>4;
}

int main(int argc, char* argv[])
{
    if(argc > 1)
        printf(" %d / 16 = %d\n", atoi(argv[1]), div16( atoi(argv[1])) );
    return 0;
}
