#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int b1[5];
    int* b2;
    int b3;
} B, *PB;

typedef struct {
    int a1;
    PB a2;
} A, *PA;

int main(int argc, char** argv)
{
    PA pa;

    pa = (A*) malloc(sizeof(A));

    // pa is a pointer to A
    // *pa is struc A

    // pointer way
    pa->a1 = 5;
    printf("pa->a1 is %d\n", pa->a1);
    // structure way
    (*pa).a1 = 6;
    printf("pa->a1 is %d\n", pa->a1);

    // something harder but understandable
    pa->a2 = (B*) malloc(sizeof(B));        // pa-a2 vs PB pb 
    pa->a2->b3 = 1314;                      // same as pa->a1
    printf("pa->a2->b3 is %d\n", pa->a2->b3);

    pa->a2->b2 = &(pa->a2->b3);
    printf("pa->a2->b3 address is %p\n", &(pa->a2->b3));
    printf("pa->a2->b2 is %p\n", pa->a2->b2);
    printf("pa->a2->b2 value is %d\n", *pa->a2->b2);

    pa->a2->b1[0] = 1;
    printf("pa->a2->b1[0] is %d\n", pa->a2->b1[0]);
    *(pa->a2->b1) = 2;
    printf("pa->a2->b1[0] is %d\n", pa->a2->b1[0]);

    for (int i = 0; i < 5; i++) {
        pa->a2->b1[i] = i * i;
        printf("pa->a2->b1[%d] is %d\n", i, pa->a2->b1[i]);
    }


    printf("\n");

    int* ptmp = pa->a2->b1;
    for (int i = 0; i < 5; i++) {
        *ptmp = 2 *i * i;
        printf("pa->a2->b1[%d] is %d\n", i, pa->a2->b1[i]);
        ptmp++;
    }
    

    return 0;
}
