#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// we can store any data in seq, use int value as example
typedef struct {
    int* data;      
} Node;

// what's the minimal info that we  need to define a seqlist?
// if we know all the node in the seqlist, we know the seq
// According to the definition of seqlist: it's store in memory one by one, so:
// 1. the begining of seqlist
// 2. the length of seqlist
typedef struct {
    int* pn;        
    int len;
} Seqlist;

int main(int argc, char** argv)
{

    return 0;
}
