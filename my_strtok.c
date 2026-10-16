#include "my_libc.h"

char *
my_strtok(char *str, const char *delim)
{
    static char *saveptr = NULL;
    char *token;

    if (delim == NULL || *delim == '\0')
        return NULL;
    if (str == NULL)
        str = saveptr;
    if (str == NULL)
        return NULL;

    while (*str != '\0' && my_strchr(delim, *str) != NULL)
        str++;

    if (*str == '\0') {
        saveptr = NULL;
        return NULL;
    }

    token = str;
    while (*str != '\0' && my_strchr(delim, *str) == NULL)
        str++;

    if (*str != '\0') {
        *str = '\0';
        saveptr = str + 1;
    } else {
        saveptr = NULL;
    }

    return token;
}