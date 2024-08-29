#include <time.h> /* time_t */
#include <stdlib.h> /* malloc, free */
#include <unistd.h> /* sleep */

#include "scheduler.h"



struct scheduler
{
	pq_t *pq;
	int stop;
	task_t *running_task;
};


static int IsMatch(const void *val1, const void *val2);
static int CompareFunc(const void *val1, const void *val2);


sched_t *SCHEDCreate(void)
{
	sched_t *create_sched = (sched_t *)malloc(sizeof(sched_t));
	if (NULL == create_sched)
	{
		return NULL;
	}
	
	create_sched->pq = PQCreate(CompareFunc);
	if (NULL == create_sched->pq)
	{
		free(create_sched);
		return NULL;
	}
	
	create_sched->stop = 1;
	create_sched->running_task = NULL;
	return create_sched;
}


void SCHEDDestroy(sched_t *sched)
{
	SCHEDClear(sched);
	PQDestroy(sched->pq);
	free(sched);
}


my_uid_t SCHEDAddTask(sched_t *sched, time_t exe_time, act_func_t act_func, void *params, cleanup_func_t clean_up)
{
	task_t *create_task = TaskCreate(exe_time, act_func, params, clean_up);
	
	if (1 == PQEnqueue(create_task, sched->pq))
	{
		return invalid_uid;
	}
	
	return TaskGetUID(create_task);
}


void *SCHEDRemoveTask(my_uid_t task_id, sched_t *sched)
{
	return PQErase(sched->pq, IsMatch, (void *)&task_id);
}


int SCHEDRun(sched_t *sched)
{
	time_t set_time;
	long interval = 0;
	sched->stop = 0;
	
	while (0 == sched->stop && 0 == PQIsEmpty(sched->pq))
	{
		interval = TaskGetTime(PQPeek(sched->pq)) - time(NULL);
		if (interval >= 0)
		{
			while (interval != 0)
			{
				interval = sleep(interval);
			}
		}
	
		sched->running_task = PQDequeue(sched->pq);
		set_time = TaskRunTask(sched->running_task );
		
		if (0 < set_time)
		{
			TaskSetTime(sched->running_task, set_time);
			PQEnqueue(sched->running_task, sched->pq);
		}
		else
		{
			TaskCleanUp(sched->running_task);
			free(sched->running_task);
			sched->running_task = NULL;
		}
	}
	
	return set_time;
}


int SCHEDIsEmpty(const sched_t *sched)
{
	if (NULL == sched->running_task && 1 == PQIsEmpty(sched->pq))
	{
		return 1;
	}
	
	return 0;
}


size_t SCHEDSize(const sched_t *sched)
{
	if (NULL != sched->running_task)
	{
		return PQSize(sched->pq) + 1;
	}
	
	return PQSize(sched->pq);
}


void SCHEDStop(sched_t *sched)
{
	sched->stop = 1;
}


void SCHEDClear(sched_t *sched)
{
	while (0 != SCHEDSize(sched))
	{
		SCHEDRemoveTask(TaskGetUID((task_t *)PQPeek(sched->pq)), sched);
	}
}


static int IsMatch(const void *val1, const void *val2)
{
	int is_equal = UIDIsEqual(TaskGetUID((task_t *)val1), *(my_uid_t *)val2);
	if (1 == is_equal)
	{
		free((task_t *)val1);
	}
	
	return is_equal;
}


static int CompareFunc(const void *val1, const void *val2)
{	
	return TaskGetTime((task_t *)val1) - TaskGetTime((task_t *)val2);
}

