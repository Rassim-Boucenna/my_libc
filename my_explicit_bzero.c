#include "my_libc.h"

void
my_explicit_bzero(void *s, size_t len)
{
	volatile unsigned char *p = (volatile unsigned char *)s;
	while (len--)
		*p++ = 0;
}