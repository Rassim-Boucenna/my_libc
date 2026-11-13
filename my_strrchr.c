#include <stddef.h>

char *
my_strrchr(const char *s, int c)
{
	const char *last_occurence = NULL;
	do {
		if (*s == (char)c) {
			last_occurence = s;
		}
	} while (*s++);
	return (char *)last_occurence;
}
