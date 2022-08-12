#ifndef _STACK_DEFINED_
#define _STACK_DEFINED_

typedef struct stack
{
    int* top;
    int size;
    int max;
} Stack;

Stack newStack(int);
int push(Stack*, int);
int pop(Stack*, int*);

#endif
