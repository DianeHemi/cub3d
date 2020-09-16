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
	config->north_tex = NULL;
	config->south_tex = NULL;
	config->west_tex = NULL;
	config->east_tex = NULL;
	config->sprite_tex = NULL;
	config->f_color = -2;
	config->c_color = -2;
	config->player_x = 0;
	config->player_y = 0;
	config->player_start = '0';
	config->nb_sprite = 0;
}

void	ft_init_move(t_move *move, t_game *game)
{
	move->forwd = 0;
	move->backwd = 0;
	move->left = 0;
	move->right = 0;
	move->turn_l = 0;
	move->turn_r = 0;
	move->mv_spd = 0.04;
	move->rot_spd = 0.05;
	game->move = move;
}

void	ft_set_dir(t_ray *ray, double x, double y)
{
	ray->dir.x = x;
	ray->dir.y = y;
}

void	ft_init_player_pos(t_config *config, t_ray *ray)
{
	ray->pos.x = config->player_x + .5;
	ray->pos.y = config->player_y + .5;
	ray->plane_x = 0.66;
	ray->plane_y = 0.;
	if (config->player_start == 'N')
		ft_set_dir(ray, 0., -1.);
	else if (config->player_start == 'S')
	{
		ft_set_dir(ray, 0., 1.);
		ray->plane_x = -0.66;
	}
	else if (config->player_start == 'E')
	{
		ft_set_dir(ray, 1., 0.);
		ray->plane_x = 0.;
		ray->plane_y = 0.66;
	}
	else if (config->player_start == 'W')
	{
		ft_set_dir(ray, -1., 0.);
		ray->plane_x = 0.;
		ray->plane_y = -0.66;
	}
}
