/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:13:53 by egomez            #+#    #+#             */
/*   Updated: 2024/02/03 10:20:47 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char **tmp)
{
	int	i;
	int	y;

	i = 1;
	while (tmp[i])
	{
		y = 0;
		while (tmp[i][y] != '\0' && (tmp[i][y] < '0' || tmp[i][y] > '9'))
			y++;
		if (tmp[i][y] == '\0')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	parse(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
	{
		if (str[i] > 47 && str[i] < 58)
			i++;
		else if ((str[i] == 43 || str[i] == 45) && str[i + 1] != 0)
		{
			if (i > 0)
				return (0);
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int	check_doube(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2 && tmp2->next)
		{
			if (tmp->val == tmp2->val)
				return (0);
			tmp2 = tmp2->next;
		}
		if (tmp->val == tmp2->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
