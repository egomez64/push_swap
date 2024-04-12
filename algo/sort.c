/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:31:22 by egomez            #+#    #+#             */
/*   Updated: 2024/02/15 12:25:07 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lenlst(t_stack **lst)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *lst;
	while (tmp && tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	i++;
	return (i);
}

int	find_max(t_stack **lst)
{
	t_stack	*tmp;
	int		val;

	tmp = *lst;
	val = tmp->val;
	while (tmp && tmp->next)
	{
		if (val < tmp->val)
			val = tmp->val;
		tmp = tmp->next;
	}
	if (tmp && val < tmp->val)
		val = tmp->val;
	return (val);
}

int	set_chunk(int len)
{
	int	chunk;

	chunk = (0.000000053 * (len * len)) + (0.03 * len) + 14.5;
	return (chunk);
}

t_stack	*a_to_b(t_stack **lst_a)
{
	int		chunk;
	int		i;
	t_stack	*lst_b;
	int		len;

	lst_b = NULL;
	len = lenlst(lst_a);
	chunk = set_chunk(len);
	i = 0;
	while (len > i)
	{
		if ((*lst_a)->val <= i + chunk)
		{
			pb(&lst_b, lst_a);
			if (lst_b->val > chunk && lst_b->val <= i)
				rb(&lst_b);
			i++;
		}
		else
			ra(lst_a);
	}
	return (lst_b);
}

void	b_to_a(t_stack **lst_b, t_stack **lst_a, int *len_b, int *max)
{
	int		mid;
	int		i;
	t_stack	*tmp_b;

	while (*len_b > 0)
	{
		*max = find_max(lst_b);
		mid = lenlst(lst_b) / 2;
		i = 0;
		tmp_b = *lst_b;
		while (tmp_b->val != *max)
		{
			tmp_b = tmp_b->next;
			i++;
		}
		while ((*lst_b)->val != *max)
		{
			if (i >= mid)
				rrb(lst_b);
			else
				rb(lst_b);
		}
		pa(lst_a, lst_b);
		(*len_b)--;
	}
}
