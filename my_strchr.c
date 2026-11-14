#include "my_libc.h"

char *
my_strchr(const char *s, int c)
{
	char char_c = (char)c;
	do {
		if (*s == char_c)
			return ((char *)s);
	} while (*s++);

	return (NULL);
}