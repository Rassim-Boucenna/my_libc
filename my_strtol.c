#include "my_libc.h"
#include <errno.h>
#include <limits.h>

static int
my_digit_value(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'z')
		return c - 'a' + 10;
	if (c >= 'A' && c <= 'Z')
		return c - 'A' + 10;
	return -1;
}

long
my_strtol(const char *nptr, char **endptr, int base)
{
	const char *p = nptr;
	unsigned long value = 0;
	int sign = 1;
	int digit;

	if (nptr == NULL) {
		if (endptr != NULL)
			*endptr = NULL;
		return 0;
	}

	if (endptr != NULL)
		*endptr = (char *)nptr;

	while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r' ||
	    *p == '\v' || *p == '\f')
		p++;

	if (*p == '+') {
		p++;
	} else if (*p == '-') {
		sign = -1;
		p++;
	}

	if (base == 0) {
		if (*p == '0') {
			base = 8;
			if (p[1] == 'x' || p[1] == 'X') {
				base = 16;
				p += 2;
			}
		} else {
			base = 10;
		}
	}

	if (base < 2 || base > 36)
		return 0;

	while (*p != '\0') {
		digit = my_digit_value(*p);

		if (digit < 0 || digit >= base)
			break;

		if (sign > 0 &&
		    value > (unsigned long)LONG_MAX / (unsigned long)base) {
			errno = ERANGE;
			return LONG_MAX;
		}

		if (sign > 0 &&
		    value == (unsigned long)LONG_MAX / (unsigned long)base &&
		    (unsigned long)digit >
			(unsigned long)LONG_MAX % (unsigned long)base) {
			errno = ERANGE;
			return LONG_MAX;
		}

		if (sign < 0 &&
		    value >
			((unsigned long)LONG_MAX + 1UL) / (unsigned long)base) {
			errno = ERANGE;
			return LONG_MIN;
		}

		if (sign < 0 &&
		    value ==
			((unsigned long)LONG_MAX + 1UL) / (unsigned long)base &&
		    (unsigned long)digit >
			((unsigned long)LONG_MAX + 1UL) % (unsigned long)base) {
			errno = ERANGE;
			return LONG_MIN;
		}

		value = value * (unsigned long)base + (unsigned long)digit;
		p++;
	}

	if (endptr != NULL)
		*endptr = (char *)p;

	return (sign > 0) ? (long)value : -(long)value;
}