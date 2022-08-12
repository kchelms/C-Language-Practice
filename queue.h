#ifndef _QUEUE_DEFINED_
#define _QUEUE_DEFINED_

#include "./stack.h"

struct queue {
    struct stack s1;
    struct stack s2;
    int size;
    int max;
};

struct queue newQueue(int);
int enqueue(struct queue* q, int);
int dequeue(struct queue*, int*);

#endif