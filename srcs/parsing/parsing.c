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

int	ft_check_config(t_config *config)
{
	if (config->width <= 0 || config->height <= 0)
		return (ft_errors("Resolution incorrect.\n"));
	if (config->width > 2560)
		config->width = 2560;
	if (config->height > 1440)
		config->height = 1440;
	if (config->f_color < 0 || config->c_color < 0)
		return (ft_errors("Floor or ceiling color is incorrect.\n"));
	if (config->north_tex[0] == '\0' || config->south_tex[0] == '\0'
		|| config->east_tex[0] == '\0' || config->west_tex[0] == '\0'
		|| config->sprite_tex[0] == '\0')
		return (ft_errors("Textures are missing.\n"));
	if (!ft_open_tex(config))
		return (ft_errors("Cannot open textures.\n"));
	if (!ft_check_map(config))
		return (ft_errors("Map is incorrect.\n"));		
	return (1);
}

int		ft_is_map(char *line)
{
	int i;

	i = 0;
	if (ft_strchr("RFCNSEW", line[0]))
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		if (line[i] == '0' || line[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_config(t_config *config, char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		return (ft_get_resolution(config, &line[1]));
	else if ((line[0] == 'F' && line[1] == ' ')
		|| (line[0] == 'C' && line[1] == ' '))
		return (ft_get_colors(config, line));
	else if (line[0] == 'N' && line[1] == 'O')
		return (ft_get_wall_north(config, &line[2]));
	else if (line[0] == 'S' && line[1] == 'O')
		return (ft_get_wall_south(config, &line[2]));
	else if (line[0] == 'E' && line[1] == 'A')
		return (ft_get_wall_east(config, &line[2]));
	else if (line[0] == 'W' && line[1] == 'E')
		return (ft_get_wall_west(config, &line[2]));
	else if (line[0] == 'S' && line[1] == ' ')
		return (ft_get_sprite(config, &line[1]));
	else if (line[0] == ' ' || line[0] == '\n' || line[0] == '\0')
		return (1);
	else
		return (0);
	return (1);
}

int	ft_parsing(char *map, t_config *config)
{
	int		fd;	
	int		read;
	char 	*line;

	read = 0;
	if ((fd = open(map, O_RDONLY)) < 0)
		return (ft_errors("Error: cannot open map\n"));
	while ((read = get_next_line(fd, &line)) != 0 && !ft_is_map(line))
	{
		if (!ft_get_config(config, line))
		{
			free(line);
			return (ft_errors("Error : Configuration is invalid.\n"));
		}
		free(line);
	}	
	if (ft_is_map(line))
		ft_get_map(fd, line, config);
	else
		return (ft_errors("Error : Map is missing.\n"));
	close(fd);
	return (1);
}
