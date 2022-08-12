#include <stdio.h>

#include "lib/input_handler.h"

int main()
{
	void on_key_down(void* key)
	{
		char* c = (char*) key;

		printf("char: %c\n", *c);
	}

	ih_key_down(on_key_down);

	return 0;
}

