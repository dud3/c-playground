#ifndef _ARRHEAP_H_
#define _ARRHEAP_H_

typedef struct arr_heap arr_heap;

arr_heap* arr_heap_alloc(char arr[], int n);

void arr_heap_insert(arr_heap *heap, char n);
int arr_heap_find(arr_heap *heap, char n);

inline void arr_heap_remove_top(arr_heap *heap);
inline void arr_heap_remove(arr_heap *heap, int i);
inline void arr_heap_destroy(arr_heap *heap);

inline int arr_heap_child_left(int cursor);
inline int arr_heap_child_right(int cursor);
inline int arr_heap_sibling_left(int cursor);
inline int arr_heap_sibling_right(int cursor);
inline int arr_heap_parent(int cursor);

inline void swim(arr_heap *heap, int i);
inline void sink(arr_heap *heap, int i);

void arr_heap_heapify(arr_heap *heap);
void arr_heap_swap(arr_heap *heap, int i, int j);
void arr_heap_print(arr_heap* heap);

#endif
