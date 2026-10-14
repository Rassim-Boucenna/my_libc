// my_strcpy
#include "my_libc.h"

char *
my_strcpy(char *dst, const char *src)
{
	char *d = dst;
	int i = 0;
	while (src[i] != '\0') {
		d[i] = src[i];
		i++;
	}
	return dst;
}