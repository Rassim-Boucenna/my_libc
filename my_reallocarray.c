#include "my_libc.h"
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>

void *
my_reallocarray(void *ptr, size_t nmemb, size_t size)
{
	size_t total_size;
	void *new_ptr;

	if (nmemb == 0 || size == 0)
		return NULL;
	if (nmemb > SIZE_MAX / size) {
		errno = ENOMEM;
		return NULL;
	}

	total_size = nmemb * size;
	new_ptr = realloc(ptr, total_size);
	if (new_ptr == NULL) {
		errno = ENOMEM;
		return NULL;
	}
	return new_ptr;
}