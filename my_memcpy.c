#include "my_libc.h"
#include <stddef.h>

void *
my_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char *d = (unsigned char *)dst;
	const unsigned char *s = (const unsigned char *)src;
	size_t i = 0;

	if (dst == NULL || src == NULL) {
		return NULL;
	}

	while (i < len) {
		d[i] = s[i];
		i++;
	}

	return dst;
}
