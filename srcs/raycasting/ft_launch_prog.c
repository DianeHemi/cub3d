/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_prog.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:49:35 by dchampda          #+#    #+#             */
/*   Updated: 2020/07/13 12:49:40 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdio.h> //

int 	ft_exit(t_game *game)
{
	//Free everything
	ft_free_tab(game->config->map);
	mlx_clear_window(game->mlx->ptr, game->mlx->win);
	mlx_destroy_window(game->mlx->ptr, game->mlx->win);
	exit(EXIT_SUCCESS);
	return (1);
}

int ft_init_image(t_config *data, t_mlx *mlx)
{
	if (!(mlx->img = mlx_new_image(mlx->ptr, data->width, data->height)))
		return (0);
	mlx->img_ptr = mlx_get_data_addr(mlx->img, &mlx->bpp, 
		&mlx->size_line, &mlx->endian);
	if (mlx->img_ptr == NULL)
		return (0);
	mlx->bpp = mlx->bpp / 8;
	return (1);
}

int ft_launch_prog(t_config *data, t_mlx *mlx, int save_opt)
{
	t_game		game;
	t_ray 		ray;
	t_texture	tex[4];
	t_sprite	*sprite;
	t_move		move;

	if (!(sprite = malloc(sizeof(*sprite) * data->nb_sprite)))
		return (ft_errors("Memory allocation failed.\n"));
	ft_get_pos_sprite(sprite, data, &game);



	if ((mlx->ptr = mlx_init()) == NULL)
		return (ft_errors("Initialisation failed.\n"));
	if (!(mlx->win = mlx_new_window(mlx->ptr, data->width, data->height, "Cub3D")))
		return (ft_errors("Window couldn't be initialised.\n"));
	if (!(ft_init_image(data, mlx)))
		return (ft_errors("Image initialisation failed.\n"));  //Init image
	if (!(ft_init_textures(data, &game, tex, mlx)))
		return (ft_errors("Error : Texture file is corrupt.\n"));


	//Storage
	if (!ft_init_store(data, &ray, mlx, &game))
		return (0);
	ft_init_move(&move, &game);

	//Initialisation position joueur
	//A deplacer dans le stockage après ?
	ft_init_player_pos(game.config, game.ray);


	//Fonction qui sauvegarde en bmp !
	//ft_save(&game, save_opt);
(void)save_opt;


	//Fonction qui gère l'appui sur une touche
	mlx_hook(mlx->win, 2, 1L, ft_keypress, &game);
	//Fonction qui gère le relachement d'une touche
	mlx_hook(mlx->win, 3, 2L, ft_keyrelease, &game);
	//Fonction pour quitter proprement
	mlx_hook(mlx->win, 33, 0, ft_exit, &game);
	mlx_loop_hook(mlx->ptr, ft_main_loop, &game);
	mlx_loop(mlx->ptr);
	


	return (1);
}