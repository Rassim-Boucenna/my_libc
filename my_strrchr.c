#include "my_libc.h"

char *
my_strrchr(const char *s, int c)
{
	char *ch = NULL;
	while (*s != '\0') {
		if (*s == (char)c)
			ch = (char *)s;
		s++;
	}
	if ((char)c == '\0') {
		return (char *)s;
	}
	return ch;
}