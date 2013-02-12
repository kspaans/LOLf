#include <stdio.h>

int main(void)
{
	int i;

	for(i = 0; i < 1000000; i += 1) {
		printf("Look ma, %d hands!\n", i % 5);
	}

	return 0;
}
