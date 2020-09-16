/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:14:01 by diane             #+#    #+#             */
/*   Updated: 2020/07/28 17:56:21 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_raycast(t_ray *ray, t_config *config, int x)
{
	ray->cam_x = 2 * x / (double)config->width - 1.0;
	ray->ray_dir.x = ray->dir.x + ray->plane_x * ray->cam_x;
	ray->ray_dir.y = ray->dir.y + ray->plane_y * ray->cam_x;
	ray->map_x = (int)ray->pos.x;
	ray->map_y = (int)ray->pos.y;
	ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	ray->hit = 0;
}

void	ft_calcul_step(t_ray *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist.x = (ray->pos.x - ray->map_x) * ray->delta_dist.x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist.x = (ray->map_x + 1.0 - ray->pos.x) * ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist.y = (ray->pos.y - ray->map_y) * ray->delta_dist.y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist.y = (ray->map_y + 1.0 - ray->pos.y) * ray->delta_dist.y;
	}
}

void	ft_dda_algo(t_ray *ray, t_config *config)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (config->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	ft_get_wall_dist(t_ray *ray, int x)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->map_x - ray->pos.x
			+ (1.0 - ray->step_x) / 2.0) / ray->ray_dir.x;
	else
		ray->wall_dist = (ray->map_y - ray->pos.y
			+ (1.0 - ray->step_y) / 2.0) / ray->ray_dir.y;
	if (ray->wall_dist == 0)
		ray->wall_dist = 0.01;
	ray->zbuffer[x] = ray->wall_dist;
}

void	ft_raycasting(t_game *game)
{
	t_draw draw;

	draw.x = 0;
	while (draw.x < game->config->width)
	{
		ft_init_raycast(game->ray, game->config, draw.x);
		ft_calcul_step(game->ray);
		ft_dda_algo(game->ray, game->config);
		ft_get_wall_dist(game->ray, draw.x);
		ft_get_tex_coords(game->ray, game);
		ft_init_drawing(game->ray, game->config, &draw,
			game->tex[game->ray->wall_dir].height);
		ft_draw_colors(game, &draw);
		draw.x++;
	}
}
