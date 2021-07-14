// the difference between seqlist and linklist is
// the store logic: the former use a block of memory,
// which means we can use pointer++ to find the next one
// the linklist use pointer to connect the next node

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// THE BASIC CONCEPTION IS WRONG, REWRITE
/*
typedef struct {
    double x;
    double y;
    double z;
} Node;

typedef struct {
    Node node;
    Node* next;
    int len;
} Linklist, *PLK;

Linklist* init(Linklist* plk)
{
    plk = (*Linklist)malloc(sizeof(Linklist));
    plk->next = NULL;
    plk->len = -1;
    return plk;
}
*/

typedef struct {
    int x;
    int y;
} DATA;

// the node have two part:
// one is data, another is a link to another, aka a pointer
// But how to count the length of linklist?

typedef struct node {
    DATA data;
    struct node* next;
} Node, *Linklist;

// initialize a link list
// init a node without data part
Node* init(Linklist pn)
{
    pn = (Node*) malloc(sizeof(Node));
    pn->next = NULL;

    return pn;
}


int main(int argc, char** argv)
{
    Node* head = init(head);

    return 0;
}
