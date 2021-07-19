#include <iostream>
#include "list.hpp"

using namespace std;

int main()
{
    List L;

    init(L);
    cout << L << endl;

    create(L);
    cout << L << endl;

    return 0;
}
