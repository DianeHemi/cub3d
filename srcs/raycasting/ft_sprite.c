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

void	ft_sprite_width(t_config *config, t_sprite *spr, t_game *game)
{
	if (game->tex[4].width == game->tex[4].height)
		spr->width = (int)(((config->width / 2) / tan(32 * (M_PI / 180)))
			/ (spr->transform.y));
	else if (game->tex[4].width <= game->tex[4].height)
		spr->width = (int)(((config->width / 2) * spr->ratio)
			/ (spr->transform.y));
	else
		spr->width = (int)(((config->width / 2) / spr->ratio)
			/ (spr->transform.y));
}

void	ft_draw_sprite(t_config *config, t_sprite *spr,
						t_s_pos s_pos, t_game *game)
{
	spr->x = s_pos.x - game->ray->pos.x;
	spr->y = s_pos.y - game->ray->pos.y;
	spr->transform.x = spr->inv_det *
		(game->ray->dir.y * spr->x - game->ray->dir.x * spr->y);
	spr->transform.y = spr->inv_det *
		(-game->ray->plane_y * spr->x + game->ray->plane_x * spr->y);
	spr->screen_x = (int)((config->width / 2) *
		(1 + spr->transform.x / spr->transform.y));
	spr->height = (int)(((config->width / 2) / tan(32 * (M_PI / 180)))
		/ (spr->transform.y));
	spr->draw_start_y = -spr->height / 2 + config->height / 2;
	spr->draw_start_y = spr->draw_start_y < 0 ? 0 : spr->draw_start_y;
	spr->draw_end_y = spr->height / 2 + config->height / 2;
	if (spr->draw_end_y >= config->height)
		spr->draw_end_y = config->height;
	ft_sprite_width(config, spr, game);
	spr->draw_start_x = -spr->width / 2 + spr->screen_x;
	spr->draw_start_x = spr->draw_start_x < 0 ? 0 : spr->draw_start_x;
	spr->draw_end_x = spr->width / 2 + spr->screen_x;
	if (spr->draw_end_x >= config->width)
		spr->draw_end_x = config->width;
}

void	ft_sprite_tex(t_sprite *spr, t_game *game, t_texture *tex)
{
	int stripe;
	int y;

	stripe = spr->draw_start_x;
	while (stripe < game->config->width && stripe < spr->draw_end_x)
	{
		spr->tex_x = (int)((256 * (stripe - (-spr->width / 2 + spr->screen_x))
			* tex->width / spr->width) / 256);
		y = spr->draw_start_y;
		while (y < spr->draw_end_y && spr->transform.y > 0.
			&& spr->transform.y < game->ray->zbuffer[stripe])
		{
			spr->d = y * 256 - game->config->height * 128 + spr->height * 128;
			spr->tex_y = ((spr->d * tex->height) / spr->height) / 256;
			spr->color = *(unsigned int *)(tex->img + (spr->tex_y
				* tex->size_line + spr->tex_x * (tex->bpp / 8)));
			if (spr->color != 0)
				my_mlx_pixel_put(game->mlx, y, stripe, spr->color);
			y++;
		}
		stripe++;
	}
}

void	ft_sprite_management(t_game *game, t_sprite *spr, t_config *config)
{
	int	i;

	ft_sort_sprites(game, config->nb_sprite);
	spr->ratio = (double)game->tex[4].height / (double)game->tex[4].width;
	spr->inv_det = 1.0 / (game->ray->plane_x * game->ray->dir.y
		- game->ray->dir.x * game->ray->plane_y);
	i = 0;
	while (i < config->nb_sprite)
	{
		if (spr->s_pos[i].dist > .2)
		{
			ft_draw_sprite(config, spr, spr->s_pos[i], game);
			ft_sprite_tex(spr, game, &game->tex[4]);
		}
		i++;
	}
}
