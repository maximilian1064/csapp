#include <stdio.h>

void solution(unsigned long long x)
{
    printf("A: 0x%.16llx\n", 0xFFULL & x);
    printf("A: 0x%.16llx\n", (~0xFFULL) ^ x);
    printf("A: 0x%.16llx\n", 0xFFULL | x);
}

int main()
{
    char x4=0x21;
    short x1=0x3121;
    int x2=0x51413121;
    long long x3=0x5141312151413121;
    solution(x4);
    solution(x1);
    solution(x2);
    solution(x3);
    int a=0x80808080;
    int b=0x7fffffff;
    int c=a&b;
    printf("%x\n", c); 
    return 0;
}
