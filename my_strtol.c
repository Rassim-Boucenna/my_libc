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
	return (36);
}

static const char *
skip_prefix(const char *s, int *base)
{
	int hex;

	hex = (s[0] == '0' && (s[1] == 'x' || s[1] == 'X') &&
	    digit_value(s[2]) < 16);
	if ((*base == 0 || *base == 16) && hex) {
		*base = 16;
		return (s + 2);
	}
	if (*base == 0)
		*base = (s[0] == '0') ? 8 : 10;
	return (s);
}
