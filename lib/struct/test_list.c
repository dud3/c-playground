#include <stdio.h>
#include "util.h"
#include "list.h"
#include "point.h"

int main() {
	Point* point = point_unit();
	point_add(point, point_new_i(2,2));

	/* create list */

	List* list_point = list_create(point_print, lambda, lambda);

	list_push(list_point, point);
	list_push(list_point, point_new(1,1));

	list_print(list_point);

	/* size */

	printf("length/size: %d\n", list_point->size);

	/* traverse */

	void point_traverse(void* data) {
		Point* point = (Point*) data;
		point_print(point);
	}

	list_traverse(list_point, point_traverse);

	/* map Point to double */

	void double_print(void* n) {
		double* _n = (double*) n;
		printf("double: %f\n", *_n);
	}

	void point_to_int(List* dest, void* data) {
		Point* point = (Point*) data;
		list_push(dest, &(point->x));
	}

	// List* dobule_list = list_create(double_print, lambda, lambda);
	List* list_double = list_map(list_point,
		list_create(double_print, lambda, lambda),
		point_to_int);

	list_print(list_double);

	/* find in list */

	bool point_find(void* data) {
			Point* point = (Point*) data;
			if (point->x == 2) return true;

			return false;
	}

	Point* the_point = list_find(list_point, point_find);

	/* int list */

	List* list_int = list_create(util_print_int, lambda, lambda);
	list_push(list_int, util_int_p(0));
	list_push(list_int, util_int_p(1));

	list_print(list_int);

	/* other util stuff */

	util_print_int(util_int_p(1));
	util_print_double(util_double_p(2.0f));

	return 1;
}
