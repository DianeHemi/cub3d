/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:05:03 by dchampda          #+#    #+#             */
/*   Updated: 2020/07/07 18:00:46 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_line_len(char *line)
{
	int len;
	int	i;

	len = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' && line[i + 1] == ' ')
		{
			len++;
			i++;
		}
		else if (ft_strchr("10NSEW", line[i]) && line[i + 1] == ' ')
		{
			len++;
			i++;
		}
		else
			len++;
		i++;
	}	
	return (len);
}

char	*ft_get_line(char *line)
{
	int i;
	int j;
	int len;
	char *str;

	i = -1;
	j = 0;
	len = ft_line_len(line);
	if (!(str = calloc(len, sizeof(char *))))
		return (NULL);
	while (line[++i])
	{
		if ((line[i] == ' ' && line[i + 1] == ' ')
			|| (ft_strchr("012NSEW", line[i]) && line[i + 1] == ' '))
		{
			str[j] = line[i];
			i++;
		}
		else
			str[j] = line[i];
		j++;
	}
	free(line);
	return (str);
}

int	ft_get_map(int fd, char *line, t_config *config)
{
	int		read;
	char	*map_tmp;
	char	*tmp;

	if (!(map_tmp = malloc(sizeof(char))))
		return (ft_errors("Memory allocation failed.\n"));
	map_tmp[0] = 0;
	tmp = map_tmp;
	map_tmp = ft_get_line(line);
	free(tmp);
	while ((read = get_next_line(fd, &line)) > 0)
	{
		tmp = map_tmp;
		line = ft_get_line(line);
		map_tmp = ft_strjoin(map_tmp, line);
		free(tmp);
		free(line);		
	}
	free(line);
	config->map = ft_split(map_tmp, '\n');
	free(map_tmp);
	return (1);
}
