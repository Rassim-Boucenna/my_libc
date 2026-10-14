#include "my_libc.h"

int
my_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;
	s1 = my_strncpy(s1, s1, n);
	s2 = my_strncpy(s2, s2, n);
	while (i < n && s1[i] != '\0' && s1[i] == s2[i]) {
		i++;
	}
	return (unsigned char)s1[i] - (unsigned char)s2[i];
}