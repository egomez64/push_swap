/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:44:32 by egomez            #+#    #+#             */
/*   Updated: 2024/02/22 16:12:06 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_stack **lst)
{
	t_stack	*tmp;
	int	val;

	tmp = *lst;
	val = tmp->val;
	while (tmp && tmp->next)
	{
		if (val > tmp->val)
			val = tmp->val;
		tmp = tmp->next;
	}
	if (tmp && val > tmp->val)
		val = tmp->val;
	return (val);
}

void	little_sort(t_stack **lst)
{
	int	max;
	int	max_pos;

	max = find_max(lst);
	max_pos = 0;
	if ((*lst)->val == max)
		max_pos = 1;
	else if ((*lst)->next->val == max)
		max_pos = 2;
	if (max_pos == 1)
		ra(lst);
	else if (max_pos == 2)
		rra(lst);
	if ((*lst)->val > (*lst)->next->val)
		sa(lst);
}

void	medium_sort(t_stack **lst_a, t_stack **lst_b)
{
	int	min;
	int	i;
	
	i = 0;
	while (i < 2)
	{
		min = find_min(lst_a);
		while ((*lst_a)->val != min)
			ra(lst_a);
		pb(lst_b, lst_a);
	}
	little_sort(lst_a);
	if ((*lst_b)->val < (*lst_b)->next->val)
		sb(lst_b);
	pa(lst_a, lst_b);
	pa(lst_a, lst_b);
}

int	is_sorted(t_stack **lst_a)
{
	t_stack	*tmp;
	
	tmp = *lst_a;
	while (tmp && tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	if (tmp && tmp->next && tmp->val > tmp->next->val)
		return (0);
	return (1);
}
