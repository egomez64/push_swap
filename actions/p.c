/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:48:35 by egomez            #+#    #+#             */
/*   Updated: 2024/02/08 14:55:05 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **lst_a, t_stack **lst_b)
{
	push_stack(lst_b, lst_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **lst_b, t_stack **lst_a)
{
	push_stack(lst_a, lst_b);
	write(1, "pb\n", 3);
}
