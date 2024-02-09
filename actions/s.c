/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:34:35 by egomez            #+#    #+#             */
/*   Updated: 2024/02/08 14:40:33 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **lst_a)
{
	swap_stack(lst_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **lst_b)
{
	swap_stack(lst_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **lst_a, t_stack **lst_b)
{
	swap_stack(lst_a);
	swap_stack(lst_b);
	write(1, "ss\n", 3);
}
