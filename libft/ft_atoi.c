/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:15:59 by egomez            #+#    #+#             */
/*   Updated: 2023/11/07 23:21:07 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_lmt(long long conv, int sign, int *error)
{
	if (conv * sign > 2147483647)
		*error = 1;
	if (conv * sign <= -2147483649)
		*error = 1;
}

int	check_begin(const char *nptr, int *sign)
{
	int	i;

	i = 0;
	while (*nptr && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if ((nptr[i] == '+' || nptr[i] == '-') && nptr[i + 1] != 0)
	{
		if (nptr[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nptr, int *error)
{
	long long	conv;
	int			i;
	int			sign;

	conv = 0;
	i = 0;
	sign = 1;
	if (!nptr)
		return (0);
	i = check_begin(nptr, &sign);
	if (nptr[i] < '0' || nptr[i] > '9')
		return (0);
	while (*nptr && nptr[i] >= '0' && nptr[i] <= '9')
	{
		conv = conv * 10 + (nptr[i] - '0');
		check_lmt(conv, sign, error);
		i++;
	}
	return (conv * sign);
}
