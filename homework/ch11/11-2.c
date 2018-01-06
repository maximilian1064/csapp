#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// convert HEX IP address to dot decimal format
// the input hex should be of 32bit length and follow format 0x[Uppercase characters or numbers]
char* hex2dd(char* hex)
{
    // format check
    if(strlen(hex) != 10)
    {
        printf("bad input!\n");
        return NULL;
    }
    if(hex[0] != '0' || hex[1] != 'x')
    {
        printf("bad input!\n");
        return NULL;
    }

    // Initialize output
    char* dd = malloc(16);
    memset(dd,0,16);

    // conversion
    char* iter;
    for(iter=hex+2; iter<hex+10; iter+=2)
    {
        // convert input byte to decimal string 
        int c1 = (*iter>=48 && *iter<=57)? (*iter-48): (*iter-55);
        int c2 = (*(iter+1)>=48 && *(iter+1)<=57)? (*(iter+1)-48): (*(iter+1)-55);
        int seg_val = c1*16 + c2;
        char seg_char[5]; 
        sprintf(seg_char, "%d.", seg_val);

        // append the decimal string to output 
        strcat(dd, seg_char);
    }
    dd[strlen(dd)-1] = '\0';

    return dd;
}

// test code
int main(int argc, char* argv[])
{
    if(argc != 2)
        return 1;
    char* dd = hex2dd(argv[1]);
    if(dd)
        printf("%s, %zd\n", dd, strlen(dd));
}
