#include <stdio.h>
#include <stdlib.h>

// node of a list
struct node {
    int data; // data held by the node
    struct node *next; // the next node in the list
};

// linked list data structure
typedef struct linked_list {
    struct node *head; // the head of the list
} linked_list;

// create an empty linked list
linked_list *create_linked_list() {
    linked_list *list = malloc(sizeof(list));
    list->head = NULL; // set head to null
    return list;
}

// create a new node
struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// free a linked list
void free_linked_list(linked_list *list) {
    struct node *temp = list->head; // set temp to the head of the list
    struct node *next = NULL; // node after temp

    // while node is not empty
    while (temp != NULL) {
        next = temp->next;
        free(temp); // free node at temp
        temp = next; // set temp to next node
    }

    free(list); // free list
}

// append data to the end of a linked list
void linked_list_append(linked_list *list, int data) {
    // if list is empty
    if (list->head == NULL) {
        list->head = create_node(data);
        return;
    }

    struct node *temp = list->head; // set temp to the head of the list

    // traverse through list until at last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // set next to new node
    temp->next = create_node(data);
}

void print_linked_list(linked_list *list) {
    struct node *temp = list->head; // set temp to the head of the list

    // traverse through list until at last node
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// test the linked list
void linked_list_test() {
    linked_list *list = create_linked_list();

    linked_list_append(list, 1);
    linked_list_append(list, 2);
    linked_list_append(list, 3);

    print_linked_list(list);

    free_linked_list(list);
}