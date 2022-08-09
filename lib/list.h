#include <stdio.h>
#include <stdlib.h>
#include "types.h"

typedef struct Node {
	void* data;
	struct Node* next;
	struct Node* prev;
} Node;

typedef struct List {
	int size;
	struct Node* head;
	struct Node* tail;
	
	void (*print)(void *data);
	void (*create)(void *data);
	void (*remove)(void *data);
} List;

Node* list_create_node(void* data) {
	Node* node;
	node = (Node*) malloc(sizeof(Node));
	node->next = NULL;
	node->prev = NULL;
	node->data = data;
	
	return node;
}

List* list_create(void (*print)(void *data)
		,void (*create)(void *data) 
		,void (*remove)(void *data)
		) {
	List* list = (List*) malloc(sizeof(List));
	list->size = 0;
	list->print = print;
	list->create = create;
	list->remove = remove;
	return list;
}

void list_push(List* list, void* data) {
	Node* new_node = list_create_node(data);
	
	if (list->head == NULL) { 
		list->head = new_node;
		list->tail = list->head;
	} else {
		list->tail = new_node;

		/* Current node */
		Node* curr_node = list->head;

		/* While not the last node... */
		while(curr_node->next != NULL) {
			curr_node = curr_node->next;
		}
		
		/* Last node's next is the new node */
		curr_node->next = new_node;

		/* New node's prev is the last node */
		new_node->prev = curr_node;
	}

	list->size++;
}

void list_remove(List* list, Node* node) {
	if (list->size > 0) {
		list->remove(node->data);
		free(node);
		list->size--;
	}
}

void list_traverse(List* list, void (*fn)(void* data)) {
	Node* cnode = list->head;

	while (cnode != NULL) {
		(*fn)(cnode->data);
		cnode = cnode->next;
	}
}

List* list_map(List* list, List* dest, void (*fn)(List*, void* data)) {
	Node* cnode = list->head;

	while (cnode != NULL) {
		(*fn)(dest, cnode->data);
		cnode = cnode->next;
	}

	return dest;
}

void* list_find(List* list, bool (*fn)(void* data)) {
	Node* cnode = list->head;

	while (cnode != NULL) {
		if ((*fn)(cnode->data)) {
			return cnode->data;
		}
		cnode = cnode->next;
	}

	return NULL;
}

void list_print(List* list) {
	list_traverse(list, list->print);
}

