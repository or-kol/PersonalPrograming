#include "ws7.h"


int main() {
	
	const char file_name[] = "../../fwrite.txt";
	
	PrintStructArr();
	
	printf("status: %d\n", Logger(file_name));
	
	return 0;
}
