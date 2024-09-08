#define _DEFAULT_SOURCE

#include <string.h> /* memcmp() */
#include <unistd.h> /* gethostid() */
#include <time.h> /* time() */

#include "uid.h"


const my_uid_t invalid_uid = {0};

my_uid_t UIDGenerate()
{
	static int counter;
	
	my_uid_t create_uid = {0};
	create_uid.counter = counter;
	++counter;
	
	create_uid.time_stamp = time(NULL);
	if (-1 == create_uid.time_stamp)
	{
		return invalid_uid;
	}
	
	create_uid.pid = getpid();
	
	create_uid.ip = gethostid();
	if (-1 == create_uid.ip)
	{
		return invalid_uid;
	}
	
	return create_uid;
}

int UIDIsEqual(my_uid_t a, my_uid_t b)
{
	if (0 == memcmp(&a, &b, sizeof(my_uid_t)))
	{
		return 1;
	}
	
	return 0;
}
