#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <termios.h> // termios, TCSANOW, ECHO, ICANON

#include "lib/input_handler.h"

int sum = 1;

int main(int argc, char *argv[])
{
	// char c;
	// c = getc(stdin);
	// printf("Char entered %d\n", c);

	void on_key_down(void* key)
	{
		char* c = (char*) key;

		printf("char: %c\n", *c);
	}

	void* thread_on_key_down(void *) {
		ih_key_down(on_key_down);
	}

	pthread_t tid;
	pthread_attr_t attr;

	if (argc != 2) {
		printf("Error, argc != 2\n");
		return -1;
	}

	printf("argv[1]: %s\n", argv[1]);

	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, thread_on_key_down, argv[1]); 
	// pthread_join(tid, NULL);

	// pthread_exit(NULL);

	sleep(4);

	printf("Continued sum = %d\n", sum);

	while(1) {
		// do nothing...
	}

	return 0;
}

