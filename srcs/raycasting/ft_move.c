/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 16:05:19 by diane             #+#    #+#             */
/*   Updated: 2020/07/28 17:56:05 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_keypress(int keycode, t_game *game)
{
	if (keycode == FORWD)
		game->move->forwd = 1;
	else if (keycode == BACKWD)
		game->move->backwd = 1;
	else if (keycode == LEFT)
		game->move->left = 1;
	else if (keycode == RIGHT)
		game->move->right = 1;
	else if (keycode == TURN_L)
		game->move->turn_l = 1;
	else if (keycode == TURN_R)
		game->move->turn_r = 1;
	return (0);
}

int		ft_keyrelease(int keycode, t_game *game)
{
	if (keycode == ESC)
		ft_exit(game);
	if (keycode == FORWD)
		game->move->forwd = 0;
	else if (keycode == BACKWD)
		game->move->backwd = 0;
	else if (keycode == LEFT)
		game->move->left = 0;
	else if (keycode == RIGHT)
		game->move->right = 0;
	else if (keycode == TURN_L)
		game->move->turn_l = 0;
	else if (keycode == TURN_R)
		game->move->turn_r = 0;
	return (0);
}

void	ft_move_rotte(t_move *mv, t_ray *r)
{
	double old_dir_x;
	double old_plane_x;

	if (mv->turn_r == 1)
	{
		old_dir_x = r->dir.x;
		r->dir.x = r->dir.x * cos(-mv->rot_spd) - r->dir.y * sin(-mv->rot_spd);
		r->dir.y = old_dir_x * sin(-mv->rot_spd) + r->dir.y * cos(-mv->rot_spd);
		old_plane_x = r->plane_x;
		r->plane_x = r->plane_x * cos(-mv->rot_spd) - r->plane_y
			* sin(-mv->rot_spd);
		r->plane_y = old_plane_x * sin(-mv->rot_spd) + r->plane_y
			* cos(-mv->rot_spd);
	}
	if (mv->turn_l == 1)
	{
		old_dir_x = r->dir.x;
		r->dir.x = r->dir.x * cos(mv->rot_spd) - r->dir.y * sin(mv->rot_spd);
		r->dir.y = old_dir_x * sin(mv->rot_spd) + r->dir.y * cos(mv->rot_spd);
		old_plane_x = r->plane_x;
		r->plane_x = r->plane_x * cos(mv->rot_spd) - r->plane_y
			* sin(mv->rot_spd);
		r->plane_y = old_plane_x * sin(mv->rot_spd) + r->plane_y
			* cos(mv->rot_spd);
	}
}

void	ft_move_sideway(t_move *move, t_ray *ray, t_config *config)
{
	if (move->right == 1)
	{
		if (config->map[(int)(ray->pos.y)][(int)(ray->pos.x
				+ ray->plane_x * move->mv_spd)] != '1')
			ray->pos.x += ray->plane_x * move->mv_spd;
		if (config->map[(int)(ray->pos.y + ray->plane_y
				* move->mv_spd)][(int)(ray->pos.x)] != '1')
			ray->pos.y += ray->plane_y * move->mv_spd;
	}
	if (move->left == 1)
	{
		if (config->map[(int)(ray->pos.y)][(int)(ray->pos.x
				- ray->plane_x * move->mv_spd)] != '1')
			ray->pos.x -= ray->plane_x * move->mv_spd;
		if (config->map[(int)(ray->pos.y - ray->plane_y
				* move->mv_spd)][(int)(ray->pos.x)] != '1')
			ray->pos.y -= ray->plane_y * move->mv_spd;
	}
}

void	ft_move_player(t_move *move, t_ray *ray, t_config *config)
{
	if (move->forwd == 1)
	{
		if (config->map[(int)(ray->pos.y)][(int)(ray->pos.x
				+ ray->dir.x * move->mv_spd)] != '1')
			ray->pos.x += ray->dir.x * move->mv_spd;
		if (config->map[(int)(ray->pos.y + ray->dir.y
				* move->mv_spd)][(int)(ray->pos.x)] != '1')
			ray->pos.y += ray->dir.y * move->mv_spd;
	}
	if (move->backwd == 1)
	{
		if (config->map[(int)(ray->pos.y)][(int)(ray->pos.x
				- ray->dir.x * move->mv_spd)] != '1')
			ray->pos.x -= ray->dir.x * move->mv_spd;
		if (config->map[(int)(ray->pos.y - ray->dir.y
				* move->mv_spd)][(int)(ray->pos.x)] != '1')
			ray->pos.y -= ray->dir.y * move->mv_spd;
	}
	ft_move_sideway(move, ray, config);
	ft_move_rotte(move, ray);
}
