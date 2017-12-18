#include <stdio.h>

#include "ll.h"

#include "../../heap/arr_heap.h"

void int_remove(void *data)
{
    printf("%d ", *((int *)(data)));
}

void print(void *data)
{
    printf("%d ", *((int *)(data)));
}

int main()
{
    // heap

    char arr[] = {'a', 'z', 'd', 'c', 'e', 'c', 'm', 'n', 'd'};
    arr_heap* heap = arr_heap_alloc(arr, sizeof(arr)/sizeof(arr[0]));

    char arr1[] = {'c', 'a', 'e', 'd', 'f'};
    arr_heap* heap1 = arr_heap_alloc(arr1, sizeof(arr1)/sizeof(arr1[0]));

    // dll

    dll_node* dll_head = NULL;
    dll_head = dll_list_create(&int_remove, &arr_heap_print);

    // dll insert

    arr_heap_heapify(heap);
    arr_heap_remove(heap, arr_heap_find(heap, 'c'));

    dll_insert(
        dll_insert(dll_head, heap),
    heap1);

    dll_list_print(dll_head);

    return 0;
}
