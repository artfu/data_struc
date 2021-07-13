// add if-else func to check condition
// add printf() to look better
// fix pseq->len = -1 to begin

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
    // malloc fail
    if (pseq == NULL) {
        printf("Unable to malloc.\n");
    }
    else {
        pseq->pn = (Node*) malloc(MAXSIZE * sizeof(Node));
        pseq->len = -1;
    }
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

bool insert(Seqlist* pseq, int index, Node node)
{
    Node* ptem = pseq->pn;
    Node* end = ptem + pseq->len;
    for (; end > ptem+index; end--) {
        *(end+1) = *end;
        end--;
    }
    *(ptem+index) = node;
    pseq->len++;
    return true;
}

bool delete(Seqlist* pseq, int index)
{
    Node* ptem = pseq->pn;
    Node* ptag = ptem+index;

    for ( ; ptag < ptem+pseq->len; ptag++) {
        *ptag = *(ptag+1);
    }
    pseq->len--;
    return true;
}

int main(int argc, char** argv)
{
    Seqlist* ptr = init(ptr);

    if (ptr == NULL) {
        printf("Unable to initialize list.\n");
    }
    else {
        Node* ptmp = ptr->pn;
        for (int i = 0; i < MAXSIZE-4; i++) {
            // use the sturcture way
            (*ptmp).x = 1.1 * i;
            (*ptmp).y = 2.2 * i;
            (*ptmp).z = 3.3 * i;
            ptmp++;
            ptr->len++;
        }

        printf("Print the Seqlist: \n");
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

        // insert success
        printf("After insert a node, print New seqlist:\n");
        if (insert(ptr, index, example)) {
            ptmp = ptr->pn;
            for (int i = 0; i < MAXSIZE-4; i++) {
                printf("node[%d] = (%.2f, %.2f, %.2f).\n", i, (*ptmp).x, (*ptmp).y,
                        (*ptmp).z);
                ptmp++;
            }
            printf("the length is %d now.\n", ptr->len);
        }
        printf("\n");

        // use delete()
        // delete success
        printf("After delete a node, print New seqlist:\n");
        if (delete(ptr, index)) {
            ptmp = ptr->pn;
            for (int i = 0; i < MAXSIZE-4; i++) {
                printf("node[%d] = (%.2f, %.2f, %.2f).\n", i, (*ptmp).x, (*ptmp).y,
                        (*ptmp).z);
                ptmp++;
            }
            printf("the length is %d now.\n", ptr->len);
        }

        /*****************************************************************/

        free(ptr);
    }
    return 0;
}
