#ifndef __WS11_H__
#define __WS11_H__

#define MAX_NAME_LEN (20) 

typedef enum status {OPEN_ERROR = -5, CLOSE_ERROR, WRITE_ERROR, READ_ERROR, REMOVE_FAILED, SUCCESS} status_t;

typedef struct realistic 
{
	float math;
	float physics;
	float chemistry;
} realistic_t;

typedef struct humanistic
{
	float sociology;
	float psychology;
	float literature;
} humanistic_t;

typedef struct grades
{
	realistic_t realistic_grade;
	humanistic_t humanistic_grade;
	float sports;
} grades_t;

typedef struct student
{
	char f_name[MAX_NAME_LEN];
	char l_name[MAX_NAME_LEN];
	grades_t student_grades;
} student_t;


status_t SaveStudent(char *file_name, student_t *student);

status_t LoadStudent(char *file_name, student_t *student);


#endif 
/*__WS11_H__*/
