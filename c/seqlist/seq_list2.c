#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10


// use complicate node form, such as three-dimensional coordinates
typedef struct {
    double x;      
    double y;
    double z;
} Node;

// Seqlist do not need change much
typedef struct {
    Node* pn;        
    int len;
} Seqlist;

// void is the worst, formal parameters don't affect the main,
// we use void for side effect
// we choose pointer as return value
Seqlist* init(Seqlist* pseq)
{
    // use MAXSIZE instead of exact figures
    pseq = (Seqlist*) malloc(sizeof(Seqlist));
    pseq->pn = (Node*) malloc(MAXSIZE * sizeof(Node));
    pseq->len = 0;
    
    return pseq;
}

int main(int argc, char** argv)
{
    Seqlist* ptr = NULL;
    ptr = init(ptr);

    // test more
    printf("the len of seq is %d\n", ptr->len);

    printf("the address of seqlist: %p\n", ptr);

    // give every node a valid value
    Node* ptemp = ptr->pn;
    
    printf("the address of the first Node: %p\n", ptr->pn);

    printf("\n");
    
    for (int i = 0; i < MAXSIZE; i++) {
        ptemp->x = 1.1 * i;
        ptemp->y = 2.2 * i;
        ptemp->z = 3.3 * i;
        ptemp++;
        ptr->len++;
    }

    // reset ptemp pointer to the beginning
    ptemp = ptr->pn;
    // print the list
    for (int i = 0; i < MAXSIZE; i++) {
        printf("You got (%.2f, %.2f, %.2f)\n", ptemp->x, ptemp->y, ptemp->z); 
        ptemp++;
    }
    printf("the len of seq is %d\n", ptr->len);

    // where is a mallac there is a free
    free(ptr);

    return 0;
}
