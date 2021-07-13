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

Node* getval(Seqlist* pseq, int index)
{
    Node* pnode = NULL;
    pnode = pseq->pn;

    pnode = pnode + index;
    
    return pnode;
}

int getindex(Seqlist* pseq, double a, double b, double c)
{
    int index;
    Node* ptem = pseq->pn;

    for (int i = 0; i < MAXSIZE; i++) {
        if ((ptem+i)->x == a && (ptem+i)->y == b && (ptem+i)->z ==c)
            index = i;
    }
    return index;
}

// insert a node to the seqlist
void insert(Seqlist* pseq, int index, Node node)
{
    Node* ptem = pseq->pn;
    Node* end = ptem + pseq->len;
    for (; end > ptem+index; end--) {
        *(end+1) = *end;
        end--;
    }
    *(ptem+index) = node;
}

int main(int argc, char** argv)
{
    Seqlist* ptr = NULL;
    ptr = init(ptr);

    Node* ptmp = ptr->pn;
    for (int i = 0; i < MAXSIZE-5; i++) {
        // use the sturcture way
        (*ptmp).x = 1.1 * i;
        (*ptmp).y = 2.2 * i;
        (*ptmp).z = 3.3 * i;
        ptmp++;
    }

    ptmp = ptr->pn;
    for (int i = 0; i < MAXSIZE-5; i++) {
        printf("node[%d] = (%.2f, %.2f, %.2f).\n", i, (*ptmp).x, (*ptmp).y,
                (*ptmp).z);
        ptmp++;
    }

    printf("\n");

    /*****************************************************************/
    /****************  Put your code here   **************************/
    /*****************************************************************/

    Node example = {
        .x = 8.88,
        .y = 88.88,
        .z = 888.888,
    };
    int index = 3;
    insert(ptr, index, example);


    ptmp = ptr->pn;
    for (int i = 0; i < MAXSIZE; i++) {
        printf("node[%d] = (%.2f, %.2f, %.2f).\n", i, (*ptmp).x, (*ptmp).y,
                (*ptmp).z);
        ptmp++;
    }


    /*****************************************************************/

    free(ptr);
    return 0;
}
