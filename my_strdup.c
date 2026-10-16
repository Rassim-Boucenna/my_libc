#include "my_libc.h"
#include <stdlib.h>

char *
my_strdup(const char *s)
{
	size_t len;
	char *dup;

	if (s == NULL)
		return NULL;
	len = my_strlen(s);
	dup = (char *)malloc(len + 1);
	if (dup == NULL)
		return NULL;
	my_strcpy(dup, s);
	return dup;
}