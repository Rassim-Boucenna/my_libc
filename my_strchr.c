#include "my_libc.h"

char *
my_strchr(const char *s, int c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	}
	return (NULL);
}