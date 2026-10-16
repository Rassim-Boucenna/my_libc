#include "my_libc.h"

int
my_atoi(const char *nptr)
{
	int result = 0;
	int sign = 1;
	while (*nptr == ' ' || *nptr == '\t') {
		nptr++;
	}
	if (*nptr == '-') {
		sign = -1;
		nptr++;
	} else if (*nptr == '+') {
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9') {
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return result * sign;
}