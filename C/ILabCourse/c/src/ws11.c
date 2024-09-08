#include <stdio.h> /* FILE */

#include "ws11.h"

static status_t SerialRealGrd(char *file_name, student_t *student, FILE *fptr)
{
	size_t n_write;
	
	if (NULL == fptr)
	{
		return OPEN_ERROR;
	}
	
	n_write = fwrite(&student->student_grades.realistic_grade.math, sizeof(float), 1, fptr);
	if (1 != n_write)
	{
		if (SUCCESS != fclose(fptr))
		{
			return CLOSE_ERROR;
		}
		if (SUCCESS != remove(file_name))
		{
			return REMOVE_FAILED;
		}
		return WRITE_ERROR;
	}
	
	n_write = fwrite(&student->student_grades.realistic_grade.physics, sizeof(float), 1, fptr);
	if (1 != n_write)
	{
		if (SUCCESS != fclose(fptr))
		{
			return CLOSE_ERROR;
		}
		if (SUCCESS != remove(file_name))
		{
			return REMOVE_FAILED;
		}
		return WRITE_ERROR;
	}
	
	n_write = fwrite(&student->student_grades.realistic_grade.chemistry, sizeof(float), 1, fptr);
	if (1 != n_write)
	{
		if (SUCCESS != fclose(fptr))
		{
			return CLOSE_ERROR;
		}
		if (SUCCESS != remove(file_name))
		{
			return REMOVE_FAILED;
		}
		return WRITE_ERROR;
	}
	
	return SUCCESS;
}


static status_t SerialHumanGrd(char *file_name, student_t *student, FILE *fptr)
{
	size_t n_write;
	
	if (NULL == fptr)
	{
		
		return OPEN_ERROR;		
	}
	
	n_write = fwrite(&student->student_grades.humanistic_grade.sociology, sizeof(float), 1, fptr);
	if (1 != n_write)
	{
		if (SUCCESS != fclose(fptr))
		{
			return CLOSE_ERROR;
		}
		if (SUCCESS != remove(file_name))
		{
			return REMOVE_FAILED;
		}
		return WRITE_ERROR;
	}
	
	n_write = fwrite(&student->student_grades.humanistic_grade.psychology, sizeof(float), 1, fptr);
	if (1 != n_write)
	{
		if (SUCCESS != fclose(fptr))
		{
			return CLOSE_ERROR;
		}
		if (SUCCESS != remove(file_name))
		{
			return REMOVE_FAILED;
		}
		return WRITE_ERROR;
	}
	
	n_write = fwrite(&student->student_grades.humanistic_grade.literature, sizeof(float), 1, fptr);
	if (1 != n_write)
	{
		if (SUCCESS != fclose(fptr))
		{	
			return CLOSE_ERROR;
		}
		
		if (SUCCESS != remove(file_name))
		{
			return REMOVE_FAILED;
		}
		
		return WRITE_ERROR;
		
	}
	
	return SUCCESS;
}

status_t SerialSportGrd(char *file_name, student_t *student, FILE *fptr)
{
	size_t n_write;
	        
	n_write = SerialRealGrd(file_name, student, fptr);
	if (SUCCESS != n_write)
	{	
		return n_write;
	}
	
	n_write = SerialHumanGrd(file_name, student, fptr);
	if (SUCCESS != n_write)
	{	
		return n_write;
	}
	
	n_write = fwrite(&student->student_grades.sports, sizeof(float), 1, fptr);
	if (1 != n_write)
	{
		if (SUCCESS != fclose(fptr))
		{	
			return CLOSE_ERROR;
		}
		
		if (SUCCESS != remove(file_name))
		{
			return REMOVE_FAILED;
		}
		
		return WRITE_ERROR;
	}	
	
	return SUCCESS;
}


status_t SaveStudent(char *file_name, student_t *student)
{
	size_t n_write;
	FILE *fptr = fopen(file_name, "wb");
	if (NULL == fptr)
	{		
		return OPEN_ERROR;		
	}
	
	n_write = fwrite(student->f_name, MAX_NAME_LEN, 1, fptr);
	if (1 != n_write)
	{
		if (SUCCESS != fclose(fptr))
		{	
			return CLOSE_ERROR;
		}
		
		if (SUCCESS != remove(file_name))
		{
			return REMOVE_FAILED;
		}
		
		return WRITE_ERROR;
	}	
	
	n_write = fwrite(student->l_name, MAX_NAME_LEN, 1, fptr);
	if (1 != n_write)
	{
		if (SUCCESS != fclose(fptr))
		{	
			return CLOSE_ERROR;
		}
		
		if (SUCCESS != remove(file_name))
		{
			return REMOVE_FAILED;
		}
		
		return WRITE_ERROR;
	}
		
	n_write = SerialSportGrd(file_name, student, fptr);
	if (SUCCESS != n_write)
	{	
		return n_write;
	}
	
	if (SUCCESS != fclose(fptr))
	{	
		return CLOSE_ERROR;
	}
	
	return SUCCESS;
}

