#ifndef _LIST_HPP_
#define _LIST_HPP_

typedef int ElementType;
struct node;
typedef struct node Node;
typedef Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void init(List &L);
void create(List &L);

#endif
