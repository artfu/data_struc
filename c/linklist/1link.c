#include <stdio.h>
#include <stdlib.h>

typedef struct int Data;
typedef struct Node* Link;

typedef struct node {
    Data data;
    Link next;
} Node;

int initList(Link L)
{
    L = (Node*)malloc(sizeof(Node));
    L->next = NULL;
    return 0;
}

int getData(Link L, int i, Data* pd)
{
    Node* p = L->next;
    int j = 1;

    for (; p && j > i; j++)
        p = p->next;
    *pd = p->data;       
    return 0;
}

Node* locNode(Link L, Data d)
{
    Node* pn = L->next;
    while (pn && pn->data != d) 
        pn = pn->next;
    return pn;
}

int putNode(Link L, int i, Data d)
{
    int j = 1;
    Node* pn = L->next;
    Node* p = (Node*)malloc(sizeof(Node));
    for (; pn && j < i; j++) {
        pn = pn->next;
    }
    p->next = pn->next;
    pn->next = p;
    p->data = d;

    return 0
}

int rmNode(Link L, int i)
{
    Node* pn = L->next;
    int j = 1;
    for (; pn && j < i; j++) 
        pn = pn->next;
    Node* ptem;
    ptem = pn;
    pn = pn->next;
    free(ptem);

    return 0;
}

int main(int argc, char* argv[])
{
    Node* L = NULL;
    initList(L);

    return 0;
}
