#include "my_libc.h"

char *
my_strchr(const char *s, int c)
{
	char ch = (char)c;

	while (*s != '\0') {
		if (*s == ch) {
			return (char *)s;
		}
		s++;
	}
	if (*s == ch) {
		return (char *)s;
	}
	return NULL;
}