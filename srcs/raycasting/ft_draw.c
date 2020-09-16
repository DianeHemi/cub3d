/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:40:52 by dchampda          #+#    #+#             */
/*   Updated: 2020/09/16 15:40:56 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_get_color(t_draw *draw, t_texture *tex)
{
	tex->tex_y = (int)draw->tex_pos & (tex->height - 1);
	draw->tex_pos += draw->step;
	draw->color = *(unsigned int *)(tex->img + (tex->tex_y * tex->size_line
			+ tex->tex_x * (tex->bpp / 8)));
}

void		ft_draw_colors(t_game *game, t_draw *draw)
{
	draw->y = 0;
	while (draw->y < draw->draw_start)
	{
		draw->color = game->config->c_color;
		my_mlx_pixel_put(game->mlx, draw->y, draw->x, draw->color);
		draw->y++;
	}
	while (draw->y < draw->draw_end)
	{
		ft_get_color(draw, &(game->tex[draw->side]));
		my_mlx_pixel_put(game->mlx, draw->y, draw->x, draw->color);
		draw->y++;
	}
	while (draw->y < game->config->height)
	{
		draw->color = game->config->f_color;
		my_mlx_pixel_put(game->mlx, draw->y, draw->x, draw->color);
		draw->y++;
	}
}

void		ft_get_tex_coords(t_ray *ray, t_game *game)
{
	if (ray->side == 1)
		ray->wall_dir = ray->ray_dir.y < 0 ? 1 : 0;
	else
		ray->wall_dir = ray->ray_dir.x < 0 ? 2 : 3;
	if (ray->side == 0)
		ray->wall_x = ray->pos.y + ray->wall_dist * ray->ray_dir.y;
	else
		ray->wall_x = ray->pos.x + ray->wall_dist * ray->ray_dir.x;
	ray->wall_x -= floor(ray->wall_x);
	game->tex[ray->wall_dir].tex_x = (int)(ray->wall_x
			* (double)game->tex[ray->wall_dir].width);
	if (ray->side == 0 && ray->ray_dir.x > 0)
		game->tex[ray->wall_dir].tex_x = game->tex[ray->wall_dir].width
			- game->tex[ray->wall_dir].tex_x - 1;
	if (ray->side == 1 && ray->ray_dir.y < 0)
		game->tex[ray->wall_dir].tex_x = game->tex[ray->wall_dir].width
			- game->tex[ray->wall_dir].tex_x - 1;
}

void		ft_init_drawing(t_ray *ray, t_config *config,
			t_draw *draw, int tex_height)
{
	draw->line_height = (int)((config->width / 2)
			/ tan(32 * (M_PI / 180)) / ray->wall_dist);
	draw->draw_start = -(draw->line_height) / 2 + config->height / 2;
	draw->draw_end = (draw->line_height) / 2 + config->height / 2;
	draw->dist = ray->wall_dist;
	draw->side = ray->wall_dir;
	if (draw->draw_start < 0)
		draw->draw_start = 0;
	if (draw->draw_end >= config->height)
		draw->draw_end = config->height - 1;
	draw->step = 1.0 * tex_height / draw->line_height;
	draw->tex_pos = (draw->draw_start - config->height / 2
			+ draw->line_height / 2) * draw->step;
}
