CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

NAME = my_libc.a
SRCS = my_strlen.c my_strcpy.c my_strncpy.c my_strcat.c my_strncat.c my_strcmp.c my_strncmp.c my_strchr.c my_strrchr.c my_strstr.c my_memset.c my_memcpy.c my_memmove.c my_memcmp.c my_memchr.c my_strdup.c my_strtok.c my_strlcpy.c my_strlcat.c my_explicit_bzero.c my_isdigit.c my_reallocarray.c my_isalpha.c my_isalnum.c my_isspace.c my_isprint.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

format :
	clang-format -i $(SRCS) $(HEADERS)

check:
	clang-format --dry-run --Werror $(SRCS) $(HEADERS)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re