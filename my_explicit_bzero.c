#include "my_libc.h"

void
my_explicit_bzero(void *buf, size_t len)
{
	volatile unsigned char *p = (volatile unsigned char *)buf;

	while (len > 0) {
		*p++ = 0;
		len--;
	}
}
