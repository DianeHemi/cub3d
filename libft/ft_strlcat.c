/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 11:16:09 by dchampda          #+#    #+#             */
/*   Updated: 2020/04/27 13:09:55 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t len_dest;

	i = 0;
	j = 0;
	len_dest = ft_strlen(dest);
	if (size == 0 || len_dest >= size)
		return (ft_strlen(src) + size);
	while (dest[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0' && (i < size - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (ft_strlen(src) + len_dest);
}
