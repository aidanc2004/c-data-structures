#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue queue;

queue *create_queue(int size);
int enqueue(queue *qu, int element);
int dequeue(stack *st);
int front(queue *qu);
void print_queue(queue *qu);
int queue_size(stack *st);
int is_empty(queue *qu);
int is_full(queue *qu);
void free_queue(queue *qu);
void queue_test();

#endif