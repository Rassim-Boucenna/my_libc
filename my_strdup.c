#include "my_libc.h"

char *
my_strdup(const char *s)
{
	size_t len = my_strlen(s);
	char *dup = (char *)malloc(len + 1);
	if (dup == NULL) {
		return NULL;
	}
	my_strcpy(dup, s);
	return dup;
}