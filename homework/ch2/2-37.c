#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void* copy_elements_original(void* ele_src[], int ele_cnt, size_t ele_size)
{
    /*if( ((unsigned long long)ele_size * ele_cnt) >> (8*sizeof(int)) )*/
    if( ele_cnt > __SIZE_MAX__ / ele_size )
    {
        printf("buffer overflow detected!, exit!!\n");
        exit(-1); 
    }

    void* result = malloc(ele_cnt * ele_size);
    if(result == NULL)
        return NULL;

    void* next = result;
    int i;
    for(i=0; i<ele_cnt; i++)
    {
        memcpy(next, ele_src[i], ele_size);
        next += ele_size;
    }

    return result;
}

int main()
{
    // data structures to be copied
    size_t ele_size = 4096;
    int ele_cnt = 1048575 + ele_size/sizeof(int);

    int* data = malloc(ele_cnt * sizeof(int)); 
    void** data_pointer = malloc(ele_cnt * sizeof(void*));

    int j;
    for(j=0; j<ele_cnt; j++)
    {
        data[j] = j;
        data_pointer[j] = data + j;
    }

    // store elements of data array into dest

    short* dest = copy_elements_original(data_pointer, ele_cnt+1-ele_size/sizeof(int), ele_size);

    // print data structure stored in dest
    int i;
    for(i = ele_cnt+1-ele_size/sizeof(int)-10; i < ele_cnt+1-ele_size/sizeof(int); i++)
        printf("%hx\n", *(dest + ele_size*i/sizeof(short)) ); 

    printf("end!\n");

    return 0;
}
