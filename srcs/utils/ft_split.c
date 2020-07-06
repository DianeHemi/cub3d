/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 19:41:35 by dchampda          #+#    #+#             */
/*   Updated: 2020/05/01 14:00:29 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		ft_count_words(char const *str, char c)
{
	int		words_count;
	int		i;

	words_count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c && str[i + 1] == c) || (str[i] != c && !str[i + 1]))
			words_count++;
		i++;
	}
	return (words_count);
}

static char		*ft_fill_string(char const *src, char c)
{
	unsigned int	i;
	unsigned int	word_len;
	char			*str;

	i = 0;
	word_len = 0;
	while (src[i] != '\0' && src[i] != c)
	{
		word_len++;
		i++;
	}
	if (!(str = malloc(sizeof(char) * (word_len + 1))))
		return (NULL);
	i = 0;
	while (src[i] != '\0' && src[i] != c)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			**ft_split(char const *s, char c)
{
	char			**res;
	unsigned int	i;
	unsigned int	j;
	unsigned int	nb_words;

	if (!s)
		return (NULL);
	nb_words = ft_count_words(s, c);
	if (!(res = malloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < nb_words)
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		res[i++] = ft_fill_string(&s[j], c);
		while (s[j] != '\0' && s[j] != c)
			j++;
	}
	res[i] = NULL;
	return (res);
}
