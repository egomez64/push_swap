/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:31:22 by egomez            #+#    #+#             */
/*   Updated: 2024/02/10 12:22:00 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*a_to_b(t_stack **lsta, t_stack **lstb, int count)
{
	int	i;

	i = 0;

	while (count > 0)
	{
		while ((*lsta)->val != i)
			ra(lsta);
		pb(lstb, lsta);
		i++;
		count--; 
	}
	return (*lstb);
}

t_stack	*b_to_a(t_stack **lsta, t_stack **lstb)
{
	while(*lstb && (*lstb)->next)
		pa(lsta, lstb);
	pa(lsta, lstb);
	return (*lsta);
}
