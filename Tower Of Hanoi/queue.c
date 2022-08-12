#include <stdio.h>
#include "./queue.h"

struct queue newQueue(int max_size) {    
    struct queue q = {
        newStack(max_size),
        newStack(max_size),
        0,
        max_size
    };

    return q;
}

int enqueue(struct queue* q, int n) {    
    int ret = q->size < q->max;

    if(ret) {
        int rec;

        while(pop(&q->s2, &rec))
            push(&q->s1, rec);

        push(&q->s1, n);

        while(pop(&q->s1, &rec))
            push(&q->s2, rec);

        q->size++;
    }

    return ret;  
}

int dequeue(struct queue* q, int* out) {
    int ret = q->size > 0;

    if(ret) {
        ret = pop(&q->s2, out);

        if(ret)
            q->size--;
    }

    return ret;
}
