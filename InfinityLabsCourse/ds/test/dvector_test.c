#include <stdio.h> /* print */

#include "dvector.h"


int main() {
	
	d_vector_t *new_d_vector;
	
	int x = 5, y = 7, z = 10, s = 13, d = 1, a = 9, f = 25, g = 66;
	
	new_d_vector = DVectorCreate(7, sizeof(int));
	
	DVectorPushBack(new_d_vector, &x);
	DVectorPushBack(new_d_vector, &y);
	DVectorPushBack(new_d_vector, &z);
	DVectorPushBack(new_d_vector, &s);
	DVectorPushBack(new_d_vector, &d);
	DVectorPushBack(new_d_vector, &a);
	DVectorPushBack(new_d_vector, &f);
	DVectorPushBack(new_d_vector, &g);
	
	printf("idx 0: %d\n", *(int *)DVectorGet(new_d_vector, 0));
	printf("idx 1: %d\n", *(int *)DVectorGet(new_d_vector, 1));
	printf("idx 2: %d\n", *(int *)DVectorGet(new_d_vector, 2));
	
	printf("size: %ld\n", DVectorSize(new_d_vector));
	printf("capacity: %ld\n", DVectorCapacity(new_d_vector));
	
	DVectorPopBack(new_d_vector);
	
	printf("size: %ld\n", DVectorSize(new_d_vector));
	printf("capacity: %ld\n", DVectorCapacity(new_d_vector));
	
	printf("reserve status: %d\n", DVectorReserve(new_d_vector, 20));
	printf("capacity: %ld\n", DVectorCapacity(new_d_vector));
	
	DVectorDestroy(new_d_vector);
	
	return 0;
}
