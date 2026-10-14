#include "my_libc.h"

char *
my_strncpy(char *dst, const char *src, size_t n)
{
	char *d = dst;
	size_t i;
	for (i = 0; i < n && src[i] != '\0'; i++) {
		d[i] = src[i];
	}
	for (; i < n; i++) {
		d[i] = '\0';
	}
	return dst;
}