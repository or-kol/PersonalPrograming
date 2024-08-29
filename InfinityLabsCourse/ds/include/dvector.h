#ifndef __DVECTOR_H__
#define __DVECTOR_H__

#include <stddef.h> /* size_t */

/* type of the dynamic vector management struct */
typedef struct d_vector d_vector_t;
typedef enum tatus {FAIL_TO_RESIZE = -1, SUCCESS = 0} status_t;

/* DVectorCreate:
Description - create the dynamic vector data structure
Params:
	size_t capasity - how many variables can the dynamic vector contain.
	size_t size_of_element - size of each elment in bytes.
return value - d_vector_t *
time complexity - O(1)
space complexity - O(1)
*/
d_vector_t *DVectorCreate(size_t capacity, size_t size_of_element);

/* DVectorDestroy:
Description - delete the dynamic vector data structure
Params:
	d_vector_t * d_vector - management struct.
return value - void
time complexity - O(1)
space complexity - O(1)
*/
void DVectorDestroy(d_vector_t *d_vector);

/* DVectorGet:
Description - get the requested value.
Params:
	const d_vector_t *d_vector - management struct.
	size_t idx - indx of requested value.
return value - void *
time complexity - O(1)
space complexity - O(1)
*/
void *DVectorGet(const d_vector_t *d_vector, size_t idx);


/* DVectorPushBack:
Description - add value to the dynamic vector.
Params:
	d_vector_t *d_vector - management struct.
	const void *val - value to add to the dynamic vector.
return value - int
time complexity - O(1)
space complexity - O(1)
*/
status_t DVectorPushBack(d_vector_t *d_vector, const void *val);


/* DVectorPopBack:
Description - remove value from the dynamic vector.
Params:
	d_vector_t *d_vector - management struct.
return value - int
time complexity - O(1) amortized O(n)
space complexity - O(1)
*/
status_t DVectorPopBack(d_vector_t *d_vector);

/* DVectorSize:
Description - get dynamic vector size.
Params:
	const d_vector_t *d_vector - management struct.
return value - size_t
time complexity - O(1)
space complexity - O(1)
*/
size_t DVectorSize(const d_vector_t *d_vector);


/* DVectorCapacity:
Description - get dynamic vector capacity.
Params:
	const d_vector_t *d_vector - management struct.
return value - size_t
time complexity - O(1)
space complexity - O(1)
*/
size_t DVectorCapacity(const d_vector_t *d_vector);


/* DVectorShrink:
Description - shrink dynamic vector capacity by half of the difference
	between size to capacity if size < 50% of capacity.
Params:
	d_vector_t *d_vector - management struct.
return value - int
time complexity - O(1)
space complexity - O(1)
*/
status_t DVectorShrink(d_vector_t *d_vector);


/* DVectorReserve:
Description - set new capacity to dynamic vector
Params:
	d_vector_t *d_vector - management struct.
	size_t new_capacity - new capacity
return value - int
time complexity - O(1)
space complexity - O(1)
*/
status_t DVectorReserve(d_vector_t *d_vector, size_t new_capacity);

#endif /*__DVECTOR_H__*/



