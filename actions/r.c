/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:16:36 by egomez            #+#    #+#             */
/*   Updated: 2024/02/09 09:23:26 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **lst_a)
{
	rotate_stack(lst_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **lst_b)
{
	rotate_stack(lst_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **lst_a, t_stack **lst_b)
{
	rotate_stack(lst_a);
	rotate_stack(lst_b);
	write(1, "rr\n", 3);
}
