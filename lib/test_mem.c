#include <stdio.h>
#include "mem.h"

typedef struct Vec2 {
	int x;
	int y;
} Vec2;

int main() {
	int* ia = (int*) mem_alloc(sizeof(int));
	*ia = 2;

	printf("%d\n", *ia);

	Vec2* vec2 = (Vec2*) mem_alloc(sizeof(Vec2));
	vec2->x = 1;
	vec2->y = 1;

	printf("x: %d, y: %d\n", vec2->x, vec2->y);

	mem_map(int);

	return 1;
}
