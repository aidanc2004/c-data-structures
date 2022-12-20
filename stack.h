#ifndef STACK_H
#define STACK_H

typedef struct stack stack;

stack *create_stack(int size);
int push(stack *st, int element);
int pop(stack *st);
void print_stack(stack *st);
int stack_size(stack *st);
void stack_test();

#endif