#include <stdlib.h>

void* mem_alloc(size_t size) {
	void* p = malloc(size);
	return p;
}

#define MAP(type) mem_lambda(type (*fn)(void* data))

void mem_lambda(void* (*fn)(void* data)) {
	int* n = (int*) mem_alloc(sizeof(int));
}

