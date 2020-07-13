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

int	ft_get_map(int fd, char *line, t_config *config)
{
	int		read;
	char	*map_tmp;
	char	*tmp;

	if (!(map_tmp = malloc(sizeof(char))))
		return (ft_errors("Memory allocation failed.\n"));
	map_tmp[0] = 0;
	tmp = map_tmp;
	map_tmp = ft_strjoin(map_tmp, line);
	free(tmp);
	free(line);
	while ((read = get_next_line(fd, &line)) > 0)
	{
		tmp = map_tmp;
		map_tmp = ft_strjoin(map_tmp, line);
		free(tmp);
		free(line);		
	}
	free(line);
	config->map = ft_split(map_tmp, '\n');
	free(map_tmp);
	return (1);
}
