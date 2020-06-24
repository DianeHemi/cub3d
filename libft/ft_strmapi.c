/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:01:13 by dchampda          #+#    #+#             */
/*   Updated: 2020/04/29 16:45:26 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	res = ft_strdup(s);
	if (!res)
		return (NULL);
	while (res[i] != '\0')
	{
		res[i] = (*f)(i, res[i]);
		i++;
	}
	return (res);
}
