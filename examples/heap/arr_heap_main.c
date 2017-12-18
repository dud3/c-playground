#include <stdio.h>

#include "arr_heap.h"

int main()
{
    char arr[] = {'a', 'z', 'd', 'c', 'e'};

    arr_heap* heap = arr_heap_alloc(arr, sizeof(arr)/sizeof(arr[0]));

    arr_heap_print(heap);

    arr_heap_heapify(heap);

    arr_heap_print(heap);

    arr_heap_insert(heap, 'a');

    arr_heap_print(heap);

    arr_heap_remove_top(heap);

    arr_heap_print(heap);

    arr_heap_remove(heap, 2);

    arr_heap_print(heap);

    arr_heap_destroy(heap);

    return 0;
}
