#include "my_libc.h"

char *
my_strncat(char *dst, const char *src, size_t n)
{
	dst = my_strcat(dst, src);
	dst = my_strncpy(dst, dst, n);
	return dst;
}