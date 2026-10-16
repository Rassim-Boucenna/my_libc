#include "my_libc.h"

int
my_isalpha(int c)
{
	c = (unsigned char)c;
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}