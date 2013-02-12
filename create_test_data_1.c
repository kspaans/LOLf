#include <unistd.h>
#include <stdio.h>

int main()
{
	int buf[] = {
		0, 1, 45,
	};

	write(1, buf, sizeof(buf));

	return 0;
}
