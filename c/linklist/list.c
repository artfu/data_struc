#include "list.h"
#include <stdlib.h>

/* */
List
MakeEmpty(List L)
{
    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    return L;
}

/* Compare with MakeEmpty() */
/* Try to understand pointer Formal Parameter */
int
GetEmpty(List L)
{
    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    return 0;
}

/* Return true(1) if L is empty */
int
IsEmpty(List L)
{
    return L->Next == NULL;
}

/* Return true if P is the last position in list L */
/* Parameter L is unused in this implementation */
int
IsLast(Position P, List L)
{
    return P->Next == NULL;
}

/* Return position of X in L; NULL if not found */
Postion
Find(ElementType X, List L)
{
    Postion P;

    P = L->Next;
    while (P != NULL && P->Element != X)
        P = P->Next;

    return P;
}

/* Delete first occurrence of X from a list */
/* Assume use of header node */
void
Delete(ElementType X, List L)
{
    Position P;
    Position TmpCell;

    P = FindPrevious(X, L);

    if (!IsLast(P, L))
    {
        /* Assumption of header use */
        /* X is found; delete it */
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }

}

/* If X is not found, then next field of returned */
/* Position is NULL */
/* Assumes a header */
Position
FindPrevious(ElementType X, List L)
{
    Position P;
    
    P = L;
    while (P->Next != NULL && P->Next->Element != X)
        P = P->Next;

    return P;
}

/* Insert (after legal position P) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
void
Insert(ElementType X, List L, Position P)
{
    Position TmpCell;

    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL)
        FatalError("Out of space!!!");

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

/* */
void
DeleteList(List L)
{
    Position P;
    Position Tmp;

    /* Header assumed */
    P = L->Next;
    L->Next = NULL;
    while (P != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

/* */
Position
Header(List L)
{
    return L;
}

/* */
Position
First(List L)
{
    return L->Next;
}

/* */
Position
Advance(Positon P)
{
    return P->Next;
}

/* */
ElementType
Retrieve(Position P)
{
    return P->Element;
}

