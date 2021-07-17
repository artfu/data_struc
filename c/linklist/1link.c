#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct node {
    Data data;
    struct node* next;
} Node, *Link;

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

    return 0;
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

// add node to head
void creatHead(Link L, int n)
{
    L = (Node*)malloc(sizeof(Node));
    L->next = NULL;

    for (int i = 0; i < n; ++i) {
        Node* p = (Node*)malloc(sizeof(Node));
        printf("Input the %d node value: ", i);
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}

// add node at end
void creatTail(Link L, int n)
{
    L = (Node*) malloc(sizeof(Node));
    L->next = NULL;
    Node* tail = L;

    for (int i = 0; i < n; i++) {
        Node* p = (Node*) malloc(sizeof(Node));
        printf("Input the %d node value: ", i);
        scanf("%d", &p->data);
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
}

void printLink(Link L)
{
    Node* p = L;
    for (p; p; p = p->next)
        printf("%d ", p->data);
    printf("\n");
}


int main(int argc, char* argv[])
{
    Link L1;
    Link L2;

    creatHead(L1, 5);
    creatTail(L2, 5);

    printLink(L1);
    printLink(L2);

    return 0;
}
