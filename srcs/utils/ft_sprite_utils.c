/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:45:15 by dchampda          #+#    #+#             */
/*   Updated: 2020/09/08 17:45:19 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void 	ft_swap_sprites(t_s_pos *sprite1, t_s_pos *sprite2)
{
	t_s_pos tmp;

	tmp = *sprite1;
	*sprite1 = *sprite2;
	*sprite2 = tmp;
}

double		ft_sprite_dist(t_ray *ray, t_s_pos *sprite)
{

	sprite->dist = ((ray->pos.x - sprite->x) * (ray->pos.x - sprite->x) 
			+ (ray->pos.y - sprite->y) * (ray->pos.y - sprite->y));
	return (sprite->dist);
}

void		ft_sort_sprites(t_game *game, int nb_sprite)
{
	int i;
	int j;

	i = 1;
	while (i < nb_sprite)
	{
		j = i;
		while (j > 0 && ft_sprite_dist(game->ray, &game->sprite->s_pos[j - 1]) 
				< ft_sprite_dist(game->ray, &game->sprite->s_pos[j]))
		{
			ft_swap_sprites(&game->sprite->s_pos[j], &game->sprite->s_pos[j - 1]);
			j--;
		}
		i++;
	}
}

