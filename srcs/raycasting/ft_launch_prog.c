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

int ft_adjust_resolution(t_mlx *mlx, t_config *data)
{
	int width;
	int height;

	mlx_get_screen_size(mlx->ptr, &width, &height);
	if (width <= 0 || height <= 0)
		return (0);
	else
	{
		data->width = data->width > width ? width : data->width;
		data->height = data->height > height ? height : data->height;
		return (1);
	}
}

int ft_launch_mlx(t_mlx *mlx, t_config *data)
{
	if ((mlx->ptr = mlx_init()) == NULL)
		return (ft_errors("Initialisation failed.\n"));
	if (!ft_adjust_resolution(mlx, data))
		return (ft_errors("An error occured while resizing the window.\n"));
	if (!(mlx->win = mlx_new_window(mlx->ptr, data->width, data->height, "Cub3D")))
		return (ft_errors("Window couldn't be initialised.\n"));
	if (!(ft_init_image(data, mlx)))
		return (ft_errors("Image initialisation failed.\n"));
	return (1);
}

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

	return (1);
}

int ft_launch_prog(t_config *data, t_mlx *mlx, int save_opt)
{
	t_game		game;
	t_ray 		ray;
	t_texture	tex[5];
	t_sprite	*sprite;
	t_move		move;

	if (!(sprite = malloc(sizeof(*sprite) * data->nb_sprite)))
		return (ft_errors("Memory allocation failed.\n"));
	ft_get_pos_sprite(sprite, data, &game);

	if (!(ft_init_textures(data, &game, tex, mlx)))
		return (ft_errors("Error : Texture file can't be initialised.\n"));

	//Storage
	if (!ft_init_store(data, &ray, mlx, &game))
		return (0);
	ft_init_move(&move, &game);
	ft_init_player_pos(game.config, game.ray);

	//Fonction qui sauvegarde en bmp !
	if (save_opt == 1)
		ft_save(&game);

	//Fonction qui gère l'appui sur une touche
	mlx_hook(mlx->win, 2, 1L<<0, ft_keypress, &game);
	//Fonction qui gère le relachement d'une touche
	mlx_hook(mlx->win, 3, 1L<<1, ft_keyrelease, &game);
	//Fonction pour quitter proprement
	mlx_hook(mlx->win, EXIT_BTN, 1L<<17, ft_exit, &game);
	mlx_loop_hook(mlx->ptr, ft_main_loop, &game);
	mlx_loop(mlx->ptr);

	return (1);
}