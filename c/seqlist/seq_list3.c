#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10


typedef struct {
    double x;      
    double y;
    double z;
} Node;

typedef struct {
    Node* pn;        
    int len;
} Seqlist;

Seqlist* init(Seqlist* pseq)
{
    pseq = (Seqlist*) malloc(sizeof(Seqlist));
    pseq->pn = (Node*) malloc(MAXSIZE * sizeof(Node));
    pseq->len = 0;
    
    return pseq;
}

// let's get node value by index
Node* getval(Seqlist* pseq, int index)
{
    Node* pnode = NULL;
    pnode = pseq->pn;

    pnode = pnode + index;
    
    return pnode;
}



int main(int argc, char** argv)
{
    Seqlist* ptr = NULL;
    ptr = init(ptr);

    Node* ptmp = ptr->pn;
    for (int i = 0; i < MAXSIZE; i++) {
        // use the sturcture way
        (*ptmp).x = 1.1 * i;
        (*ptmp).y = 2.2 * i;
        (*ptmp).z = 3.3 * i;
        ptmp++;
    }

    ptmp = ptr->pn;
    for (int i = 0; i < MAXSIZE; i++) {
        printf("node[%d] = (%.2f, %.2f, %.2f).\n", i, (*ptmp).x, (*ptmp).y,
                (*ptmp).z);
        ptmp++;
    }

    printf("\n");

    // use getval()
    Node* ptarget = getval(ptr, 5);
    printf("node[%d] = (%.2f, %.2f, %.2f).\n", 5, ptarget->x, ptarget->y, ptarget->z);

    free(ptr);
    return 0;
}
