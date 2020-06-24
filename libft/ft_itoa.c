/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 12:15:43 by dchampda          #+#    #+#             */
/*   Updated: 2020/05/07 14:49:39 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nb_size(long nb, int sign)
{
	unsigned int	nb_size;

	nb_size = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		nb_size++;
	}
	if (sign == -1)
		nb_size++;
	return (nb_size);
}

static char			*fill_str(char *res, long nbr, int nb_size, int sign)
{
	res[nb_size] = '\0';
	while (nb_size > 0)
	{
		res[--nb_size] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}

char				*ft_itoa(int n)
{
	char			*res;
	long			nbr;
	unsigned int	nb_size;
	int				sign;

	sign = 1;
	if (n < 0)
	{
		nbr = (long)n * -1;
		sign = -1;
	}
	else
		nbr = n;
	nb_size = ft_nb_size(nbr, sign);
	if (!(res = malloc(sizeof(char) * nb_size + 1)))
		return (NULL);
	fill_str(res, nbr, nb_size, sign);
	return (res);
}