/*********************************************************************************************************************************/

status_t DeSerialRealGrd(student_t *student, FILE *fptr)
{
	size_t n_read;        
	n_read = fread(&student->student_grades.realistic_grade.math, sizeof(float), 1, fptr);
	if (1 != n_read)
	{
		if (SUCCESS != fclose(fptr))
		{
			return CLOSE_ERROR;
		}
		
		return READ_ERROR;
	}
	
	n_read = fread(&student->student_grades.realistic_grade.physics, sizeof(float), 1, fptr);
	if (1 != n_read)
	{
		if (SUCCESS != fclose(fptr))
		{
			return CLOSE_ERROR;
		}
		
		return READ_ERROR;
	}
	
	n_read = fread(&student->student_grades.realistic_grade.chemistry, sizeof(float), 1, fptr);
	if (1 != n_read)
	{
		if (SUCCESS != fclose(fptr))
		{
			return CLOSE_ERROR;
		}
		
		return READ_ERROR;
	}
	
	return SUCCESS;
}

status_t DeSerialHumanGrd(student_t *student, FILE *fptr)
{
	size_t n_read;       
	n_read = fread(&student->student_grades.humanistic_grade.sociology, sizeof(float), 1, fptr);
	if (1 != n_read)
	{
		if (SUCCESS != fclose(fptr))
		{
			return CLOSE_ERROR;
		}
		
		return READ_ERROR;
	}
	
	n_read = fread(&student->student_grades.humanistic_grade.psychology, sizeof(float), 1, fptr);
	if (1 != n_read)
	{
		if (SUCCESS != fclose(fptr))
		{
			return CLOSE_ERROR;
		}
		
		return READ_ERROR;
	}
	
	n_read = fread(&student->student_grades.humanistic_grade.literature, sizeof(float), 1, fptr);
	if (1 != n_read)
	{
		if (SUCCESS != fclose(fptr))
		{	
			return CLOSE_ERROR;
		}
		
		return READ_ERROR;
	}
	
	return SUCCESS;
}

status_t DeSerialSportGrd(student_t *student, FILE *fptr)
{
	size_t n_read;
	
	n_read = DeSerialRealGrd(student, fptr);
	if (SUCCESS != n_read)
	{	
		return n_read;
	}
	
	n_read = DeSerialHumanGrd(student, fptr);
	if (SUCCESS != n_read)
	{	
		return n_read;
	}
	
	n_read = fread(&student->student_grades.sports, sizeof(float), 1, fptr);
	if (1 != n_read)
	{
		if (SUCCESS != fclose(fptr))
		{	
			return CLOSE_ERROR;
		}
		
		return READ_ERROR;
	}
			
	return SUCCESS;
}

status_t LoadStudent(char *file_name, student_t *student)
{
	size_t n_read;
	FILE *fptr = fopen(file_name, "rb");
	if (NULL == fptr)
	{		
		return OPEN_ERROR;		
	}
	
	n_read = fread(student->f_name, MAX_NAME_LEN, 1, fptr);
	if (1 != n_read )
	{
		if (SUCCESS != fclose(fptr))
		{	
			return CLOSE_ERROR;
		}
		
		return READ_ERROR;
	}
	
	n_read = fread(student->l_name, MAX_NAME_LEN, 1, fptr);
	if (1 != n_read)
	{
		if (SUCCESS != fclose(fptr))
		{	
			return CLOSE_ERROR;
		}
		
		return READ_ERROR;
	}	
	
	n_read = DeSerialSportGrd(student, fptr);
	if (SUCCESS != n_read)
	{	
		return n_read;
	       	
		if (SUCCESS != fclose(fptr))
	        {	
		        return CLOSE_ERROR;
	        }	
	}
	
	if (SUCCESS != fclose(fptr))
	{	
		return CLOSE_ERROR;
	}	
	       
	return SUCCESS;
}











