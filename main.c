/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:09:03 by egomez            #+#    #+#             */
/*   Updated: 2024/02/10 11:45:46 by egomez           ###   ########.fr       */
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
	t_stack *affb;
	
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
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
			free(tmp[y]);
			y++;
		}
		free (tmp);
		i++;
	}
	
	affa = stack_a;
	printf("stack a : ");
	while (affa && affa->next)
	{
		printf("%d ", affa->val);
		affa = affa->next;
	}
	printf("%d\n", affa->val);
	stack_a = to_index(&stack_a);
	i = lstcount(&stack_a);
	affa = stack_a;
	printf("indexation\n");
	printf("stack a : ");
	while(affa && affa->next)
	{
		printf("%d ", affa->val);
		affa = affa->next;
	}
	printf("%d\n", affa->val);
	stack_b = a_to_b(&stack_a, &stack_b, i);
	affb = stack_b;
	printf("sort in b\n");
	printf("stack b : ");
	while(affb && affb->next)
	{
		printf("%d ", affb->val);
		affb = affb->next;
	}
	printf("%d\n", affb->val);
	stack_a = b_to_a(&stack_a, &stack_b);
	affa = stack_a;
	printf("sort in a\n");
	printf("stack a : ");
	while(affa && affa->next)
	{
		printf("%d ", affa->val);
		affa = affa->next;
	}
	printf("%d\n", affa->val);
	lstclear(&stack_a);
	lstclear(&stack_b);
}
