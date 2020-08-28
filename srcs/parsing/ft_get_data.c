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

int	ft_get_sprite(t_config *config, char *line)
{
	int start;
	int end;

	start = 0;
	if (config->sprite_tex[0] != '\0')
		return (ft_errors("Duplicate sprite declared.\n"));
	while (line[start] == ' ' && line[start] != '\0')
		start++;
	end = start;
	while (line[end] != ' ' && line[end] != '\0')
		end++;
	if (line[end] != '\0')
		end++;
	ft_strncpy(&line[start], config->sprite_tex, end - start - 1);
	return (1);
}