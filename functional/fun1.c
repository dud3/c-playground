#include <stdio.h>

typedef int (*Tuple)(int, int);

typedef struct Fun {
	Tuple add;
	Tuple sub;
} Fun;

typedef struct AbsStruct {
	Fun funs;
} AbsStruct;

void printFun(Fun* fun) {
	printf("printFun %d\n", fun->add(1,1));
}

void printAbsStruct(AbsStruct* abs) {
	printf("printAbsStruct %d\n", abs->funs.add(1,1));
}

int main()
{
	int add(int a, int b) {
		int c = a + b;
		return c;
	}

	int sub(int a, int b) {
		int c = a - b;
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

	printFun(funp);

	AbsStruct abs;
	abs.funs.add = add;
	abs.funs.sub = sub;

	AbsStruct* absp;
	absp = &abs;

	printAbsStruct(absp);

	return 0;
}

