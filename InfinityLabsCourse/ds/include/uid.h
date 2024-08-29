#ifndef __UID_H__
#define __UID_H__

#include <stddef.h> /*size_t */
#include <time.h> /* time_t */
#include <sys/types.h> /* pid_t */


/* UID struct - variable might change*/
typedef struct uid
{
	size_t counter;
	time_t time_stamp;
	pid_t pid;
	long ip;
}my_uid_t;


/* Global value to define invalid UID*/
extern const my_uid_t invalid_uid; 


/* UIDIsEqual:
Description - generate UID.
Params: NONE.
return value - my_uid_t
time complexity - O(1)
space complexity - O(1)
*/
my_uid_t UIDGenerate();


/* UIDIsEqual:
Description - check if to UIDs are equal.
Params: NONE.
return value - int
time complexity - O(1)
space complexity - O(1)
*/
int UIDIsEqual(my_uid_t a, my_uid_t b);






/* StackDestroy:
Description - delete the stack.
Params:
	stack_t *stack - management struct.
return value - NONE.
time complexity - O(1)
space complexity - O(1)
*/



#endif /*__UID_H__*/



