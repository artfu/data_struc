#include <iostream>
#include "list.hpp"

using namespace std;

struct node {
    ElementType data;
    Position next;
};

void init(List &L)
{
    L = NULL;
}

void create(List &L)
{
    int n;
    List p = NULL;

    cout << "n = " << endl;
    cin >> n;
    
    while (n--) {
        p = new Node;
        cin >> p->data;
        p->next = L;
        L = p;
    }
}
