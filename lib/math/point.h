#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
	double x;
	double y;
} Point;

Point* point_new(double x, double y) {
	Point* point = (Point*) malloc(sizeof(Point));
	point->x = x;
	point->y = y;
	return point;
}

Point point_new_i(double x, double y) {
	Point point = { .x = x, .y = y };
	return point;
}

Point* point_unit() {
	return point_new(0,0);
}

void point_add(Point* self, Point add) {
	self->x += add.x;
	self->y += add.y;
}

void point_print(void* point) {
	Point* _point = (Point*) point;
	printf("x: %f, y: %f\n", _point->x, _point->y);
}

void point_destroy(Point* point) {
	free(point);
}

