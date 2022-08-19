#include <stdio.h>
#include <stdlib.h>

typedef struct Vec2 {
	double x;
	double y;
} Vec2;

Vec2* vec2_new(double x, double y) {
	Vec2* vec2 = (Vec2*) malloc(sizeof(Vec2));
	vec2->x = x;
	vec2->y = y;
	return vec2;
}

Vec2 vec2_new_i(double x, double y) {
	Vec2 vec2 = { .x = x, .y = y };
	return vec2;
}

Vec2* vec2_unit() {
	return vec2_new(0,0);
}

void vec2_add(Vec2* self, Vec2 add) {
	self->x += add.x;
	self->y += add.y;
}

void vec2_print(void* vec2) {
	Vec2* _vec2 = (Vec2*) vec2;
	printf("x: %f, y: %f\n", _vec2->x, _vec2->y);
}

void vec2_destroy(Vec2* vec2) {
	free(vec2);
}

