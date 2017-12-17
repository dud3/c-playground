#include <stdio.h>
#include <stdlib.h>

#include "ll.h"

// Ds

struct dll_list {
    int size;
    struct dll_node *head;
    struct dll_node *tail;

    void (*create)(void *data);
    void (*remove)(void *data);
};

struct dll_node {
    int n;
    void *data;
    struct dll_node *next;
    struct dll_node *prev;
};

dll_node* dll_head = NULL;
dll_node* dll_tail = NULL;

// Head node

inline dll_node* dll_node_head_get()
{
    return dll_head;
}

// Tail node

inline dll_node* dll_node_tail_get()
{
    return dll_tail;
}

// Create node

dll_node* dll_node_create(int n)
{
    dll_node* np;

    np = (dll_node*) malloc(sizeof(dll_node));
    np->n = n;
    np->next = NULL;
    np->prev = NULL;

    return np;
}

// Create list

dll_node* dll_list_create(int n)
{
    dll_node* np;

    int i;
    for(i = 1; i <= n; i++) {
        np = dll_node_create(i);

        if(dll_head == NULL) {
            dll_head = np;
        } else {
            np->prev = dll_tail;
            dll_tail->next = np;
        }

        dll_tail = np; // save the last node for the next time
    }

    return dll_head;
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

inline dll_node* dll_insert(dll_node* after_node, int n)
{
    dll_node* new_node = dll_node_create(n);

    new_node->prev = after_node;
    new_node->next = after_node->next;

    after_node->next->prev = new_node;
    after_node->next = new_node;
}

// Remove

inline void dll_remove(dll_node* node)
{
    if(node != NULL) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        free(node);
    }
}

// Print node

void dll_node_print(dll_node* node)
{
    if(node != NULL)
    {
        printf("\nPrint node: %d\n", node->n);
    }
}

// Print from head

void dll_list_print(dll_node* head)
{
    while(head != NULL) {
        printf("%d ", head->n);
        head = head->next;
    }

    printf("\n");
}

// Print reverse

void dll_list_printr(dll_node* node)
{
    while(node != NULL) {
        printf("%d ", node->n);
        node = node->prev;
    }

    printf("\n");
}
