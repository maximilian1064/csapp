#include <stdio.h>
#include <stdlib.h>

void tadd_ok(int x, int y)
{
    printf("x: %d, y: %d, x+y: %d, tadd ok?: %d\n", x, y, x+y,  (x>=0)&&(y>=0) ? (x+y>=0) : ( (x<0)&&(y<0) ? (x+y<0) : 1) );
}

int main(int argc, char* argv[])
{
    if(argc > 2)
        tadd_ok(atoi(argv[1]), atoi(argv[2]));
    return 0;
}
