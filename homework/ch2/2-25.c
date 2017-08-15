#include <stdio.h>
#include <stdlib.h>

// BUG is the signed to unsigned conversion of "i<=length-1", 
// NEVER use mixed signed and unsigned data in <, >, <=, >=, == expressions !!!

float sum_elements(float a[], unsigned int length)
{
    int i = 0;
    float sum = 0;
    for(i=0; i<=length-1; i++)
        sum += a[i];
    return sum;
}

int main(int argc, char* argv[] )
{
    float a[1] = {1.0f};
    if(argc > 1)
        printf("sum of array length equal to zero: %f \n", sum_elements(a, atoi(argv[1]))); 

    return 0;
}
