// the difference between seqlist and linklist is
// the store logic: the former use a block of memory,
// which means we can use pointer++ to find the next one
// the linklist use pointer to connect the next node

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    double x;
    double y;
    double z;
} Node;

typedef struct {
    Node node;
    Node* next;
    int len;
} Linklist;

Linklist* init(Linklist* plk)
{
    plk = (*Linklist)malloc(sizeof(Linklist));
    plk->next = NULL;
    plk->len = -1;
    return plk;
}

int main(int argc, char** argv)
{
    Linklist* ptr = NULL;
    if (init(ptr)) {
        ptr->node.x = 1.1;
        ptr->node.y = 2.2;
        ptr->node.z = 3.3;
        ptr->len++;
    }

    return 0;
}
