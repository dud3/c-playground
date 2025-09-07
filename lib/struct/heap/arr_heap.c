#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

#include "arr_heap.h"

// For singleton, remove arr_heap* heap parameter
// replace heap with the_arr_heap
// arr_heap* the_arr_heap = NULL;

struct arr_heap
{
    int size;
    char *data;
};

arr_heap* arr_heap_alloc(char arr[], int n)
{
    arr_heap* heap = (arr_heap*) malloc(sizeof(arr_heap));

    heap->data = (char *) malloc(n * sizeof(char));

    for(heap->size = 0; heap->size < n; heap->size++)
    {
        *(heap->data + heap->size) = arr[heap->size];
    }

    heap->size--;

    return heap;
}

void arr_heap_insert(arr_heap *heap, char n)
{
    char* realloc_data = realloc(heap->data, (heap->size + 2) * sizeof(char));

    if(realloc_data == NULL)
    {
        fprintf(stderr,
            "Array uninitialized! use arr_heap_alloc(char n) Aborting...\n");
        exit(EXIT_FAILURE);
    }

    heap->data = realloc_data;

    *(heap->data + (++heap->size)) = n;

    swim(heap, heap->size);
}

int arr_heap_find(arr_heap *heap, char n)
{
    int i;
    for(i = 0; i < heap->size; i++)
    {
        if(*(heap->data + i) == n) {
            return i;
        }
    }

    return -1;
}

inline void arr_heap_remove_top(arr_heap *heap)
{
    arr_heap_remove(heap, 0);
}

inline void arr_heap_remove(arr_heap *heap, int i)
{
    arr_heap_swap(heap, i, heap->size);

    if(heap->size != -1) {
        *(heap->data + heap->size) = 0;
    }

    heap->size--;

    sink(heap, i);
}

inline void arr_heap_destroy(arr_heap *heap)
{
    free(heap->data);
    free(heap);
}

inline int arr_heap_child_left(int i)
{
    if(i < 0) return -1;

    return 2 * i + 1;
}

inline int arr_heap_child_right(int i)
{
    if(i < 0) return -1;

    return 2 * i + 2;
}

inline int arr_heap_sibling_left(int i)
{
    if(i < 0) return -1;

    return i - 1;
}

inline int arr_heap_sibling_right(int i)
{
    if(i <= 0) return -1;

    return i + 1;
}

inline int arr_heap_parent(int i)
{
    return floor((double)(i - 1) / 2);
}

inline void swim(arr_heap *heap, int i)
{
    int parent = arr_heap_parent(i);
    while( *(heap->data + parent) < *(heap->data + i) )
    {
        // swap
        arr_heap_swap(heap, i, parent);

        i = parent;
        parent = arr_heap_parent(i);

        if(i < 0 || parent < 0) break;
    }
}

inline void sink(arr_heap *heap, int i)
{
    if(i >= 0)
    {
        int swap = 0;

        while(heap->size > swap)
        {
            int left = arr_heap_child_left(i);
            int right = arr_heap_child_right(i);

            if(heap->data[left] > heap->data[right])
                swap = left;
            else
                swap = right;

            if(heap->data[i] > heap->data[swap]) break;

            arr_heap_swap(heap, i, swap);
            i = swap;
        }
    }
}

void arr_heap_heapify(arr_heap *heap)
{
    int i;
    for(i = 1; i <= heap->size; i++)
    {
        int index = i;
        while(index != 0)
        {
            int parent = arr_heap_parent(index);

            if(heap->data[parent] >= heap->data[index]) break;

            arr_heap_swap(heap, index, parent);

            index = parent;
        }
    }
}

void arr_heap_swap(arr_heap *heap, int i, int j)
{
    int tmp = heap->data[i];
    heap->data[i] = heap->data[j];
    heap->data[j] = tmp;
}

void arr_heap_node_print(arr_heap *heap, int i)
{
    printf("%c\t", *((char *)(heap->data + i)));
}

void arr_heap_print(arr_heap *heap)
{
    printf("\n");

    int i;
    for(i = 0; i <= heap->size; i++)
    {
        printf("%d\t", i);
    }

    printf("\n");

    for(i = 0; i <= heap->size; i++)
    {
        arr_heap_node_print(heap, i);
    }

    printf("\n");
}

