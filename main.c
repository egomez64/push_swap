/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:09:03 by egomez            #+#    #+#             */
/*   Updated: 2024/04/11 17:11:33 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear(t_stack **lst_a, t_stack **lst_b)
{
	lstclear(lst_a);
	if (lst_b)
		lstclear(lst_b);
}

void	init(char **av, t_stack **stack_a, int *error)
{
	int		i;
	int		y;
	char	**tmp;

	i = 0;
	while (av[++i] != 0)
	{
		y = -1;
		tmp = ft_split(av[i], ' ');
		while (tmp[++y] != 0)
		{
			if (!parse(tmp[y]))
			{
				*error = 1;
				free_split(tmp);
				return ;
			}
			if (i == 1 && y == 0)
				*stack_a = lstnew(ft_atoi((const char *)tmp[y], error));
			else
				lstadd_back(stack_a,
					lstnew(ft_atoi((const char *)tmp[y], error)));
		}
		free_split(tmp);
	}
}

void	choose_sort(t_stack **lst_a, t_stack **lst_b)
{
	int	len_b;
	int	max;

	max = 0;
	if (lenlst(lst_a) == 2)
		sa(lst_a);
	else if (lenlst(lst_a) == 3)
		little_sort(lst_a);
	else if (lenlst(lst_a) <= 5)
		medium_sort(lst_a, lst_b);
	else
	{
		*lst_b = a_to_b(lst_a);
		len_b = lenlst(lst_b);
		b_to_a(lst_b, lst_a, &len_b, &max);
	}
}

int	check_sort(t_stack **lst)
{
	if (is_sorted(lst))
	{
		lstclear(lst);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		error;

	stack_a = NULL;
	stack_b = NULL;
	error = 0;
	if (ac < 2 || !check_num(av))
		return (1);
	init(av, &stack_a, &error);
	if (error > 0 || !stack_a || !check_doube(&stack_a))
	{
		clear(&stack_a, &stack_b);
		write(1, "Error\n", 6);
		return (1);
	}
	stack_a = to_index(&stack_a);
	if (check_sort(&stack_a))
		return (0);
	choose_sort(&stack_a, &stack_b);
	clear(&stack_a, &stack_b);
	return (0);
}
