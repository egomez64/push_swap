/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:47:07 by egomez            #+#    #+#             */
/*   Updated: 2024/02/10 09:16:35 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_index(t_stack *tmp, t_stack *index, t_stack *compare)
{
	while (compare && compare->next)
	{
		if (tmp->val > compare->val)
			index->val += 1;
		compare = compare->next;
	}
	if (tmp->val > compare->val)
		index->val += 1;
}

t_stack	*to_index(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*compare;
	t_stack	*index;
	t_stack	*tmp_index;

	tmp = *lst;
	index = lstnew(0);
	tmp_index = index;
	while (tmp && tmp->next)
	{
		compare = *lst;
		get_index(tmp, tmp_index, compare);
		tmp = tmp->next;
		lstadd_back(&index, lstnew(0));
		tmp_index = lstlast(index);
	}
	compare = *lst;
	get_index(tmp, tmp_index, compare);
	lstclear(lst);
	return (index);
}
