#include "my_libc.h"

char *
my_strncat(char *dst, const char *src, size_t n)
{
	int i = my_strlen(dst);
	int j = 0;
	while (src[j] != '\0' && j < n) {
		dst[i] = src[j];
		i++;
		j++;
	}
	while (i < n) {
		dst[i] = '\0';
		i++;
		j++;
	}
	dst[i] = '\0';
	return dst;
}