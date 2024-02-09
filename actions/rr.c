/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:26:44 by egomez            #+#    #+#             */
/*   Updated: 2024/02/09 09:32:47 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **lst_a)
{
	reverse_rotate_stack(lst_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **lst_b)
{
	reverse_rotate_stack(lst_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **lst_a, t_stack **lst_b)
{
	reverse_rotate_stack(lst_a);
	reverse_rotate_stack(lst_b);
	write(1, "rrr\n", 4);
}
