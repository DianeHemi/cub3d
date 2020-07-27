/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 11:43:41 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/24 11:43:43 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int ft_check_top_bot(t_config *config)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (config->map[0][x])
	{
		if (config->map[0][x] != ' ' && config->map[0][x] != '1')
			return (0);
		x++;
	}
	while (config->map[y])
		y++;
	x = 0;
	y--;
	while (config->map[y][x])
	{
		if (config->map[y][x] != ' ' && config->map[y][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int ft_check_sides(t_config *config)
{
	int y;
	int first;
	int last;

	y = 0;
	first = 0;
	while (config->map[y])
	{
		while (config->map[y][first] == ' ')
			first++;
		last = ft_strlen(config->map[y]) - 1;
		while (last > 0 && config->map[y][last] == ' ')
			last--;
		if (config->map[y][first] != '1' || config->map[y][last] != '1')
			return (1);
		y++;
	}
	return (1);
}

int ft_check_middle(t_config *config) 
{
	int y;
	int x;

	y = 0;
	while (config->map[y])
	{
		x = 0;
		while (config->map[y][x])
		{
			if ((config->map[y][x] == '0' && config->map[y + 1][x] == ' ')
				|| (config->map[y][x] == '0' && config->map[y - 1][x] == ' '))
				return (0);
			else if (config->map[y][x] == '0' && config->map[y][x + 1] == ' ' 
				&& config->map[y][x + 2] == ' ')
				return (0);
			else if (config->map[y][x] == '0' && config->map[y][x - 1] == ' ' 
				&& config->map[y][x - 2] == ' ')
				return (0);
			x++;
		}
		y++;
	}
	return(1);
}

int	ft_check_map(t_config *config)
{
	int y;
	int x;

	y = 0;
	if (!ft_check_top_bot(config) || !ft_check_sides(config)
		|| !ft_check_middle(config))
		return (ft_errors("Map is not closed.\n"));
	while (config->map[y])
	{
		x = 0;
		while (config->map[y][x])
		{
			if (!ft_strchr(" 012NSEW", config->map[y][x]))
				return (ft_errors("Invalid character in map.\n"));
			if (ft_strchr("NSEW", config->map[y][x]))
				ft_get_player_pos(config, y, x);
			x++;
		}
		y++;
	}
	return (1);
}