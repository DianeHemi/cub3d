/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:13:53 by dchampda          #+#    #+#             */
/*   Updated: 2020/08/27 15:13:56 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

int	ft_check_config(t_config *config)
{
	if (config->width <= 0 || config->height <= 0)
		return (ft_errors("Resolution incorrect.\n"));
	if (config->width > 1920)
		config->width = 1920;
	if (config->height > 1080)
		config->height = 1080;
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
	if (config->player_start == '0')	
		return (ft_errors("Player is missing.\n"));
	return (1);
}
