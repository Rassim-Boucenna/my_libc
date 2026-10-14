#include "my_libc.h"

char *
my_strcat(char *dst, const char *src)
{
	int i = my_strlen(dst);
	while (src[i] != '\0') {
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return dst;
}