/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:13:48 by egomez            #+#    #+#             */
/*   Updated: 2024/02/08 13:05:22 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_stack(t_stack **lst)
{
	int	tmp1;
	int	tmp2;

	if (!*lst || !(*lst)->next)
		return ;
	tmp1 = pop(lst);
	tmp2 = pop(lst);
	push(lst, tmp1);
	push(lst, tmp2);
}

void	push_stack(t_stack **lst1, t_stack **lst2)
{
	int	tmp;

	if (!*lst1)
		return ;
	tmp = pop(lst1);
	push(lst2, tmp);
}

void	rotate_stack(t_stack **lst)
{
	int	tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = pop(lst);
	push_back(lst, tmp);
}

void	reverse_rotate_stack(t_stack **lst)
{
	int		tmp;
	int		i;
	t_stack	*last;

	i = 0;
	if (!*lst)
		return ;
	last = *lst;
	while (last->next)
	{
		last = last->next;
		i++;
	}
	tmp = pop(&last);
	push(lst, tmp);
	last = *lst;
	while (i > 0)
	{
		last = last->next;
		i--;
	}
	last->next = NULL;
}
