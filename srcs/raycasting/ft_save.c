/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:43:50 by dchampda          #+#    #+#             */
/*   Updated: 2020/07/31 10:43:53 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_struct_save(t_save *save, t_config *config)
{
	save->file_size = 54 + 4 * config->width * config->height;
	save->reserved = 0;
	save->offset = 54; //Taille du header, on commence après
	save->header_size = 40;
	save->planes = 1;
	save->bpixels = 32;
	save->fd = open("bmp/save.bmp", O_RDWR | O_CREAT, S_IRWXU | O_TRUNC);
	if (save->fd < 0)
		ft_errors("Error : Can't create bmp file.\n");
}



void	ft_write_bmp_header(t_save *s, t_config *c)
{
	write(s->fd, "BM", 2);
	write(s->fd, &s->file_size, sizeof(int));
	write(s->fd, &s->reserved, sizeof(int));
	write(s->fd, &s->offset, sizeof(int));
	write(s->fd, &s->header_size, sizeof(int));
	write(s->fd, &c->width, sizeof(int));
	write(s->fd, &c->height, sizeof(int));
	write(s->fd, &s->planes, sizeof(short int));
	write(s->fd, &s->bpixels, sizeof(short int));
	write(s->fd, &s->reserved, sizeof(int));
	write(s->fd, &s->reserved, sizeof(int));
	write(s->fd, &s->reserved, sizeof(int));
	write(s->fd, &s->reserved, sizeof(int));
	write(s->fd, &s->reserved, sizeof(int));
	write(s->fd, &s->reserved, sizeof(int));
}




void	ft_write_bmp_tex(t_save *s, t_config *config, t_mlx *mlx)
{
	int x;
	int y;
	int len;

	y = 0;
	while (y < config->height)
	{
		x = 0;
		len = config->width * (config->height - y);
		while (x < config->width)
		{
			write(s->fd, &mlx->img_ptr[len * 4], 4);
			len++;
			x++;
		}
		y++;
	}
}




void	ft_save(t_game *game)
{
	t_save save;


	ft_main_loop(game);


	ft_init_struct_save(&save, game->config);
	ft_write_bmp_header(&save, game->config);
	ft_write_bmp_tex(&save, game->config, game->mlx);


	ft_exit(game);
}