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
	//calculate ray position and direction
	ray->cam_x = 2 * x / (double)config->width - 1.0;
	ray->rayDir_x = ray->dir_x + ray->plane_x * ray->cam_x;
	ray->rayDir_y = ray->dir_y + ray->plane_y * ray->cam_x;
	//Case dans laquelle on se trouve
	ray->mapX = (int)ray->pos_x;
	ray->mapY = (int)ray->pos_y;
	//longueur ray depuis x/y-size au suivant
	ray->deltaDist_x = fabs(1 / ray->rayDir_x);
	ray->deltaDist_y = fabs(1 / ray->rayDir_y);
	ray->hit = 0;
}

void	ft_calcul_step(t_ray *ray)
{
	if (ray->rayDir_x < 0)
	{
		ray->stepX = -1;
		ray->sideDist_x = (ray->pos_x - ray->mapX) * ray->deltaDist_x;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDist_x = (ray->mapX + 1.0 - ray->pos_x) * ray->deltaDist_x;
	}
	if (ray->rayDir_y < 0)
	{
		ray->stepY = -1;
		ray->sideDist_y = (ray->pos_y - ray->mapY) * ray->deltaDist_y;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDist_y = (ray->mapY + 1.0 - ray->pos_y) * ray->deltaDist_y;
	}
}

void	ft_dda_algo(t_ray *ray, t_config *config)
{
	while (ray->hit == 0)
	{
		//jump to next map square, or in x-direction or in y-direct
		if (ray->sideDist_x < ray->sideDist_y)
		{
			ray->sideDist_x += ray->deltaDist_x;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDist_y += ray->deltaDist_y;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		//Check if ray has hit a wall
		if (config->map[ray->mapY][ray->mapX] == '1')
			ray->hit = 1;
	}
}

void	ft_get_wall_dist(t_ray *ray, int x)
{
	//Calculate distance projected on camera direction
	if (ray->side == 0)
		ray->perpWallDist = (ray->mapX - ray->pos_x + (1.0 - ray->stepX) / 2.0) / ray->rayDir_x;
	else
		ray->perpWallDist = (ray->mapY - ray->pos_y + (1.0 - ray->stepY) / 2.0) / ray->rayDir_y;
	if (ray->perpWallDist == 0)
		ray->perpWallDist = 0.01;
	ray->zbuffer[x] = ray->perpWallDist;
}


void	ft_raycasting(t_game *game)
{
	t_draw draw;

	draw.x = 0;
	
	while (draw.x < game->config->width)
	{
		//Ray position and direction
		ft_init_raycast(game->ray, game->config, draw.x);
		//Calcule stepX et stepY
		ft_calcul_step(game->ray);
		//perform DDA
		ft_dda_algo(game->ray, game->config);
		//Get perpWallDist
		ft_get_wall_dist(game->ray, draw.x);

		//Coordonnee de la texture
		ft_get_tex_coords(game->ray, game);
		//Get line_height et draw start/end
		ft_init_drawing(game->ray, game->config, &draw, game->tex[game->ray->wallDir].height);
		
		//Affichage couleurs
		ft_draw_colors(game, &draw);

		draw.x++;	
	}
}