#include <stdio.h>

typedef int (*Tuple)(int, int);

typedef struct Fun {
	Tuple add;
} Fun;

int main()
{
	int add(int a, int b) {
		int c = a + b;
		return c;
	}
	
	Fun fun;
	fun.add = add;

	int x = fun.add(2,2);

	printf("x: %d\n", x);

	Fun* funp;
	funp = &fun;
	// funp->add = add;

	printf("x: %d\n", funp->add(2,2));

	return 0;
}

