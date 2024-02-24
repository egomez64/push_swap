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
		else if (str[i] == 43 || str[i] == 45)
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
