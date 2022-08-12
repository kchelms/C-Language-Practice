#include <stdlib.h>
#include <stdio.h>
#include "./stack.h"


Stack newStack(int max_size) {
    Stack s = {
        malloc(max_size * sizeof(int)),
        0,
        max_size
    };
    
    return s;
};

int push(Stack* s, int n) {
    int ret = 0;

    if(s->size < s->max) {
        *(++s->top) = n;
        s->size++;

        ret++;
    }

    return ret;
}

int pop(Stack* s, int* out) {
    int ret = 0;

    if(s->size > 0) {
        *out = *(s->top--);

        s->size--;

        ret++;
    }
    
    return ret;
}
