#include "my_libc.h"

char *
my_strtok(char *str, const char *delim)
{
	static char *saveptr;
	char *token;

	if (str == NULL)
		str = saveptr;

	/* Skip leading delimiters */
	while (*str && my_strchr(delim, *str))
		str++;

	if (*str == '\0') {
		saveptr = str;
		return NULL;
	}

	token = str;

	/* Find the end of the token */
	while (*str && !my_strchr(delim, *str))
		str++;

	if (*str) {
		*str = '\0';
		saveptr = str + 1;
	} else {
		saveptr = str;
	}

	return token;
}