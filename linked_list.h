#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct linked_list linked_list;

linked_list *create_linked_list();
void free_linked_list(linked_list *list);
void linked_list_append(linked_list *list, int data);
void print_linked_list(linked_list *list);
void linked_list_test();

#endif