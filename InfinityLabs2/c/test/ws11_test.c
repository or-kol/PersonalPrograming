#include <stdio.h> /* print */

#include "ws11.h"


int main() {
	
	char *file_name = "students_grades.bin";
	student_t student_1 = {"Etuaoin", "Shrdlu", {{1, 2, 3}, {6, 7, 8}, 11}};
	
	student_t student_2 = {0};
	
	
	
	SaveStudent(file_name, &student_1);
	LoadStudent(file_name, &student_2);
	
	printf("%s\n", student_2.f_name);
	printf("%f\n", student_2.student_grades.humanistic_grade.psychology);
	
	remove(file_name);
	return 0;
}
