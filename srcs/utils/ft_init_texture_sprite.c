/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_texture_sprite.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:26:26 by diane             #+#    #+#             */
/*   Updated: 2020/07/28 17:57:21 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int 	ft_init_textures_data(t_texture *tex)
{
	int i;

	i = 0;
	while (i < 5)
	{
		tex[i].img = mlx_get_data_addr(tex[i].ptr, &tex[i].bpp, 
			&tex[i].size_line, &tex[i].endian);
		if (tex[i].img == NULL)
			return (0);
		i++;
	}
	return (1);
}

int 		ft_init_textures(t_config *data, t_game *game,
				t_texture *tex, t_mlx *mlx)
{
	if ((tex[0].ptr = mlx_xpm_file_to_image(mlx->ptr, data->north_tex, 
		&tex[0].width, &tex[0].height)) == NULL)
		return (0);
	if ((tex[1].ptr = mlx_xpm_file_to_image(mlx->ptr, data->south_tex, 
		&tex[1].width, &tex[1].height)) == NULL)
		return (0);
	if ((tex[2].ptr = mlx_xpm_file_to_image(mlx->ptr, data->east_tex, 
		&tex[2].width, &tex[2].height)) == NULL)
		return (0);
	if ((tex[3].ptr = mlx_xpm_file_to_image(mlx->ptr, data->west_tex, 
		&tex[3].width, &tex[3].height)) == NULL)
		return (0);
	if ((tex[4].ptr = mlx_xpm_file_to_image(mlx->ptr, data->sprite_tex, 
		&tex[4].width, &tex[4].height)) == NULL)
		return (0);
	if (!ft_init_textures_data(tex))
		return (0);
	game->tex = tex;
	ft_free_tex(data);
	return (1);
}

int 		ft_get_nb_sprite(t_config *data)
{
	int nb_sprite;
	int x;
	int y;

	nb_sprite = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '2')
				nb_sprite++;
			x++;
		}
		y++;
	}
	return (nb_sprite);
}

void	ft_get_pos_sprite(t_sprite_data *sprite, t_config *data)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '2')
			{
				sprite->pos[i].x = (double)x + 0.5;
				sprite->pos[i].y = (double)y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
	
}
