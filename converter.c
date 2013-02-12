/*
 * Convert LOLog line binary data into human readable text.
 */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "output_format.h"

void printf_arity(char *f, unsigned int num, unsigned int *args)
{
	switch (num) {
	case 0:
		printf(f);
		break;
	case 1:
		printf(f, args[0]);
		break;
	case 2:
		printf(f, args[0], args[1]);
		break;
	case 3:
		printf(f, args[0], args[1], args[2]);
		break;
	default:
		printf("LOL TOO MANY ARGUMENTS!\n");
		break;
	}
}

char *formats[] = {
	"Hi there bro number %d\n",
	"Go away.",
};

int main(int argc, char **argv)
{
	int fd;
	ssize_t r;
	unsigned int id;
	unsigned int len;
	unsigned int buf[10];

	fd = open(argv[1], O_RDONLY, "r");
	if (fd < 0) {
		return -1;
	}

	while (1) {
		r = read(fd, &id, sizeof(id));
		if (sizeof(id) != r) {
			printf("no more input\n");
			return 0;
		}
		printf("Read id %d\n", id);
		r = read(fd, &len, sizeof(len));
		if (sizeof(len) != r) {
			return -1;
		}
		printf("Read %d, will read that many words\n", len);
		r = read(fd, buf, len*sizeof(len));
		if (len*sizeof(len) != r) {
			printf("Couldn't read enough!\n");
			return -1;
		}
		printf_arity(formats[id], len, buf);
	}

	return 0;
}
