#include "my_libc.h"

char *
my_strncat(char *dst, const char *src, size_t n)
{
	dst = my_strcat(dst, src);
	dst = my_strncpy(dst, dst, n);
	if (my_strlen(src) > n) {
		dst[my_strlen(dst) - 1] = '\0';
	}
	return dst;
}