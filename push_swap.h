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
int	pop(t_stack **lst);
void	push(t_stack **lst, int val);
void	swap_stack(t_stack **lst);
void	push_stack(t_stack **lst1, t_stack **lst2);
void	push_back(t_stack **lst, int val);
void	rotate_stack(t_stack **lst);
void	reverse_rotate_stack(t_stack **lst);
void	sa(t_stack **lst_a);
void	sb(t_stack **lst_b);
void	ss(t_stack **lst_a, t_stack **lst_b);
void	pa(t_stack **lst_a, t_stack **lst_b);
void	pb(t_stack **lst_b, t_stack **lst_a);
void	ra(t_stack **lst_a);
void	rb(t_stack **lst_b);
void	rr(t_stack **lst_a, t_stack **lst_b);
void	rra(t_stack **lst_a);
void	rrb(t_stack **lst_b);
void	rrr(t_stack **lst_a, t_stack **lst_b);
void	lstadd_front(t_stack **lst, t_stack *new);
t_stack	*to_index(t_stack **lst);

#endif
