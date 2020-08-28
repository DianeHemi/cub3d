/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 16:33:16 by diane             #+#    #+#             */
/*   Updated: 2020/07/28 17:56:37 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"



/*--------------------------------------------*/
/*--------------------------------------------*/
/*--------------------------------------------*/
/* --- Pixel put --- */

void	my_mlx_pixel_put(t_mlx *mlx, int y, int x, int color)
{
	char	*dst;

	dst = mlx->img_ptr + (y * mlx->size_line + x * mlx->bpp);
	*(unsigned int *)dst = color;
}


/*--------------------------------------------*/
/*--------------------------------------------*/
/*--------------------------------------------*/


int 	ft_main_loop(t_game *game)
{
	ft_raycasting(game);

	//Sprite management
	ft_sprite_management(game, game->config);

	//Gestion des déplacements
	ft_move_player(game->move, game->ray, game->config);

	//Envoyer image vers fenetre
	mlx_put_image_to_window(game->mlx->ptr, game->mlx->win, game->mlx->img, 0, 0);
	mlx_do_sync(game->mlx->ptr);
	//save

	return (1);
}
