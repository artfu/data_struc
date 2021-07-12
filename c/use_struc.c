#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a1;
    int a2;
} A;

A* init(A* pa)
{
    pa = (A*) malloc(2*sizeof(A));
    pa->a1 = 1;
    pa->a2 = 2;

    return pa;
}

int main(int argc, char** argv)
{
    A* ptr_a = NULL;
    ptr_a = init(ptr_a);

    ptr_a->a1 = 1;
    ptr_a->a2 = 2;

    printf("%d %d\n", ptr_a->a1, ptr_a->a2);

    free(ptr_a);
    return 0;
}
