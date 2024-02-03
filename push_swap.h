#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_stack
{
	int	val;
	struct s_stack *next;
}	t_stack;

int	parse(char *str);
t_stack	*lstnew(int num);
t_stack	*lstlast(t_stack *lst);
void	lstadd_back(t_stack **lst, t_stack *new);
void	lstdelone(t_stack *lst);
void	lstclear(t_stack **lst);

#endif
