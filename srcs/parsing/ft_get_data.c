/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 14:58:39 by dchampda          #+#    #+#             */
/*   Updated: 2020/07/13 17:28:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int ft_get_player_pos(t_config *config, int y, int x)
{
	if (config->player_start == '0')
	{
		config->player_x = x;
		config->player_y = y;
		config->player_start = config->map[y][x];
		config->map[y][x] = '0';
	}
	else
		return (ft_errors("Only one camera allowed.\n"));
	return (1);
}

int	ft_get_resolution(t_config *config, char *line)
{
	int i;

	i = 0;
	if (config->width != 0 || config->height != 0)
		return (ft_errors("Duplicate resolution data.\n"));
	while (line[i] == ' ')
		i++;
	config->width = ft_atoi(&line[i]);
	while (line[i] != ' ')
		i++;
	config->height = ft_atoi(&line[i]);
	return (1);
}

int	ft_get_sprite(t_config *config, char *line)
{
	int i;
	int j;

	i = 0;
	if (config->sprite_tex[0] != '\0')
		return (ft_errors("Duplicate sprite declared.\n"));
	while (line[i] == ' ' && line[i] != '\0')
		i++;
	j = i;
	while (line[j] != ' ' && line[j] != '\0')
		j++;
	ft_strncpy(&line[i], config->sprite_tex, j - i - 1);
	return (1);
}

int	ft_open_tex(t_config *config)
{
	int fd;

	if ((fd = open(config->north_tex, O_RDONLY)) < 0)
		return (0);
	if ((fd = open(config->south_tex, O_RDONLY)) < 0)
		return (0);
	if ((fd = open(config->east_tex, O_RDONLY)) < 0)
		return (0);
	if ((fd = open(config->west_tex, O_RDONLY)) < 0)
		return (0);
	if ((fd = open(config->sprite_tex, O_RDONLY)) < 0)
		return (0);
	return (1);
}
