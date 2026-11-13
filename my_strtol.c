#include "my_libc.h"
#include <errno.h>
#include <limits.h>

static int
digit_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	return (-1);
}

static const char *
skip_prefix(const char *s, int *base)
{
	if ((*base == 0 || *base == 16) && s[0] == '0' &&
	    (s[1] == 'x' || s[1] == 'X')) {
		*base = 16;
		return (s + 2);
	}
	if (*base == 0) {
		if (s[0] == '0')
			*base = 8;
		else
			*base = 10;
	}
	return (s);
}

long
my_strtol(const char *nptr, char **endptr, int base)
{
	const char *p = nptr;
	unsigned long acc = 0;
	unsigned long cutoff;
	unsigned long cutlim;
	int sign = 1;
	int digit;
	int any = 0;

	if (nptr == NULL) {
		if (endptr != NULL)
			*endptr = NULL;
		return (0);
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

	if (base == 0)
		p = skip_prefix(p, &base);
	else if (base == 16 && p[0] == '0' && (p[1] == 'x' || p[1] == 'X'))
		p += 2;

	if (base < 2 || base > 36)
		return (0);

	cutoff = (sign > 0) ? (unsigned long)LONG_MAX :
			      ((unsigned long)LONG_MAX + 1UL);
	cutlim = cutoff % (unsigned long)base;
	cutoff /= (unsigned long)base;

	while (*p != '\0') {
		digit = digit_value(*p);
		if (digit < 0 || digit >= base)
			break;
		if (acc > cutoff ||
		    (acc == cutoff && (unsigned long)digit > cutlim)) {
			errno = ERANGE;
			if (sign > 0)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		acc = acc * (unsigned long)base + (unsigned long)digit;
		any = 1;
		p++;
	}

	if (endptr != NULL)
		*endptr = (char *)p;

	if (!any)
		return (0);

	if (sign < 0) {
		if (acc == ((unsigned long)LONG_MAX + 1UL))
			return (LONG_MIN);
		return (-(long)acc);
	}
	return ((long)acc);
}