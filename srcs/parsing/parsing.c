/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 11:43:49 by dchampda          #+#    #+#             */
/*   Updated: 2020/07/13 17:34:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_get_config(t_config *config, char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		return (ft_get_resolution(config, &line[1]));
	else if ((line[0] == 'F' && line[1] == ' ')
		|| (line[0] == 'C' && line[1] == ' '))
		return (ft_get_colors(config, line));
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (ft_get_wall_north(config, &line[2]));
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (ft_get_wall_south(config, &line[2]));
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (ft_get_wall_east(config, &line[2]));
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (ft_get_wall_west(config, &line[2]));
	else if (line[0] == 'S' && line[1] == ' ')
		return (ft_get_sprite(config, &line[1]));
	else if (line[0] == ' ' || line[0] == '\n')
		return (1);
	else
		return (0);
}

int	ft_get_map(int fd, char *line, t_config *config)
{
	int		read;
	char	*map_tmp;
	char	*tmp;

	map_tmp = ft_strdup(line);
	free(line);
	while ((read = get_next_line(fd, &line)) > 0)
	{
		tmp = map_tmp;
		map_tmp = ft_strjoin(map_tmp, line);
		free(tmp);
		free(line);
	}
	tmp = map_tmp;
	map_tmp = ft_strjoin(map_tmp, line);
	free(tmp);
	free(line);
	config->map = ft_split(map_tmp, '\n');
	free(map_tmp);
	config->nb_sprite = ft_get_nb_sprite(config);
	return (1);
}

int	ft_is_map(char *line)
{
	int i;

	i = 0;
	if (ft_strchr("RFCNSEW", line[0]))
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		if (line[i] == '0' || line[i] == '1' || line[i] == '2')
			return (1);
		if (!ft_strchr(" 012NSEW", line[i]))
			return (0);
		i++;
	}
	return (0);
}

int	ft_parsing(char *map, t_config *config)
{
	int		fd;
	int		read;
	char	*line;

	read = 0;
	if ((fd = open(map, O_RDONLY)) < 0)
		return (ft_errors("Error\nCannot open map file.\n"));
	while ((read = get_next_line(fd, &line)) != 0 && !ft_is_map(line))
	{
		if (!ft_get_config(config, line))
		{
			free(line);
			return (ft_errors("Error\nConfiguration is invalid.\n"));
		}
		free(line);
	}
	if (ft_is_map(line))
		read = ft_get_map(fd, line, config);
	else
		free(line);
	close(fd);
	if (read != 1)
		return (ft_errors("Error\nMap is missing.\n"));
	return (1);
}
