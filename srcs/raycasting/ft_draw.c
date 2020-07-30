/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:33:58 by diane             #+#    #+#             */
/*   Updated: 2020/07/28 11:34:00 by diane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_get_color(t_draw *draw, t_texture *tex)
{
	tex->tex_y = (int)draw->tex_pos & (tex->height - 1);
	draw->tex_pos += draw->step;

	draw->color = *(unsigned int *)(tex->img + (tex->tex_y * tex->size_line + tex->tex_x * (tex->bpp / 8)));
}

void		ft_draw_colors(t_game *game, t_draw *draw)
{
	while (draw->y < game->config->height)
	{
		if (draw->drawStart <= draw->y && draw->y <= draw->drawEnd)
			ft_get_color(draw, &(game->tex[draw->side]));
		if (draw->y > draw->drawEnd)
			draw->color = game->config->f_color;
		my_mlx_pixel_put(game->mlx, draw->y, draw->x, draw->color);
		draw->y++;
	}
}

static int	ft_wall_direction(t_ray *ray)
{
	if (ray->side == 1)
	{
		if (ray->rayDir_y < 0)
			return (1);
		else
			return (0);
	}
	else
	{
		if (ray->rayDir_x < 0)
			return (2);
		else
			return (3);
	}
}

void		ft_get_tex_coords(t_ray *ray, t_game *game)
{
	//Get wall that was hit
	ray->wallDir = ft_wall_direction(ray);
	//Calculate where the wall was hit
	if (ray->side == 0)
		ray->wallX = ray->pos_y + ray->perpWallDist * ray->rayDir_y;
	else
		ray->wallX = ray->pos_x + ray->perpWallDist * ray->rayDir_x;
	
	ray->wallX -= floor(ray->wallX);

	//tex_x = x coordinate on the texture
	game->tex[ray->wallDir].tex_x = (int)(ray->wallX * (double)game->tex[ray->wallDir].width);
	if (ray->side == 0 && ray->rayDir_x > 0)
		game->tex[ray->wallDir].tex_x = game->tex[ray->wallDir].width - game->tex[ray->wallDir].tex_x - 1;
	if (ray->side == 1 && ray->rayDir_y < 0)
		game->tex[ray->wallDir].tex_x = game->tex[ray->wallDir].width - game->tex[ray->wallDir].tex_x - 1;
}

void		ft_init_drawing(t_ray *ray, t_config *config, t_draw *draw, int t_height)
{
	//Calculate height of line to draw on screen
	draw->lineHeight = (int)(config->height / ray->perpWallDist);
	//calculate lowest and highest pixel to fill in current stripe
	draw->drawStart = -(draw->lineHeight) / 2 + config->height / 2;
	draw->drawEnd = (draw->lineHeight) / 2 + config->height / 2;

	draw->color = config->c_color;
	draw->y = 0;
	draw->dist = ray->perpWallDist;
	draw->side = ray->wallDir;

	if (draw->drawStart < 0)
		draw->drawStart = 0;
	if (draw->drawEnd >= config->height)
		draw->drawEnd = config->height - 1;

	draw->step = 1.0 * t_height / draw->lineHeight;
	draw->tex_pos = (draw->drawStart - config->height / 2 + draw->lineHeight / 2) * draw->step;
}