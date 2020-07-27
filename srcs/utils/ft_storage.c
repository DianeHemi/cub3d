/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 15:38:21 by diane             #+#    #+#             */
/*   Updated: 2020/07/17 15:38:22 by diane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_move(t_move *move)
{
	move->forwd = 0;
	move->backwd = 0;
	move->left = 0;
	move->right = 0;
}

void	ft_init_store(t_config *data, t_ray *ray, t_mlx *mlx, t_game *game)
{
	t_move		move;

	game->mlx = mlx;
	game->config = data;
	game->ray = ray;
	ft_init_move(&move);
	game->move = &move;
	//game->draw = malloc(sizeof(t_draw));
}
