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
#include <stdio.h>///



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





int 	ft_main_loop(t_game *game)
{

	ft_raycasting(game);

	//Sprite management ?

	//free zbuffer

	//Gestion des déplacements
	ft_move_player(game->move, game->ray, game->config);



	//Envoyer image vers fenetre
	mlx_put_image_to_window(game->mlx->ptr, game->mlx->win, game->mlx->img, 0, 0);

	//save

	return (1);
}




/*
printf("----\n");
printf("mapX : %d, mapY : %d\npos_x : %f, pos_y : %f\nstepX : %d, stepY: %d\n", game->ray->mapX, game->ray->mapY, game->ray->pos_x, game->ray->pos_y, game->ray->stepX, game->ray->stepY);
printf("RayDir_x : %f, RayDir_y : %f\nsideDist_x : %f, sideDist_y : %f\ndeltaDist_x : %f, deltaDist_y: %f\n", game->ray->rayDir_x, game->ray->rayDir_y, game->ray->sideDist_x, game->ray->sideDist_y, game->ray->deltaDist_x, game->ray->deltaDist_y);
printf("hit : %d, cameraX : %f\n", game->ray->hit, game->ray->cam_x);
printf("D-start : %d, D-end : %d\nlineHeight : %d, perpWallDist : %f \n", game->draw->drawStart, game->draw->drawEnd, game->draw->lineHeight, game->ray->perpWallDist);//
printf("Wall dir: %d\n", game->ray->wallDir);
printf("----\n\n");*/
