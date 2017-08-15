/*
 * Small code showing byte representations of different data type
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, int len)
{
    int i;
    for(i=0; i<len; i++)
        printf("%.2x ", start[i]);
    printf("\n");
}

void show_pointer(void* x)
{
    show_bytes( (byte_pointer)&x, sizeof(void*));
}

void show_short(short x)
{
    show_bytes( (byte_pointer)&x, sizeof(short));
}

int main()
{
    int x=0x12345678;
    show_bytes( (byte_pointer)&x, sizeof(int) ); 

    void* p=&x;
    show_pointer(p);

    show_bytes( (byte_pointer)"12345", 6);

    const char* s="abcdef";
    show_bytes( (byte_pointer)s, strlen(s));

    return 0;
}
