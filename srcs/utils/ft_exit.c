/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:40:49 by dchampda          #+#    #+#             */
/*   Updated: 2020/08/31 14:40:52 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int 	ft_exit(t_game *game)
{
	ft_free_tab(game->config->map);

	mlx_destroy_image(game->mlx->ptr, game->mlx->img);
	game->mlx->img = NULL;
	mlx_destroy_image(game->mlx->ptr, game->tex[0].ptr);
	mlx_destroy_image(game->mlx->ptr, game->tex[1].ptr);
	mlx_destroy_image(game->mlx->ptr, game->tex[2].ptr);
	mlx_destroy_image(game->mlx->ptr, game->tex[3].ptr);
	mlx_destroy_image(game->mlx->ptr, game->tex[4].ptr);

	mlx_clear_window(game->mlx->ptr, game->mlx->win);
	mlx_destroy_window(game->mlx->ptr, game->mlx->win);

	free(game->mlx->ptr);
	game->mlx->ptr = NULL;


	free(game->sprite);
	free(game->ray->zbuffer);



	exit(EXIT_SUCCESS);
	return (1);
}