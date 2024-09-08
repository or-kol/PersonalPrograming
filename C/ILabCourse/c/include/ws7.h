#ifndef __WS7_H__
#define __WS7_H__

#include <stddef.h>/* size_t */
#include <stdio.h>/* FILE */

typedef enum status_t {OPEN_FAILED = -5, CLOSE_FAILED, EXIT_OPERATION, REMOVE_FAILED, FAIL, SUCCESS, LOGGER, ADD_BEGINNING, REMOVE} return_status;

void PrintStructArr();

int Logger(const char file_name[]);

#endif 
/*__WS7_H__*/
