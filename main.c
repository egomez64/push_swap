/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:09:03 by egomez            #+#    #+#             */
/*   Updated: 2024/02/03 11:53:52 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	char	**tmp;
	int	y;
	t_stack	*stack_a;
	t_stack	*aff;
	
	i = 1;
	if (ac < 2)
		return (0);
	while (av[i] != 0)
	{
		y = 0;
		tmp = ft_split(av[i], ' ');
		while (tmp[y] != 0)
		{
			if(!parse(tmp[y]))
			{
				free(tmp);
				printf("ERROR\n");
				return (1);
			}
			if (i == 1 && y == 0)
				stack_a = lstnew(ft_atoi((const char *)tmp[y]));
			else
				lstadd_back(&stack_a, lstnew(ft_atoi((const char *)tmp[y])));
			y++;
		}
		i++;
	}
	free(tmp);
	aff = stack_a;
	while(aff && aff->next)
	{
		printf("%d ", aff->val);
		aff = aff->next;
	}
	printf("%d", aff->val);
	lstclear(&stack_a);
}
