#include <stdio.h>

#include "line.h"

int main()
{
	Line* line = line_new(vec2_new_i(0,0), vec2_new_i(4,4));
	line_print(line);

	Line* line_u = line_unit();
	line_print(line_u);

	line_set(line_u, vec2_new_i(2,2), vec2_new_i(8,8));
	line_print(line_u);

	return 0;
}

