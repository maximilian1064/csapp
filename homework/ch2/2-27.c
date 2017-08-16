#include <stdio.h>
#include <stdlib.h>

void uadd_ok(unsigned x, unsigned y)
{
    printf("x: %u, y: %u, x+y: %u, add ok? : %d\n", x, y, x+y, x<=x+y);
}

int main(int argc, char* argv[])
{
    if(argc > 2)
        uadd_ok((unsigned)atoi(argv[1]), (unsigned)atoi(argv[2]));

    return 0;
}
