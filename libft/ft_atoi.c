/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 14:36:34 by dchampda          #+#    #+#             */
/*   Updated: 2020/05/10 15:00:33 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	int			negative;
	long int	res;

	i = 0;
	negative = 1;
	res = 0;
	while ((nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r')))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			negative = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
	{
		if (res > 2147483647 && negative == 1)
			return (-1);
		if (res > 2147483648 && negative == -1)
			return (0);
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * negative);
}
