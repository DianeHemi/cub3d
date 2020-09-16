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

void	ft_free_tab(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_tex(t_config *config)
{
	free(config->north_tex);
	free(config->south_tex);
	free(config->east_tex);
	free(config->west_tex);
	free(config->sprite_tex);
}

int		ft_exit(t_game *game)
{
	int i;

	i = 0;
	ft_free_tab(game->config->map);
	if (game->mlx->ptr && game->mlx->img)
	{
		mlx_destroy_image(game->mlx->ptr, game->mlx->img);
		game->mlx->img = NULL;
		while (i < 5)
		{
			mlx_destroy_image(game->mlx->ptr, game->tex[i].ptr);
			i++;
		}
	}
	free(game->sprite->s_pos);
	free(game->ray->zbuffer);
	if (game->mlx->ptr && game->mlx->win)
	{
		mlx_clear_window(game->mlx->ptr, game->mlx->win);
		mlx_destroy_window(game->mlx->ptr, game->mlx->win);
	}
	free(game->mlx->ptr);
	exit(EXIT_SUCCESS);
	return (1);
}
