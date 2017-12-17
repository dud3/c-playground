#ifndef _DLL_H_
#define _DLL_H_

typedef struct dll_list dll_list;
typedef struct dll_node dll_node;

dll_node* dll_node_head_get();
dll_node* dll_node_tail_get();
dll_node* dll_node_create(int n);
dll_node* dll_list_create(int n);
dll_node* dll_find(dll_node* node, int n);
dll_node* dll_insert(dll_node* after_node, int n);

void dll_remove(dll_node* node);
void dll_node_print(dll_node* node);
void dll_list_print(dll_node* head);
void dll_list_printr(dll_node* node);

#endif // _DLL_H_
