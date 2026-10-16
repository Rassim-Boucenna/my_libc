#include "my_libc.h"

size_t
my_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dst_len = my_strlen(dst);
	size_t src_len = my_strlen(src);

	if (dstsize <= dst_len)
		return dstsize + src_len;

	size_t copy_len = dstsize - dst_len - 1;
	if (copy_len > src_len)
		copy_len = src_len;

	my_memcpy(dst + dst_len, src, copy_len);
	dst[dst_len + copy_len] = '\0';

	return dst_len + src_len;
}