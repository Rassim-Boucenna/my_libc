#include "my_libc.h"

size_t
my_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t src_len;

	if (dst == NULL || src == NULL)
		return 0;

	src_len = my_strlen(src);

	if (dstsize == 0)
		return src_len;

	if (src_len + 1 < dstsize) {
		my_memcpy(dst, src, src_len + 1);
		return src_len;
	}

	my_memcpy(dst, src, dstsize - 1);
	dst[dstsize - 1] = '\0';
	return src_len;
}