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

int ft_launch_prog(t_config *data, t_mlx *mlx)
{
	t_ray 		ray;
	t_texture	tex[4];
	t_sprite	*sprite;
	t_game		game;


	if (!(sprite = malloc(sizeof(*sprite) * data->nb_sprite)))
		return (ft_errors("Memory allocation failed.\n"));
	ft_get_pos_sprite(sprite, data, &game);



//Recuperer position de depart de la camera
//Fonction qui sauvegarde en bmp !



	//ft_init_struct_player



	//Recuperer position de depart du joueur
	ft_init_player_pos(data, &ray); 

	//Initialisation de la fenetre, a mettre dans fct a part ?
	if ((mlx->ptr = mlx_init()) == NULL)
		return (ft_errors("Initialisation failed.\n"));
	if (!(mlx->win = mlx_new_window(mlx->ptr, data->width, data->height, "Cub3D")))
		return (ft_errors("Window couldn't be initialised.\n"));
	if (!(ft_init_image(data, mlx)))
		return (ft_errors("Image initialisation failed.\n"));  //Init image

	//Initialisation des textures. Tj apres init. fenetre
	if (!(ft_init_textures(data, &game, tex, mlx)))
		return (ft_errors("Error : Texture file is corrupt.\n"));

	


	/*
	*** Ici gestion des hooks, puis du loop des hook et le loop general vient en dernier.
	*** Fonction qui gère l'appui sur une touche ---- mlx_hook-keypress
	*** Fonction qui gère le relachement d'une touche ---- mlx_hook-keyrelease
	*** Fonction qui gère sortie propre du programme ---- mlx_hook-exit
	*** Loop de la fonction hook
	*/



	
	ft_init_store(data, &ray, mlx, &game); //On met toutes les structs dans game

	//mlx_hook 1
	//mlx_hook 2
	
	//Fonction pour quitter proprement
	mlx_hook(mlx->win, 33, 0, ft_exit, &game);

//ft_main_loop(&game);
	mlx_loop_hook(mlx->ptr, ft_main_loop, &game);
	mlx_loop(mlx->ptr);
	
	//free(sprite); ?

	return (1);
}



//game->config.map[(floor(game->camera.pos.y) * game->config.map.columns) + floor(game->camera.pos.x)] = 'A'