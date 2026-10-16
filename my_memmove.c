#include "my_libc.h"

void *
my_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d = dst;
	const unsigned char *s = src;

	if (d < s) {
		while (len--)
			*d++ = *s++;
	} else {
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}

	return dst;
}