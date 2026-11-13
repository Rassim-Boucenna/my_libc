#include "my_libc.h"

size_t
my_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i = 0;
	while (i + 1 < dstsize && src[i] != '\0') {
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0) {
		dst[i] = '\0';
	}
	while (src[i] != '\0') {
		i++;
	}
	return (i);
}
