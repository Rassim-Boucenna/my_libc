NAME = libmy_libc.a

CC ?= cc
CFLAGS ?= -Wall -Wextra -Werror -std=c11 -c
AR ?= ar
ARFLAGS = rcs

SRC = my_strlen.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c my_libc.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re