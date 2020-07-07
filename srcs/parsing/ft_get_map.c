/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:05:03 by dchampda          #+#    #+#             */
/*   Updated: 2020/07/07 17:46:21 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_get_map(int fd, char *line, t_config *config)
{
	int		read;
	char	*map_tmp;
	int		i;

	i = 0;

	//Copier contenu de la 1ere ligne qu'on a encore en stock
	map_tmp = ft_strdup(line);
	map_tmp[ft_strlen(map_tmp)] = '\n';
	free(line);

	
	//Puis lire avec while et copier au fur et a mesure
	//Lire les lignes 1 par 1 et les copier ?
	while ((read = get_next_line(fd, &line)) > 0)
	{
		line[ft_strlen(line)] = '\n';
		
		map_tmp = ft_strjoin(map_tmp, line);

		free(line);		
	}

	
		config->map = ft_split(map_tmp, '\n');

	return (1);
}
