/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 18:25:35 by diane             #+#    #+#             */
/*   Updated: 2020/09/09 16:43:13 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void 	ft_draw_sprite(t_config *config, t_sprite_data *s_data, t_sprite sprite, t_game *game)
{
	s_data->ratio = (double)game->tex[4].height / (double)game->tex[4].width;
	s_data->x = sprite.x - game->ray->pos_x;
	s_data->y = sprite.y - game->ray->pos_y;
	s_data->invDet = 1.0 / (game->ray->plane_x * game->ray->dir_y - game->ray->dir_x * game->ray->plane_y);
	s_data->transformX = s_data->invDet * (game->ray->dir_y * s_data->x - game->ray->dir_x * s_data->y);
	s_data->transformY = s_data->invDet * (-game->ray->plane_y * s_data->x + game->ray->plane_x * s_data->y);
	s_data->screen_x = (int)((config->width / 2) * (1 + s_data->transformX / s_data->transformY));
	s_data->s_height = (int)(((config->width / 2) / tan(32 * (M_PI/180))) / (s_data->transformY));
	s_data->drawStart_y = -s_data->s_height / 2 + config->height / 2;
	s_data->drawStart_y = s_data->drawStart_y < 0 ? 0 : s_data->drawStart_y;
	s_data->drawEnd_y = s_data->s_height / 2 + config->height / 2;
	if (s_data->drawEnd_y >= config->height)
		s_data->drawEnd_y = config->height;
	if (game->tex[4].width == game->tex[4].height)
		s_data->s_width = (int)(((config->width / 2) / tan(32 * (M_PI/180))) / (s_data->transformY));
	else if (game->tex[4].width <= game->tex[4].height)
		s_data->s_width = (int)(((config->width / 2) * s_data->ratio) / (s_data->transformY));
	else
		s_data->s_width = (int)(((config->width / 2) / s_data->ratio) / (s_data->transformY));
	s_data->drawStart_x = -s_data->s_width / 2 + s_data->screen_x;
	s_data->drawStart_x = s_data->drawStart_x < 0 ? 0 : s_data->drawStart_x;
	s_data->drawEnd_x = s_data->s_width / 2 + s_data->screen_x;
	if (s_data->drawEnd_x >= config->width)
		s_data->drawEnd_x = config->width;
}

void 	ft_sprite_tex(t_sprite_data *s_data, t_game *game)
{
	int stripe;
	int y;

	stripe = s_data->drawStart_x;
	while (stripe < game->config->width && stripe < s_data->drawEnd_x)
	{
		s_data->tex_x = (int)((256 * (stripe - (-s_data->s_width / 2 + s_data->screen_x)) * game->tex[4].width / s_data->s_width) / 256);
		y = s_data->drawStart_y;
		while (y < s_data->drawEnd_y && s_data->transformY > 0. && s_data->transformY < game->ray->zbuffer[stripe])
		{

			s_data->d = y * 256 - game->config->height * 128 + s_data->s_height * 128;
			s_data->tex_y = ((s_data->d * game->tex[4].height) / s_data->s_height) / 256;
			s_data->color = *(unsigned int *)(game->tex[4].img + (s_data->tex_y * game->tex[4].size_line + s_data->tex_x * (game->tex[4].bpp / 8)));			
			if (s_data->color != 0)
				my_mlx_pixel_put(game->mlx, y, stripe, s_data->color);
			y++;
		}
		stripe++;
	}
}

void	ft_sprite_management(t_game *game, t_config *config)
{
	int 			i;

	ft_sort_sprites(game, config->nb_sprite);
	i = 0;
	while (i < config->nb_sprite)
	{
		if (game->sprite->pos[i].dist > .1)
		{
			ft_draw_sprite(config, game->sprite, game->sprite->pos[i], game);
			ft_sprite_tex(game->sprite, game);
		}
		i++;
	}
}