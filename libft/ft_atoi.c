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

int	ft_atoi(const char *nptr, int *error)
{
	long long	conv;
	int	i;
	int	sign;

	conv = 0;
	i = 0;
	sign = 1;
	if (!nptr)
		return (0);
	while (*nptr && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	if (nptr[i] < '0' || nptr[i] > '9')
		return (0);
	while (*nptr && nptr[i] >= '0' && nptr[i] <= '9')
	{
		conv = conv * 10 + (nptr[i] - '0');
		if (conv > 2147483647)
			*error = 1;
		if (conv < -2147483648)
			*error = 1;
		i++;
	}
	return (conv * sign);
}
