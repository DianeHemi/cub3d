/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 14:05:03 by dchampda          #+#    #+#             */
/*   Updated: 2020/07/07 13:01:18 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_config(t_config *config)
{
	config->width = 0;
	config->height = 0;
	config->map = malloc(sizeof(char *));
	config->north_tex[0] = '\0';
	config->south_tex[0] = '\0';
	config->west_tex[0] = '\0';
	config->east_tex[0] = '\0';
	config->sprite_tex[0] = '\0';
	config->f_color = 0;
	config->c_color = 0;
	config->player_x = 0;
	config->player_y = 0;
	config->player_start = '0';
}
