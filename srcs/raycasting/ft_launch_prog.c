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

int	ft_init_image(t_config *config, t_mlx *mlx)
{
	if (!(mlx->img = mlx_new_image(mlx->ptr, config->width, config->height)))
		return (0);
	mlx->img_ptr = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->size_line, &mlx->endian);
	if (mlx->img_ptr == NULL)
		return (0);
	mlx->bpp = mlx->bpp / 8;
	return (1);
}

int	ft_adjust_resolution(t_mlx *mlx, t_config *config)
{
	int width;
	int height;

	mlx_get_screen_size(mlx->ptr, &width, &height);
	if (width <= 0 || height <= 0)
		return (0);
	else
	{
		config->width = config->width > width ? width : config->width;
		config->height = config->height > height ? height : config->height;
		return (1);
	}
}

int	ft_launch_img(t_mlx *mlx, t_config *config)
{
	if (!ft_adjust_resolution(mlx, config))
		return (ft_errors("Error\nResizing the window failed.\n"));
	if (!(mlx->win = mlx_new_window(mlx->ptr, config->width,
			config->height, "Cub3D")))
		return (ft_errors("Error\nWindow couldn't be initialised.\n"));
	return (1);
}

int	ft_main_loop(t_game *game)
{
	ft_raycasting(game);
	ft_sprite_management(game, game->sprite, game->config);
	ft_move_player(game->move, game->ray, game->config);
	mlx_put_image_to_window(game->mlx->ptr, game->mlx->win,
			game->mlx->img, 0, 0);
	mlx_do_sync(game->mlx->ptr);
	return (1);
}

int	ft_launch_prog(t_config *config, t_mlx *mlx, int save_opt)
{
	t_game		game;
	t_ray		ray;
	t_texture	tex[5];
	t_sprite	sprite;
	t_move		move;

	if (!(sprite.s_pos = malloc(sizeof(t_s_pos) * config->nb_sprite)))
		return (ft_errors("Error\nMemory allocation failed.\n"));
	ft_get_pos_sprite(&sprite, config);
	game.sprite = &sprite;
	if (!(ft_init_textures(config, &game, tex, mlx))
		|| !ft_store_struct(config, &ray, mlx, &game))
		return (ft_errors("Error\nStructure initialisation failed.\n"));
	ft_init_move(&move, &game);
	ft_init_player_pos(game.config, game.ray);
	if (save_opt == 1)
		ft_save(&game);
	if (!ft_launch_img(mlx, game.config))
		return (ft_errors("Error\nMLX initialisation failed.\n"));
	mlx_hook(mlx->win, 2, 1L << 0, ft_keypress, &game);
	mlx_hook(mlx->win, 3, 1L << 1, ft_keyrelease, &game);
	mlx_hook(mlx->win, EXIT_BTN, 1L << 17, ft_exit, &game);
	mlx_loop_hook(mlx->ptr, ft_main_loop, &game);
	mlx_loop(mlx->ptr);
	return (1);
}
