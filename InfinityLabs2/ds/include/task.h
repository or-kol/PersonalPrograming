#ifndef __TASK_H__
#define __TASK_H__

#include <time.h> /* time_t */

#include "uid.h"

/* type of task action func */
typedef time_t (*act_func_t)(void *params);

/* type of task cleanup func */
typedef void (*cleanup_func_t)(void *params);

/* type of task variable */
typedef struct task task_t;


/* TaskCreate:
Description - create a task.
Params:
	time_t exe_time - execution time.
	act_func_t act_func - action function
	void *params - user parameters
	cleanup_func_t clean_up - clean up after function operation.
return value - task_t *.
time complexity - O(1)
space complexity - O(1)
*/
task_t *TaskCreate(time_t exe_time, act_func_t ActFunc, void *params, cleanup_func_t CleanUp);


/* TaskDistroy:
Description - Destroy a task.
Params:
	task_t *task
return value - NONE.
time complexity - O(1)
space complexity - O(1)
*/
void TaskDistroy(task_t *task);


/* TaskIsBefore:
Description - wich of the two tasks will ececute before.
Params:
	const task_t *task_before
	const task_t *task_after
return value - int - boolean.
time complexity - O(1)
space complexity - O(1)
*/
int TaskIsBefore(const task_t *task_before, const task_t *task_after);


/* TaskGetTime:
Description - get task execution time.
Params:
	task_t *task
return value - task_t *.
time complexity - O(1)
space complexity - O(1)
*/
time_t TaskGetTime(task_t *task);


/* TaskGetUID:
Description - get task ID.
Params:
	task_t *task
return value - task_t *.
time complexity - O(1)
space complexity - O(1)
*/
my_uid_t TaskGetUID(task_t *task);


/* TaskGetTime:
Description - set task execution time.
Params:
	task_t *task
	time_t set_time
return value - NONE.
time complexity - O(1)
space complexity - O(1)
*/
void TaskSetTime(task_t *task, time_t set_time);


/* TaskRunTask:
Description - activat task's action function.
Params:
	task_t *task
return value - time_t.
time complexity - O(1)
space complexity - O(1)
*/
time_t TaskRunTask(task_t *task);


/* TaskCleanUp:
Description - cleanup function after task's action function execution.
Params:
	task_t *task
return value - time_t.
time complexity - O(1)
space complexity - O(1)
*/
void TaskCleanUp(task_t *task);

#endif
