#include "my_libc.h"

char *
my_strchr(const char *s, int c)
{
	int i;
	char ch = ".";
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == (char)c)
			ch = s[i];
	}
	if (ch != ".") {
		return ((char *)&ch);
	}
	return (NULL);
}