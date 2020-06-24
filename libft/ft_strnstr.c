/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 12:02:35 by dchampda          #+#    #+#             */
/*   Updated: 2020/04/27 14:36:05 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < len)
	{
		if (s1[i] == s2[0])
		{
			j = i;
			k = 0;
			while (s1[j] == s2[k] && (j < len))
			{
				j++;
				k++;
				if (s2[k] == '\0')
					return ((char *)&s1[i]);
			}
		}
		i++;
	}
	return (0);
}
