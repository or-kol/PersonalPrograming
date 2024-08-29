#include <stdio.h> /* printf */
#include <string.h> /* memcmp */

#include "scheduler.h"

void CleanUp(void *params);
time_t ActFunc(void *params);

typedef struct params params_t;
struct params
{
	int param;
	sched_t *sched;
};


time_t PrintHello(void *params)
{
	time_t new_time = time(NULL);
	
	if (-1 == new_time)
	{
		return new_time;
	}
	
	printf("Hello %d\n", *(int *)params);
	*(int *)params -= 5;
	
	if (0 >= *(int *)params)
	{
		return 0;
	}
	
	return new_time + 20;
}

time_t PrintHello2(void *params)
{
	time_t new_time = time(NULL);
	
	if (-1 == new_time)
	{
		return new_time;
	}
	
	printf("Hello %d\n", ((params_t *)(params))->param);
	((params_t *)(params))->param -= 5;
	
	if (0 > ((params_t *)(params))->param)
	{
		SCHEDStop(((params_t *)(params))->sched);
		return -1;
	}
	
	if (0 == ((params_t *)(params))->param)
	{
		printf("return 0\n");
		return 0;
	}
	
	
	return new_time + 20;
}


time_t PrintWorld(void *params)
{
	time_t new_time = 0;
	
	printf("world %d\n", *(int *)params);
	
	return new_time;
}


void CleanUp(void *params)
{
	(void)params;
}


int main()
{
	sched_t *sched1 = SCHEDCreate();
	sched_t *sched2 = SCHEDCreate();
	
	time_t time1 = time(NULL);
	int params1 = 5;
	my_uid_t task1 = SCHEDAddTask(sched1, time1, PrintHello, &params1, CleanUp);
	
	time_t time2 = time(NULL)+5;
	int params2 = 10;
	my_uid_t task2 = SCHEDAddTask(sched1, time2, PrintWorld, &params2, CleanUp);
	
	time_t time3 = time(NULL)+10;
	int params3 = 15;
	my_uid_t task3 = SCHEDAddTask(sched1, time3, PrintHello, &params3, CleanUp);
	
	time_t time4 = time(NULL)+7;
	int params4 = 20;
	my_uid_t task4 = SCHEDAddTask(sched1, time4, PrintWorld, &params4, CleanUp);
	
	
	time_t time5 = 0;
	params_t params5 = {0};
	my_uid_t task5;
	
	time_t time6 = 0;
	params_t params6 = {0};
	my_uid_t task6;
	
	time_t time7 = 0;
	params_t params7 = {0};
	my_uid_t task7;
	
	time_t time8 = 0;
	params_t params8 = {0};
	my_uid_t task8;
	
	
	if (4 == SCHEDSize(sched1) && 0 == SCHEDIsEmpty(sched1))
	{
		printf("Create Success\n");
		printf("Add Task Success\n");
		printf("Size Success\n");
		printf("Is Empty Success\n");
	}
	
	SCHEDRun(sched1);
	if (0 == SCHEDSize(sched1) && 1 == SCHEDIsEmpty(sched1))
	{
		printf("Run Success\n");
	}
	
	
	time5 = time(NULL);
	params5.param = 7;
	params5.sched = sched2;
	task5 = SCHEDAddTask(sched2, time5, PrintHello2, &params5, CleanUp);
	
	time6 = time5;
	params6.param = 10;
	params6.sched = sched2;
	task6 = SCHEDAddTask(sched2, time6, PrintWorld, &params6, CleanUp);
	
	time7 = time(NULL) + 10;
	params7.param = 15;
	params7.sched = sched2;
	task7 = SCHEDAddTask(sched2, time7, PrintHello2, &params7, CleanUp);
	
	time8 = time(NULL) + 7;
	params8.param = 20;
	params8.sched = sched2;
	task8 = SCHEDAddTask(sched2, time8, PrintWorld, &params8, CleanUp);
	
	
	SCHEDRun(sched2);	
	if (1 == SCHEDSize(sched2))
	{
		printf("Stop Success\n");
	}
	
	SCHEDClear(sched2);
	if (0 == SCHEDSize(sched2))
	{
		printf("Clear Success\n");
	}
	
	SCHEDDestroy(sched1);
	SCHEDDestroy(sched2);
	return 0;
}
