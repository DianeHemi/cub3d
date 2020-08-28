/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 18:25:35 by diane             #+#    #+#             */
/*   Updated: 2020/08/01 18:25:38 by diane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdio.h>///






/*--------------------------------------------*/
/*--------------------------------------------*/
/*--------------------------------------------*/

void 	ft_init_sprite_tex(t_sprite_data *s_data, t_texture *tex, t_config *config)
{
	s_data->factor_128 = (-config->height + s_data->s_height * 128);
	s_data->calc1 = ((double)tex->width / (double)s_data->s_width);
	s_data->calc2 = -s_data->calc1 * (-s_data->half_sprite_w + s_data->screen_x);
}



void 	ft_init_sprite_draw(t_config *config, t_sprite_data *s_data, t_sprite *sprite, t_game *game)
{
	s_data->transformX = s_data->invDet * (game->ray->dir_y * sprite->x - game->ray->dir_x * sprite->y);
	s_data->transformY = s_data->invDet * (-game->ray->plane_y * sprite->x + game->ray->plane_x * sprite->y);
	s_data->screen_x = (int)(s_data->half_win_w) * (1 + s_data->transformX / s_data->transformY);
	//Calculate height of sprite on screen
	s_data->s_height = fabs((int)config->height / (s_data->transformY));
	s_data->half_sprite_h = s_data->s_height / 2;

	//get stripe size
	s_data->drawStart_y = -s_data->half_sprite_h + s_data->half_win_h;
	if (s_data->drawStart_y < 0)
		s_data->drawStart_y = 0;
	s_data->drawEnd_y = s_data->half_sprite_h + s_data->half_win_h;
	if (s_data->drawEnd_y >= config->height)
		s_data->drawEnd_y = config->height - 1;
	//Calcul de la width du sprite
	s_data->s_width = fabs((config->height / s_data->transformY));
	s_data->half_sprite_w = s_data->s_width / 2;
	s_data->drawStart_x = -s_data->half_sprite_w + s_data->screen_x + 1;
	if (s_data->drawStart_x < 0)
		s_data->drawStart_x = 0;
	s_data->drawEnd_x = s_data->half_sprite_w + s_data->screen_x;
	if (s_data->drawEnd_x >= config->width)
		s_data->drawEnd_x = config->width - 1;
}


/*--------------------------------------------*/
/*--------------------------------------------*/
/*--------------------------------------------*/

void 	ft_swap_sprites(t_sprite *sprite1, t_sprite *sprite2)
{
	t_sprite tmp;

	tmp = *sprite1;
	*sprite1 = *sprite2;
	*sprite2 = tmp;
}

double		ft_sprite_dist(t_ray *ray, t_sprite *sprite)
{
	double sprite_dist;

	sprite_dist = ((ray->pos_x - sprite->x) * (ray->pos_x - sprite->x) 
			+ (ray->pos_y - sprite->y) * (ray->pos_y - sprite->y));
	return (sprite_dist);
}

void		ft_sort_sprites(t_game *game, int nb_sprite)
{
	int i;
	int j;

	i = 1;
	while (i < nb_sprite)
	{
		j = i;
		while (j > 0 && ft_sprite_dist(game->ray, &game->sprite[j - 1]) < ft_sprite_dist(game->ray, &game->sprite[j]))
		{
			ft_swap_sprites(&game->sprite[j], &game->sprite[j - 1]);
			j--;
		}
		i++;
	}
}
/*--------------------------------------------*/
/*--------------------------------------------*/
/*--------------------------------------------*/



void	*ft_memcpy(void *dst, const void *src, int n)
{
	int					i;
	unsigned char		*ptr_dst;
	unsigned char		*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (!ptr_dst && !ptr_src)
		return (ptr_dst);
	i = 0;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return (ptr_dst);
}

void 	ft_draw_sprite(t_sprite_data *s_data, int stripe, t_game *game)
{
	int 	invDet;
	int 	y;

	y = s_data->drawStart_y;
	while (y < s_data->drawEnd_y)
	{
		invDet = (int)((y) * 256 + s_data->factor_128);
		s_data->tex_y = ((invDet * game->tex[4].width) / (s_data->s_height) / 256);
		
		//
		if (game->tex[4].img[s_data->tex_y % 64 * game->tex[4].size_line + s_data->tex_x % 64 * game->tex[4].bpp / 8] != 0)
			ft_memcpy(game->mlx->img_ptr + 4 * game->config->width * y + stripe * 4, &game->tex[4].img[s_data->tex_y % 64 * game->tex[4].size_line + s_data->tex_x % 64 * game->tex[4].bpp / 8], sizeof(int));
		//

		//s_data->color = *(unsigned int *)(game->tex[4].img + (s_data->tex_y * (game->tex[4].size_line / 8) + s_data->tex_x * (game->tex[4].bpp / 8)));
		//if ((s_data->color & 0x00FFFFFF) != 0)
		//	my_mlx_pixel_put(game->mlx, y, stripe, s_data->color);
		y++;
	}
}



void 	ft_draw_stripes(t_sprite_data *s_data, double *zbuffer, t_game *game)
{
	int stripe;

	stripe = s_data->drawStart_x;
	while (stripe < s_data->drawEnd_x)
	{
		s_data->tex_x = (int)(stripe * s_data->calc1 + s_data->calc2);
		if (s_data->transformY > 0 && stripe > 0 && stripe < game->config->width && s_data->transformY < zbuffer[stripe])
			ft_draw_sprite(s_data, stripe, game);
		stripe++;
	}	
}


void 	ft_draw_sprite(t_config *config, t_sprite_data *s_data, t_sprite *sprite, t_game *game)
{

	s_data->x = sprite->x - game->ray->pos_x;
	s_data->y = sprite->y - game->ray->pos_y;
}


int		ft_sprite_management(t_game *game, t_config *config)
{
	int 			i;
	t_sprite_data 	s_data;


	//Tri dans l'ordre de distance
	ft_sort_sprites(game, config->nb_sprite);

	s_data.invDet = 1.0 / (game->ray->plane_x * game->ray->dir_y - game->ray->dir_x * game->ray->plane_y);
	s_data.half_win_h = config->height / 2;
	s_data.half_win_w = config->width / 2;

	i = 0;

	while (i < config->nb_sprite)
	{
		ft_draw_sprite(config, &s_data, &game->sprite[i], game);

		game->sprite[i].x -= game->ray->pos_x;
		game->sprite[i].y -= game->ray->pos_y;
		s_data.dist = sqrt(game->sprite[i].x * game->sprite[i].x + game->sprite[i].y * game->sprite[i].y);
		//Initialisation
		ft_init_sprite_draw(config, &s_data, &game->sprite[i], game);
		ft_init_sprite_tex(&s_data, &game->tex[4], game->config);

		//Lancement de l'écriture
		ft_draw_stripes(&s_data, game->ray->zbuffer, game);
		i++;
	}
	return (1);
}