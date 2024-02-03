NAME = push_swap

LIBFT = libft/libft.a

CC = cc

SRCS = main.c parse.c lst.c

HEADERS = push_swap.h

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

ifdef DEBUG
CFLAGS = -Wall -Wextra -Werror -g
endif

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(LIBFT):
	@make -C libft/ all

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJS)
	@make -C libft/ clean
	
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all fclean clean re
