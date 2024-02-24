NAME = push_swap

LIBFT = libft/libft.a

CC = cc

SRCS = main.c parse.c actions/lst.c actions/poppush.c actions/swap_push.c actions/s.c actions/p.c actions/r.c actions/rr.c algo/index_sort.c algo/sort.c algo/little_sort.c

HEADERS = push_swap.h

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

ifdef DEBUG
CFLAGS = -Wall -Wextra -g
endif

ifdef CHECK
CFLAGS += -fsanitize=address
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
