/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 22:19:09 by dchampda          #+#    #+#             */
/*   Updated: 2020/04/22 22:30:54 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *tofind;

	tofind = NULL;
	while (*s)
	{
		if (*s == c)
			tofind = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	else
		return (tofind);
}
