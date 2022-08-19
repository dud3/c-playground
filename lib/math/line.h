#include <stdio.h>
#include <stdlib.h>

#include "vec2.h"

typedef struct Line {
	Vec2 a;
	Vec2 b;
} Line;

Line* line_new(Vec2 a, Vec2 b) 
{
	Line* line = (Line*) malloc(sizeof(Line));
	line->a = a;
	line->b = b;
	return line;
}

Line line_new_i(Vec2 a, Vec2 b) 
{
	Line line = { .a = a, .b = b };
	return line;
}

Line* line_unit()
{
	return line_new(vec2_unit_i(),vec2_unit_i());
}

Line* line_set(Line* line, Vec2 a, Vec2 b)
{
	line->a = a;
	line->b = b;
}

void line_add(Line* self, Line add) 
{
	vec2_add(&self->b, add.b);
}

void line_print(void* line) 
{
	Line* ln = (Line*) line;
	printf("a: \n");
	vec2_print(&ln->a);

	printf("b: \n");
	vec2_print(&ln->b);

	// printf("a: %f, b: %f\n", ln->x, ln->y);
}

void line_destroy(Line* line) 
{
	free(line);
}

