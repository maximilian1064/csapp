#include <stdio.h>
#include <stdlib.h>

void tmul_ok(int x, int y)
{
    // (long long)x*y => real result, (int)((long long)x*y) ==> truncated result, same effects as x*y, 
    // these two will only be equal if no overflow happens...
    printf("x: %d, y: %d, x*y: %d, real result: %lld, tmul ok?: %d\n", x, y, x*y, (long long)x*y, (long long)x*y == (int)((long long)x*y) );
}

// a more general approach (suitable for any type) from problem 2-35
void alter_tmul_ok(int x, int y)
{
    printf("x: %d, y: %d, x*y: %d, real result: %lld, tmul ok?: %d\n", x, y, x*y, (long long)x*y, (x*y)/x == y );
}

int main(int argc, char* argv[])
{
    if(argc > 2)
    {
        tmul_ok(atoi(argv[1]), atoi(argv[2]));
        alter_tmul_ok(atoi(argv[1]), atoi(argv[2]));       
    }
    return 0;
}
