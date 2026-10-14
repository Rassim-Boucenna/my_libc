#include "my_libc.h"

char *
my_strncat(char *dst, const char *src, size_t n)
{
	char *new_dst = my_strncpy(dst, dst, n);
	int i = my_strlen(new_dst);
	int j = 0;
	while (src[j] != '\0' && j < n) {
		new_dst[i] = src[j];
		i++;
		j++;
	}
	new_dst[i] = '\0';
	return new_dst;
}