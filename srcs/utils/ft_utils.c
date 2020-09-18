/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 13:50:38 by dchampda          #+#    #+#             */
/*   Updated: 2020/07/02 13:50:41 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int y, int x, int color)
{
	char	*dst;

	dst = mlx->img_ptr + (y * mlx->size_line + x * mlx->bpp);
	*(unsigned int *)dst = color;
}

int		ft_errors(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (0);
}

int		ft_store_struct(t_config *data, t_ray *ray, t_mlx *mlx, t_game *game)
{
	game->mlx = mlx;
	game->config = data;
	game->ray = ray;
	if (!(game->ray->zbuffer = malloc(sizeof(double) * game->config->width)))
		return (ft_errors("Error\nMemory allocation failed.\n"));
	return (1);
}
