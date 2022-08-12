#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int sum = 1;
void *runner(void *param);

int main(int argc, char *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;

	if (argc != 2) {
		printf("Error, argc != 2\n");
		return -1;
	}

	printf("argv[1]: %s\n", argv[1]);

	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, runner, argv[1]); 
	pthread_join(tid, NULL);

	printf("sum = %d\n", sum);

	return 0;
}

void *runner(void* param)
{
	char* c = (char*)param;
	int i = atoi(c);

	printf("x: %d\n", i);

	sum += i;
	
	pthread_exit(0);
}

