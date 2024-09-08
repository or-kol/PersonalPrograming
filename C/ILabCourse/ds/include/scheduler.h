#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include "task.h"
#include "sl.h"
#include "pq.h"
#include "dll.h"
#include "task.h"
#include "uid.h"

/*
	type of task action func:
typedef time_t (*act_func_t)(void *params);

	type of task cleanup func:
typedef void (*cleanup_func_t)(void *params);
*/


/* type of scheduler variable */
typedef struct scheduler sched_t;

/* SCHEDCreate:
Description - create scheduler.
Params: NONE
return value - sched_t *
time complexity - O(1)
space complexity - O(1)
*/
sched_t *SCHEDCreate(void);


/* SCHEDDestroy:
Description - destroy scheduler.
Params:
	sched_t *sched - scheduler.
return value - NONE.
time complexity - O(1)
space complexity - O(1)
*/
void SCHEDDestroy(sched_t *sched);


/* SCHEDAddTask:
Description - add task to scheduler.
Params:
	sched_t *sched - scheduler.
	time_t exe_time - execution time.
	act_func_t act_func - action function
	void *params - user parameters
	cleanup_func_t clean_up - clean up after function operation.
return value - my_uid_t
time complexity - O(n)
space complexity - O(1)
*/
my_uid_t SCHEDAddTask(sched_t *sched, time_t exe_time, act_func_t act_func, void *params, cleanup_func_t clean_up);


/* SCHEDRemoveTask:
Description - remove task from scheduler.
Params:
	sched_t *sched - scheduler.
	my_uid_t task_id - task ID.
return value - NONE.
time complexity - O(n)
space complexity - O(1)
*/
void *SCHEDRemoveTask(my_uid_t task_id, sched_t *sched);


/* SCHEDRun:
Description - run scheduler.
Params:
	sched_t *sched - scheduler.
return value - int.
time complexity - O(n)
space complexity - O(1)
*/
int SCHEDRun(sched_t *sched);


/* SCHEDIsEmpty:
Description - is scheduler empty.
Params:
	const sched_t *sched - scheduler.
return value - int - boolean.
time complexity - O(n)
space complexity - O(1)
*/
int SCHEDIsEmpty(const sched_t *sched);


/* SCHEDSize:
Description - scheduler size.
Params:
	const sched_t *sched - scheduler.
return value - size_t.
time complexity - O(n)
space complexity - O(1)
*/
size_t SCHEDSize(const sched_t *sched);


/* SCHEDStop:
Description - stop scheduler run.
Params:
	sched_t *sched - scheduler.
return value - NONE.
time complexity - O(1)
space complexity - O(1)
*/
void SCHEDStop(sched_t *sched);


/* SCHEDClear:
Description - clear all tasks from scheduler.
Params:
	sched_t *sched - scheduler.
return value - NONE.
time complexity - O(n)
space complexity - O(1)
*/
void SCHEDClear(sched_t *sched);

#endif
/*__SCHEDULER_H__*/



