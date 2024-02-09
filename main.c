/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:09:03 by egomez            #+#    #+#             */
/*   Updated: 2024/02/09 11:40:48 by egomez           ###   ########.fr       */
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
	t_stack *stack_b;
	t_stack	*affa;
	//t_stack *affb;
	
	i = 1;
	stack_a = NULL;
	//stack_b = NULL;
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
	affa = stack_a;
	while (affa && affa->next)
	{
		printf("%d ", affa->val);
		affa = affa->next;
	}
	printf("%d\n", affa->val);
	stack_a = to_index(&stack_a);
	affa = stack_a;
	while (affa && affa->next)
	{
		printf("%d ", affa->val);
		affa = affa->next;
	}
	printf("%d\n", affa->val);
	/*printf("%d\n", affa->val);
	push_stack(&stack_a, &stack_b);
	push_stack(&stack_a, &stack_b);
	push_stack(&stack_a, &stack_b);
	rrr(&stack_a, &stack_b);
	affa = stack_a;
	affb = stack_b;
	printf("a | b\n");
	while((affa && affa->next) || (affb && affb->next))
	{
		if (affa)
		{
			printf("%d | ", affa->val);
			affa = affa->next;
		}
		if (affb)
		{
			printf("%d", affb->val);
			affb = affb->next;
		}
		printf("\n");
	}
	if (affa)
		printf("%d", affa->val);
	printf(" | ");
	if (affb)
		printf("%d", affb->val);*/
	lstclear(&stack_a);
	lstclear(&stack_b);
}
