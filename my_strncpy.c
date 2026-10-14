#include "my_libc.h"

char *
my_strncpy(char *dst, const char *src, size_t n)
{
	char *d = dst;
	size_t i;
	for (i = 0; src[i] != '\0'; i++) {
		if (i < n) {
			d[i] = src[i];
		} else {
			d[i] = '\0';
		}
	}
	return dst;
}