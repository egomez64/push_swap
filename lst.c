/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:10:36 by egomez            #+#    #+#             */
/*   Updated: 2024/01/25 13:50:39 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstnew(int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->val = num;
	new->next =NULL;
	return (new);
}

t_stack	*lstlast(t_stack *lst)
{
	while(lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		lstlast(*lst)->next = new;
	else
		*lst = new;
}

void	lstdelone(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	lstclear(t_stack **lst)
{
	if (!lst && !(*lst))
		return ;
	if ((*lst)->next)
		lstclear(&(*lst)->next);
	lstdelone(*lst);
	*lst = NULL;
}
