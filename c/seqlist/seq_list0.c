#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// we can store any data in seq, use int value as example
typedef struct {
    int data;      
} Node;

// what's the minimal info that we  need to define a seqlist?
// if we know all the node in the seqlist, we know the seq
// According to the definition of seqlist: it's store in memory one by one, so:
// 1. the begining of seqlist
// 2. the length of seqlist
typedef struct {
    Node* pn;        
    int len;
} Seqlist;

// initial seqlist
// the most natural thought is to allocate memory to store a seq
// how many memory do we need?
// Is it ok to allocate one node? maybe too small
// we ASSUME it is 5 node list
// is it ok to do? let's try it
// we use a function to do so, so we need to decide the return value
// we can use void, just allocate memory
// or we can use pointer to seq as return value
// or we can use boolean value to figure out if it work

// let's try void
// what parameters do we need to use?
// after we initial seq, we need to use it in someway
// maybe pointer to seq is a good choice
// is there other options?
void init(Seqlist* pseq)
{
    // goal: allocate 5 node
    // return: none

    // pseq is pointer of seq
    // *pseq is value of seq structure's value
    // so (*pseq).pn is a pointer to node
    // (*pseq).len is length of seq
    // or we can use pointer form
    // pseq->pn pseq->len

        //pseq->pn = (int*) malloc(5 * sizeof(int));      // <stdlib.h> -- malloc
        //pseq->len = 0;
        // this is wrong

//    pseq = (Seqlist*) malloc(sizeof(Seqlist));
    // we got a seqlist, but how to add 5 node?
    // we need do it again
//    pseq->pn = (Node*) malloc(5 * sizeof(Node));
//    pseq->len = 0;

    pseq->pn = (Node*) malloc(5 * sizeof(Node));
    pseq->len = 0;

    // now we have a seq list which has 5 node
    // Let's try to use it in the main func
}

int main(int argc, char** argv)
{
    // we need a pointer of seqlist
    Seqlist* ptr_seqlist = NULL;

    // try another way
//    Seqlist L;

    // we can use if func to decide if it is initial success
    // and choose different action
    // but I don't do this for now
    init(ptr_seqlist);

//    init(&L);

    // now it's seem we did it
    // let's check it
    // where is ptr_seqlist point?
    // Is length right?
    //printf("the len of seq is %d\n", ptr_seqlist->len);
    
    // I got a seqment falut
    // what's wrong?
    // seqlist is structure
    // we allocate memory for node but not for len
    // how to fix it
    // we should allocate memory for seqlist not just node
    // let's return init to figure out
    printf("the len of seq is %d\n", ptr_seqlist->len);

    free(ptr_seqlist);

//    printf("the len of seq is %d\n", L.len);
    return 0;
}
