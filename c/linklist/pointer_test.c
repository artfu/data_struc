#include <stdio.h>
#include <stdlib.h>

void dptr(int* a, int* b)
{
    *a = 4131;
    *b = 325435;

    b = a;
    a = NULL;
}

int main(int argc, char** argv)
{
    int n = 1314;
    int* a = &n;
    int* b = (int*) malloc(sizeof(int));

    printf("a = %d, b = %d\n", *a, *b);
    printf("*a = %p, *b = %p\n", a, b);

    printf("\n");

    dptr(a, b);
    printf("a = %d, b = %d\n", *a, *b);
    printf("*a = %p, *b = %p\n", a, b);
    

    return 0;
}
