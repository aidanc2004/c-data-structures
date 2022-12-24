#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int *array; // array to hold elements of queue
    int rear;   // index of the last element
    int size;   // size of the queue
} queue;

// create a stack on the heap and return it
queue *create_queue(int size) {
    queue *qu = malloc(sizeof(qu)); // allocate memory for the queue
    qu->array = malloc(sizeof(int)*size); // allocate array
    qu->rear = -1; // set the index of the rear element to be -1
    qu->size = size;
    return qu;
}

// insert an element into the queue
int enqueue(queue *qu, int element) {
    // if queue is full
    if (qu->rear + 1 == qu->size) {
        return -1;
    }

    // set rear to next free space
    qu->rear++;

    // push all elements back
    for (int i = qu->rear; i != 0; i--) {
        qu->array[i] = qu->array[i-1];
    }

    // set front to element
    qu->array[0] = element;

    return 0;
}

// remove an element from the queue and return it, -1 if empty
int dequeue(queue *qu) {
    // if empty
    if (qu->rear == -1) {
        return -1;
    }

    int element = qu->array[0];

    // remove first element and shift back other elements
    for (int i = 0; i < qu->rear; i++) {
        qu->array[i] = qu->array[i+1];
    }

    qu->rear--; // decrement rear to last element

    return element;
}

// get front element of the queue, -1 if empty
int front(queue *qu) {
    if (qu->rear == -1) {
        return -1;
    }

    return qu->array[0];
}

// print the queue to stdout
void print_queue(queue *qu) {
    for (int i = 0; i <= qu->rear; i++) {
        printf("%d ", qu->array[i]);
    }
    putchar('\n');
}

// free the queue
void free_queue(queue *qu) {
    free(qu->array); // free the array
    free(qu);        // free the stuct
}

// get the size of the queue
int queue_size(queue *qu) {
    return qu->size;
}

// if the queue is empty
int queue_empty(queue *qu) {
    return qu->rear == -1;
}

// if the queue is full
int queue_full(queue *qu) {
    return qu->rear+1 == qu->size;
}

// test the queue
void queue_test() {
    // create a new queue with size 5
    queue *qu = create_queue(5);

    // get and print the size
    printf("size: %d\n", queue_size(qu));

    // queue three elements onto the queue
    // queue: {15, 10, 5}
    enqueue(qu, 5);
    enqueue(qu, 10);
    enqueue(qu, 15);

    // dequeue an element from the queue
    // queue: {10, 5}
    printf("removed: %d\n", dequeue(qu));

    printf("front: %d\n", front(qu));

    // print the queue
    printf("queue: ");
    print_queue(qu);

    // remove all elements from queue
    dequeue(qu);
    dequeue(qu);

    printf("empty? %d\n", is_empty(qu));

    // add 5 elements to queue
    for (int i = 0; i < queue_size(qu); i++) {
        enqueue(qu, i);
    }

    printf("full? %d\n", is_full(qu));

    // free the stack when done
    free_queue(qu);
}