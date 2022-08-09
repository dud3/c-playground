#include <stdio.h>
#include <stdlib.h>

#include "ll.h"

// Ds

struct dll_list {
    int size;
    struct dll_node *head;
    struct dll_node *tail;

    void (*remove)(void *data);
    void (*print)(void *data);
};

struct dll_node {
    int n;
    void *data;
    struct dll_node *next;
    struct dll_node *prev;
};

dll_list* the_list = NULL;

// Create node

dll_node* dll_node_create(void *data)
{
    dll_node* np;

    np = (dll_node*) malloc(sizeof(dll_node));
    np->data = data;
    np->next = NULL;
    np->prev = NULL;

    return np;
}

// Create list

dll_node* dll_list_create(void (*remove)(void *data), void (*print)(void *data))
{
    the_list = (dll_list*) malloc(sizeof(dll_list));

    the_list->size = 0;
    the_list->head = dll_node_create(NULL);
    the_list->tail = dll_node_create(NULL);
    the_list->remove = remove;
    the_list->print = print;

    return the_list->head;
}

// Find

inline dll_node* dll_find(dll_node* node, int n)
{
    while(node != NULL) {
        if(node->n == n) {
            return node;
        }

        node = node->next;
    }

    return NULL;
}

// Insert

inline dll_node* dll_insert(dll_node* after_node, void *data)
{
    dll_node* new_node = dll_node_create(data);

    new_node->next = after_node->next;
    new_node->prev = after_node;

    after_node->next = new_node;

    if(new_node->next != NULL) {
        new_node->next->prev = new_node;
    }

    the_list->tail->prev = new_node;

    return new_node;
}

// Remove

inline void dll_node_destroy(dll_node* node)
{
    if(node != NULL) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        free(node);

        the_list->remove(node->data);
    }
}

// Destroy

inline void dll_list_destroy()
{
    dll_node* head = the_list->head;

    while(head != NULL)
    {
        dll_node_destroy(head);
        head->next;
    }
}

// Head node

inline dll_node* dll_node_head_get()
{
    return the_list->head;
}

// Tail node

inline dll_node* dll_node_tail_get()
{
    return the_list->tail;
}

// Print node

void dll_node_print(dll_node* node)
{
    if(node != NULL)
    {
        the_list->print(node->data);
    }
}

// Print from head

void dll_list_print(dll_node* head)
{
    while(head != NULL) {
        if(head->data != NULL) {
            dll_node_print(head);
        }

        head = head->next;
    }

    printf("\n");
}

// Print reverse

void dll_list_printr(dll_node* node)
{
    while(node != NULL) {
        if(node->data != NULL) {
            dll_node_print(node);
        }
        node = node->prev;
    }

    printf("\n");
}
