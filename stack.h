#ifndef STACK_H
#define STACK_H

typedef struct stack stack;

stack *create_stack(int size);
int push(stack *st, int element);
int pop(stack *st);
int peek(stack *st);
void print_stack(stack *st);
void free_stack(stack *st);
int stack_size(stack *st);
int stack_empty(stack *st);
int stack_full(stack *st);
void stack_test();

#endif