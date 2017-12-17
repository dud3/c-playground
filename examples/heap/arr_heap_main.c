#include <stdio.h>

#include "arr_heap.h"

int main()
{
    char arr[] = {'a', 'z', 'd', 'c', 'e'};

    arr_heap* heap = arr_heap_alloc(arr, sizeof(arr)/sizeof(arr[0]));

    arr_heap_print();

    arr_heap_heapify();

    arr_heap_print();

    arr_heap_insert('a');

    arr_heap_print();

    arr_heap_remove_top();

    arr_heap_print();

    arr_heap_remove(2);

    arr_heap_print();

    return 0;
}
