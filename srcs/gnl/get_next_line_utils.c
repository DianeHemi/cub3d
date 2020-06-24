/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 12:21:37 by dchampda          #+#    #+#             */
/*   Updated: 2020/05/13 12:21:38 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char const *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char		*ft_strndup(char *str, int len)
{
	char	*copy;
	int		i;

	i = 0;
	if (!(copy = malloc(sizeof(char) * len + 1)))
		return (copy);
	while (str[i] != '\0' && i < len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i] != '\0')
		dest[i++] = (char)s1[j++];
	j = 0;
	while (s2[j] != '\0')
		dest[i++] = (char)s2[j++];
	dest[i] = '\0';
	return (dest);
}

int			find_n(char *buffer, char c)
{
	int		i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*copy_after_n(char *str, int start)
{
	int		i;
	int		len;
	char	*tmp;

	len = ft_strlen(str);
	i = 0;
	if (!str || (!(tmp = (char *)malloc(len - start + 1))))
		return (NULL);
	while (str[start])
	{
		tmp[i] = str[start];
		start++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
