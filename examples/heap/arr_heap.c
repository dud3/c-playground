#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

#include "arr_heap.h"

arr_heap* the_arr_heap = NULL;

int cursor;

arr_heap* arr_heap_alloc(char arr[], int n)
{
    the_arr_heap = (arr_heap*) malloc((n) * sizeof(int));

    for(cursor = 0; cursor < n; cursor++)
    {
        *(the_arr_heap + cursor) = arr[cursor];
    }

    cursor--;

    return the_arr_heap;
}

void arr_heap_insert(char n)
{
    char* realloc_arr = realloc(the_arr_heap, (cursor + 2) * sizeof(char));

    if(realloc_arr == NULL)
    {
        fprintf(stderr,
            "Array uninitialized! use arr_heap_alloc(char n) Aborting...\n");
        exit(EXIT_FAILURE);
    }

    the_arr_heap = realloc_arr;

    *(the_arr_heap + (++cursor)) = n;

    swim(cursor);
}

int arr_heap_find(char n)
{
    int i;
    for(i = 0; i < cursor; i++)
    {
        if(*(the_arr_heap + i) == n) {
            return i;
        }
    }

    return -1;
}

inline void arr_heap_remove_top()
{
    arr_heap_remove(0);
}

inline void arr_heap_remove(int i)
{
    arr_heap_swap(i, cursor);

    if(cursor != -1) {
        *(the_arr_heap + cursor) = 0;
    }

    cursor--;

    sink(i);
}

inline int arr_heap_child_left(int cursor)
{
    if(cursor < 0) return -1;
    // 2 x currsor + 1
    return 2 * cursor + 1;
}

inline int arr_heap_child_right(int cursor)
{
    if(cursor < 0) return -1;
    // 2 x currsor + 2
    return 2 * cursor + 2;
}

inline int arr_heap_sibling_left(int cursor)
{
    if(cursor < 0) return -1;

    return cursor - 1;
}

inline int arr_heap_sibling_right(int cursor)
{
    if(cursor <= 0) return -1;

    return cursor + 1;
}

inline int arr_heap_parent(int cursor)
{
    return floor((double)(cursor - 1) / 2);
}

inline void swim(int i)
{
    int parent = arr_heap_parent(i);
    while( *(the_arr_heap + parent) < *(the_arr_heap + i) )
    {
        // swap
        arr_heap_swap(i, parent);

        i = parent;
        parent = arr_heap_parent(i);

        if(i < 0 || parent < 0) break;
    }
}

inline void sink(int i)
{
    if(i >= 0)
    {
        int swap = 0;

        while(cursor > swap)
        {
            int left = arr_heap_child_left(i);
            int right = arr_heap_child_right(i);

            if(the_arr_heap[left] > the_arr_heap[right])
                swap = left;
            else
                swap = right;

            if(the_arr_heap[i] > the_arr_heap[swap]) break;

            arr_heap_swap(i, swap);
            i = swap;
        }
    }
}

void arr_heap_heapify()
{
    int i;
    for(i = 1; i <= cursor; i++)
    {
        int index = i;
        while(index != 0)
        {
            int parent = arr_heap_parent(index);

            if(the_arr_heap[parent] >= the_arr_heap[index]) break;

            arr_heap_swap(index, parent);

            index = parent;
        }
    }
}

void arr_heap_swap(int i, int j)
{
    int tmp = the_arr_heap[i];
    the_arr_heap[i] = the_arr_heap[j];
    the_arr_heap[j] = tmp;
}

void arr_heap_print()
{
    printf("\n");

    int i;
    for(i = 0; i <= cursor; i++)
    {
        printf("%d\t", i);
    }

    printf("\n");

    for(i = 0; i <= cursor; i++)
    {
        printf("%c\t", the_arr_heap[i]);
    }

    printf("\n");
}
