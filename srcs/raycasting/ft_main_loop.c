/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 16:33:16 by diane             #+#    #+#             */
/*   Updated: 2020/07/17 16:33:21 by diane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdio.h>///







int		ft_wall_direction(t_ray *ray)
{
	if (ray->side == 1)
	{
		if (ray->rayDir_y < 0)
			return (0); //North
		else
			return (1); //South
	}
	else
	{
		if (ray->rayDir_x < 0)
			return (3); //West
		else
			return (2); //East
	}
}


void	ft_get_tex_coords(t_ray *ray, t_game *game)
{
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





void	ft_init_drawing(t_ray *ray, t_config *config, t_draw *draw, int t_height)
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
/* --- Affichage des couleurs --- */


void	ft_get_color(t_draw *draw, t_texture *tex)
{
	tex->tex_y = (int)draw->tex_pos & (tex->height - 1);
	draw->tex_pos += draw->step;

	draw->color = *(unsigned int *)(tex->img + (tex->tex_y * tex->size_line + tex->tex_x * (tex->bpp / 8)));
}


void	ft_draw_colors(t_game *game, t_draw *draw)
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




/*--------------------------------------------*/
/*--------------------------------------------*/
/*--------------------------------------------*/




int 	ft_main_loop(t_game *game)
{
	t_draw draw;

	game->ray->pos_x = (double)game->config->player_x;
	game->ray->pos_y = (double)game->config->player_y;


	if(!(game->ray->zbuffer = malloc(sizeof(double) * game->config->width)))
		return (ft_errors("Memory allocation failed.\n"));

	draw.x = 0;
	while (draw.x < game->config->width)
	{
		game->ray->hit = 0;

		//Ray position and direction
		ft_init_raycast(game->ray, game->config, draw.x);
		//Calcule stepX et stepY
		ft_calcul_step(game->ray);
		//perform DDA
		ft_dda_algo(game->ray, game->config);
		//Get perpWallDist
		ft_get_wall_dist(game->ray, draw.x);
		//Get wall that was hit
		game->ray->wallDir = ft_wall_direction(game->ray);

		//Coordonnee de la texture
		ft_get_tex_coords(game->ray, game);
		//Get line_height et draw start/end
		ft_init_drawing(game->ray, game->config, &draw, game->tex[game->ray->wallDir].height);



		//Affichage couleurs
		ft_draw_colors(game, &draw);

		draw.x++;


/*
printf("----\n");
printf("mapX : %d, mapY : %d\npos_x : %f, pos_y : %f\nstepX : %d, stepY: %d\n", game->ray->mapX, game->ray->mapY, game->ray->pos_x, game->ray->pos_y, game->ray->stepX, game->ray->stepY);
printf("rayDir_x : %f, rayDir_y : %f\nsideDist_x : %f, sideDist_y : %f\ndeltaDist_x : %f, deltaDist_y: %f\n", game->ray->rayDir_x, game->ray->rayDir_y, game->ray->sideDist_x, game->ray->sideDist_y, game->ray->deltaDist_x, game->ray->deltaDist_y);
printf("hit : %d, cameraX : %f\n", game->ray->hit, game->ray->cam_x);
printf("D-start : %d, D-end : %d\nlineHeight : %d, perpWallDist : %f \n", game->draw->drawStart, game->draw->drawEnd, game->draw->lineHeight, game->ray->perpWallDist);//
printf("Wall dir: %d\n", game->ray->wallDir);
printf("----\n\n");*/
	
	}


	//Envoyer image vers fenetre
	mlx_put_image_to_window(game->mlx->ptr, game->mlx->win, game->mlx->img, 0, 0);



	


	return (1);
}
