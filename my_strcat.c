#include "my_libc.h"

char *
my_strcat(char *dst, const char *src)
{
	int i = my_strlen(dst);
	int j = 0;
	while (src[j] != '\0') {
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return dst;
}