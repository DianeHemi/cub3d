/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 15:38:21 by diane             #+#    #+#             */
/*   Updated: 2020/07/28 17:57:08 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_init_store(t_config *data, t_ray *ray, t_mlx *mlx, t_game *game)
{
	game->mlx = mlx;
	game->config = data;
	game->ray = ray;

	if(!(game->ray->zbuffer = malloc(sizeof(double) * game->config->width)))
		return (ft_errors("Memory allocation failed.\n"));

	return (1);
}
