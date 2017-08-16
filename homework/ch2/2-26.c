// To prove the bug shown in example 2.26

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("%u, %zu\n", 7u-8u, sizeof(size_t));
    printf("%d, %d\n", (int)(7u > 8u), (int)(7u-8u > 0));
    return 0;
}
