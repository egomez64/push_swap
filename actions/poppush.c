/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poppush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:58:11 by egomez            #+#    #+#             */
/*   Updated: 2024/02/08 12:38:28 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	pop(t_stack **lst)
{
	int	val;
	t_stack	*tmp;

	if (!*lst)
		return (0);
	tmp = (*lst)->next;
	val = (*lst)->val;
	free(*lst);
	*lst = tmp;
	return (val);
}

void	push(t_stack **lst, int val)
{
	if (!*lst)
		*lst = lstnew(val);
	else
		lstadd_front(lst, lstnew(val));
}

void	push_back(t_stack **lst, int val)
{
	if (!*lst)
		*lst = lstnew(val);
	else
		lstadd_back(lst, lstnew(val));
}
