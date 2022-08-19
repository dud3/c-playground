#include <stdio.h>

#include "ll.h"

int main()
{
    dll_node* dll_head = NULL;
    dll_head = dll_list_create(10);

    dll_list_print(dll_head);

    dll_node* dll_eight = dll_find(dll_head, 8);

    dll_node_print(dll_eight);

    dll_remove(dll_eight);

    dll_list_print(dll_head);

    return 0;
}
