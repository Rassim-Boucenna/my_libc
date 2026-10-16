#include "my_libc.h"

int
my_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + ('a' - 'A');
	return c;
}