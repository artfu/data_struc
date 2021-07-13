#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10

// once the miniest program work fine, let's make it better

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
    Seqlist* begin = NULL;
    ptr = init(ptr);
    begin = ptr;

    // test more
    printf("the len of seq is %d\n", ptr->len);

    // give every node a valid value
    for (int i = 0; i < MAXSIZE; i++, ptr->pn++) {
        ptr->pn->x = 1.1 * i;
        ptr->pn->y = 2.2 * i;
        ptr->pn->z = 3.3 * i;
        ptr->len++;
    }
    // return to the begin
    ptr = begin;
    // print the list
    for (int i = 0; i < MAXSIZE; i++, ptr->pn++) {
        printf("You got (%f, %f, %f)\n", ptr->pn->x, ptr->pn->y, ptr->pn->z);
    }
    printf("the len of seq is %d\n", ptr->len);

    // where is a mallac there is a free
    free(ptr);

    return 0;
}
