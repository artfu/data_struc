#include <stdio.h>

int main(int argc, char** argv)
{
    int a[10] = {12, 23, 34, 45, 56,};

    // print the a
    int len1 = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < len1; i++) {
        printf("a[%d] is %d\n", i, a[i]);
    }

    // add '28' to a[2]
    // a[2] = 28; // '23' will lost
    // one way to do this:
    // a[0] = 12 
    // a[1] = 23
    // a[2] = 34
    // a[3] = 45
    // a[4] = 56

    // a[5] = a[4] --> a[5] = 56
    // a[4] = a[3] --> a[4] = 45
    // a[3] = a[2] --> a[3] = 34
    // a[2] = 28
    // a[1] a[0] keep as it is

    // do this with a loop func
    for (int i = 6; i > 2; i--) {
        a[i] = a[i-1];
    }
    // int i = 6 --> 6 = the origin length + 1
    // i > 2 --> 2 = index
    // for (int i = a.len+1; i > index; i--) {
    //      a[i] = a[i-1];
    // }
    //      a[index] = val;
}
    a[2] = 28;

    int len = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < len; i++) {
        printf("a[%d] is %d\n", i, a[i]);
    }

    
    return 0;
}
