#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int *array; // array to hold elements of stack
    int top;    // index of top element
    int size;   // size of the stack
} stack;

// create a stack on the heap and return it
stack *create_stack(int size) {
    stack *st = malloc(sizeof(st)); // allocate memory for the stack
    st->array = malloc(sizeof(int)*size); // allocate array
    st->top = -1; // set the index of the top element to be -1
    st->size = size;
    return st;
}

// push an element onto the stack, returns 0 on success, -1 on failure
int push(stack *st, int element) {
    // if at the top of the stack return -1
    if (st->top + 1 == st->size) {
        return -1;
    }

    st->top++; // go to the next space on the stack
    st->array[st->top] = element; // set new top to new element

    return 0;
}

// pop the top element off of the stack, returns the popped element
int pop(stack *st) {
    // if the stack is empty return -1
    if (st->top == -1) {
        return -1;
    }

    // get the top element from the stack
    int element = st->array[st->top];

    // decrement top, top is now the previous element
    st->top--;

    return element;
}

// return the top element on the stack, returns -1 on error
int peek(stack *st) {
    // if stack is empty return -1
    if (st->top == -1) {
        return -1;
    }

    return st->array[st->top];
}

// free the stack
void free_stack(stack *st) {
    free(st->array); // free the array
    free(st);        // free the stuct
}

// get the size of the stack
int stack_size(stack *st) {
    return st->size;
}

// print the stack to stdout
void print_stack(stack *st) {
    for (int i = 0; i <= st->top; i++) {
        printf("%d ", st->array[i]);
    }
    putchar('\n');
}

// test the stack data structure
void stack_test() {
    // create a new stack with size 5
    stack *st = create_stack(5);

    // get and print the size
    printf("size: %d\n", stack_size(st));

    // push three elements onto the stack
    // stack: {5, 10, 15}
    push(st, 5);
    push(st, 10);
    push(st, 15);

    // pop an element off the stack
    // stack: {5, 10}
    printf("popped: %d\n", pop(st));

    // push two more element onto the stack
    // stack: {5, 10, 20, 25}
    push(st, 20);
    push(st, 25);

    printf("top: %d\n", peek(st));

    // print the stack
    printf("stack: ");
    print_stack(st);

    // free the stack when done
    free_stack(st);
}