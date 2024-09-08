#include <stdio.h>

#include "uid.h"


int main()
{
	my_uid_t uid1 = UIDGenerate();
	my_uid_t uid2 = UIDGenerate();
	
	if (1 == UIDIsEqual(uid1, uid1))
	{
		printf("Generate success\n");
		printf("Is equal <equal test> success\n");
	}
		
	if (0 == UIDIsEqual(uid1, uid2) && 0 == UIDIsEqual(uid1, invalid_uid))
	{
		printf("Is equal <not equal test> success\n");
	}
	return 0;
}
