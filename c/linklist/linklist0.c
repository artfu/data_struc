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
Node* init(Linklist pn)
{
    pn = NULL;
    return pn;
}

// make a node
// means add Data and return a pointer
Node* make(DATA d)
{
    Node* p = (Node*) malloc(sizeof(Node));
    p->data = d;
    p->next = NULL;
    return p;
}

// and insert to the list
// we can use pointer to change value that point to
// rather not pointer itself
// we want to change pointer value, we need a pointer of pointer
// let's try this 

void insert(Linklist head, Node* pn)
{
    pn->next = head;
    head = pn;
}

void pinsert(Linklist* phead, Node** ppn)
{
    (*ppn)->next = *phead;
    *phead = ppn;
}


int main(int argc, char** argv)
{
    Linklist head = init(head);

    DATA a;
    a.x = 5;
    a.y = 6;

    Node* pa = make(a);
    printf("Now the node pa:%p\n", pa);

    insert(head, pa);
    printf("Now the head:%p\n", head);
    // now the head still at null
    // but why?
    // do some pointer test of this
    // now we konw pointer the difference
    
    pinsert(&head, &pa);
    printf("Now the head:%p\n", head);

    return 0;
}
