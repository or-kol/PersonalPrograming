#include <stdlib.h>/* malloc */


#include "task.h"


struct task
{
	my_uid_t task_id;
	time_t exe_time;
	act_func_t ActFunc;
	void *params;
	cleanup_func_t CleanUp;
};


task_t *TaskCreate(time_t exe_time, act_func_t ActFunc, void *params, cleanup_func_t CleanUp)
{
	task_t *create_task = (task_t *)malloc(sizeof(task_t));
	if (NULL == create_task)
	{
		return NULL;
	}
	
	create_task->task_id = UIDGenerate();
	create_task->exe_time = exe_time;
	create_task->ActFunc = ActFunc;
	create_task->params = params;
	create_task->CleanUp = CleanUp;
	
	return create_task;
}

void TaskDistroy(task_t *task)
{
	free(task);
}


time_t TaskGetTime(task_t *task)
{
	return task->exe_time;
}


my_uid_t TaskGetUID(task_t *task)
{
	return task->task_id;
}


void TaskSetTime(task_t *task, time_t set_time)
{
	task->exe_time = set_time;
}


time_t TaskRunTask(task_t *task)
{
	return task->ActFunc(task->params);
}


void TaskCleanUp(task_t *task)
{
	task->CleanUp(task->params);
}

int TaskIsBefore(const task_t *task_before, const task_t *task_after)
{
	return TaskGetTime((task_t *)task_before) < TaskGetTime((task_t *)task_after);
}



