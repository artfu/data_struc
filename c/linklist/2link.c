#include <stdio.h>
#include <stdlib.h>

// rewrite the link list
// too many concept is unclear

typedef struct node {
    int data;
    struct node* next;
} N, Lk;

// this is invaild
// pointer value change does't effect in main
void headAdd(Lk l, int i)
{
    Node* p = (Node*)malloc(sizeof(Node));
    Node* head = l;
    for (int j = 0; j < i; j++) {
        int d;
        scanf("%d", &d);
        p->data = d;
        p->next = head;
        head = p;
    }
}

int main(int argc, char** argv)
{
    Lk a = NULL;
    return 0;
}
