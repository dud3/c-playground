#ifndef _ARRHEAP_H_
#define _ARRHEAP_H_

typedef char arr_heap;

int cursor;

arr_heap* arr_heap_alloc(char arr[], int n);

void arr_heap_insert(char n);
int arr_heap_find(char n);

inline void arr_heap_remove_top();
inline void arr_heap_remove(int i);

inline int arr_heap_child_left(int cursor);
inline int arr_heap_child_right(int cursor);
inline int arr_heap_sibling_left(int cursor);
inline int arr_heap_sibling_right(int cursor);
inline int arr_heap_parent(int cursor);

inline void swim(int i);
inline void sink(int i);

void arr_heap_heapify();
void arr_heap_swap(int i, int j);
void arr_heap_print();

#endif
