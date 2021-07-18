#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char** argv)
{
    // use MakeEmpty() 
    List L = NULL;
    L = MakeEmpty(L);
    printf("L = %p\n", L);
    printf("L->Next = %p\n", L->Next);

    // use GetEmpty()
    struct Node header;
    List Lh = &header;
    GetEmpty(Lh);
    printf("Lh = %p\n", Lh);
    printf("Lh->Next = %p\n", Lh->Next);

    // use IsEmpty()
    printf("isEmpty = %d\n", IsEmpty(L));

    // use IsLast()
    printf("isLast = %d\n", IsLast(L));

    return 0;
}
